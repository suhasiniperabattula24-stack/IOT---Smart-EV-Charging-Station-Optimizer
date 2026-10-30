#include <Arduino.h>
#include <WiFi.h>
#include "State.h"
#include "config.h"
#include "peripherals.h"
#include "Network.h"
#include "telemetry.h"
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
#include "rpc.h"
#include "attributes.h"


void setup() 
{
    //listen to incoming request
    
    // intialize serial monitor
    Serial.begin(115200);
    
    // initialize sensor
    dht.begin(); 
    // configure esp32 with real time
    configTime(0,0,"pool.ntp.org", "time.nist.gov");
    //config peripheral pins
    pinMode(BTN_PLUGIN, INPUT_PULLUP);
    pinMode(BTN_PLUGOUT, INPUT_PULLUP);
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_YELLOW, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    
    //connect board to wifi
    connectWiFi();
     

    //config mqtt server
    mqtt.setServer(MQTT_SERVER, MQTT_PORT); //mqtt server addr of things and port number
    //set call back function upon receiving data from the cloud
    mqtt.setCallback(mqttCallback);
    mqtt.subscribe("v1/devices/me/rpc/request/+");
    mqtt.setBufferSize(512); 



    //conect board to the cloud
    connectMQTT(); // TOKEN , device id

}
    
unsigned long now;
unsigned long last_print;

void loop() 
{
    if (!mqtt.connected()) {
        reconnect();
    }
    mqtt.loop(); 
    // push data every 5 sec
    now = millis();
    if ((now - last_print) > 5000) 
    {
        last_print = now;
        // read data from sensor  // voltage , current, temperature, power, bay status
        sample_sensor();
        //publish the data
        publishTelemetry();
        //run Ai to get the prediction
        runEdgeAIInference();
        // decide load based on the predictions
        if(manualOverrideActive == 0)
        {
            runOptimization();

        }
         
    }
    plug_status();
    updateLeds();
}


#include <WiFi.h>
#include <ArduinoJson.h>
#include "Network.h"
#include "Config.h"
#include "attributes.h"
#include "rpc.h"

WiFiClient espClient;
PubSubClient mqtt(espClient);
const char* TOKEN = "your_device_access_token";   


//---------------------------------------------------------------------
void connectWiFi()
{
  Serial.print("Connecting to WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 15000) {
    delay(300);
    Serial.print(".");
  }
  Serial.println(WiFi.status() == WL_CONNECTED ? " connected." : " FAILED (will retry).");
}

void connectMQTT() {
  if (WiFi.status() != WL_CONNECTED) return;
    Serial.println("Connecting to Thingsboard MQTT...");
    if (mqtt.connect(BAY_ID, TB_TOKEN, NULL)) {
      Serial.println(" connected."); //push updates
      mqtt.subscribe("v1/devices/me/attributes"); //reply to our reuest
      mqtt.subscribe("v1/devices/me/attributes/response/+");  //RPC commands
      mqtt.subscribe("v1/devices/me/rpc/request/+");
      Serial.println("RPC subscription: SUCCESS");
      requestSharedAttributes(); //requesting attribute status from the cloud 
    } else {
      Serial.print("Failed, rc=");
      Serial.print(mqtt.state());
      delay(1000);
    }
   
  }

 

   void reconnect() {
    while (!mqtt.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (mqtt.connect("ESP32Client", TOKEN, "")) {
            Serial.println("connected");
            mqtt.subscribe("v1/devices/me/rpc/request/+");
            mqtt.subscribe("v1/devices/me/attributes");
        } else {
            Serial.print("failed, rc=");
            Serial.print(mqtt.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

  void mqttCallback(char* topic, byte* payload, unsigned int length) {
    String topicStr = String(topic);
    char buf[400];
    unsigned int n = length < sizeof(buf) - 1 ? length : sizeof(buf) - 1;
    memcpy(buf, payload, n);
    buf[n] = '\0';

    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, buf);
    if (error) return;

    // Relay RPC handler
    if (topicStr.startsWith("v1/devices/me/rpc/request/")) {
    const char* method = doc["method"];
    Serial.print(">> RPC ");
    Serial.println(method);

    if (strcmp(method, "setRelayState") == 0) {
        bool state = doc["params"]["state"];
        digitalWrite(RELAY_PIN, state ? HIGH : LOW);

        Serial.print("Relay set to: ");
        Serial.println(state ? "ON" : "OFF");
        Serial.print(">> RPC setRelayState(");
        Serial.print(state ? 1 : 0);
        Serial.println(") - manual override engaged.");
    }
}

    

    // Shared attributes handler
    JsonObject attrs;
    if (doc["shared"].is<JsonObject>()) {
        attrs = doc["shared"].as<JsonObject>();
    } else {
        attrs = doc.as<JsonObject>();
    }
    applySharedAttributes(attrs);


    

   


    
}


  
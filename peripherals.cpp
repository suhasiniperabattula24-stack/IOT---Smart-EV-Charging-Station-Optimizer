#include <Arduino.h>
#include <DHT.h>
#include "State.h"
#include "Peripherals.h"
#include "Config.h"


DHT dht(DHT_PIN, DHT_TYPE);

float mapFloat(long x, long inMin, long inMax, long outMin, long outMax) {
  return (float)(x - inMin) * (outMax - outMin) / (float)(inMax - inMin) + outMin;
}

void sample_sensor(void) 
{
    int raw_current = analogRead(CURRENT_PIN); // 0 to 4095  // 0 to 32A 
    int raw_voltage = analogRead(VOLTAGE_PIN); // 0 to 4095 // 0 to 250v 
   
    //map votage 0 to 250v
    voltage = mapFloat(raw_voltage, 0, 4095, 0, 250); //to read voltage
    
    if(bayStatus == "CHARGING")
    {
    // map current 0 to 32A
    current = mapFloat(raw_current, 0, 4095, 0, 32); //to read current
    }
    else
    {
      current = 0;
    }
  

    // read current and 5 values array 

    // calculate  power
    power = voltage * current; 
    
    //to read temperature
    float t = dht.readTemperature(DHT_PIN);
    if (!(isnan(t))) temperature = t;
     
    
}

float recentAvgCurrent(void)
 {
  float sum = 0;
  // read recent file current values
  for(int i = 0; i < 5; i++) 
  {
    sum = sum + current;

  }

  return sum/5;

 }
bool plugin_flag_once = 1;
bool plugout_flag_once = 1;

void plug_status(void) {
   bool pluginReading = digitalRead(BTN_PLUGIN);
   // detect the sw is pressed
    if ( pluginReading == LOW && plugin_flag_once )
     {
        //session time
        sessionStartMs = millis();
      // plug in switch is pressed
      plugin_flag_once = 0;
      // change bay_status FREE to charging
      if(bayStatus == "FREE") 
      {
        bayStatus = "CHARGING";
        Serial.println("Bay1 plugin detected, Bay is charging");
        //turn on the relay
        digitalWrite(RELAY_PIN, HIGH);
      }
      //update leds
     }
     
     if( pluginReading == HIGH)
    {
     plugin_flag_once = 1;
    }
    //plug out switch is pressed
    bool plugoutReading = digitalRead(BTN_PLUGOUT);
    // detect sw is pressed
    if( plugoutReading == LOW && plugout_flag_once )
    {
      // plug in switch is pressed
      plugin_flag_once = 0;
     // change bay_status charging to FREE
      if(bayStatus == "CHARGING")
      {
        bayStatus = "FREE";
        Serial.println("Bay1 plugout detected, Bay is FREE");
        // turn off the relay
        digitalWrite(RELAY_PIN, LOW);
      }
      //ipdate leds
   }
   if ( plugoutReading == HIGH)
   {
     plugout_flag_once = 1;
   
   } 
}
   /* void update_led_status(void) 
    { 
    // if bay_status FREE turn ON green led
    if (bayStatus == "FREE") 
    {
        
        digitalWrite(LED_GREEN, HIGH);
        digitalWrite(LED_YELLOW, LOW);
    } 
    else 
    {
        
    // if bay_status CHARGING turn ON yellow led
        digitalWrite(LED_YELLOW, HIGH);
        digitalWrite(LED_GREEN, LOW);
    }
 } */



      
    
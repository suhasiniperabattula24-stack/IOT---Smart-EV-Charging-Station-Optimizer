#include <ArduinoJson.h>
#include "Telemetry.h"
#include "network.h"
#include "state.h"
#include "config.h"

void publishTelemetry()
{
  // check if the device is connected to cloud or not, if not return
  if (!mqtt.connected()) return;

  //store the value as key value pair format
  JsonDocument doc;
  doc["bayId"] = BAY_ID;
  doc["voltage"] = round(voltage * 10) / 10.0;
  doc["current"] = round(current * 10) / 10.0;
  doc["power"] = round(power * 10) / 10.0;
  doc["temperature"] = round(temperature * 10) / 10.0;
  doc["bayStatus"] = bayStatus;
  // adding two more values to the buffer
  doc["predictedArrivalProb"] = round(predictedArrivalProb * 100) / 100.0;
  doc["predictedDurationMin"] = predictedDurationMin;
  //add lpad decision, throttle level, over load
  doc["throttleLevel"] = throttleLevel;
  doc["loadDecision"] = loadDecision;
  doc["overloadActive"] = overloadActive;
  
  char buffer[350];
  serializeJson(doc, buffer);


  //push the data to the cloud, topic, data -> buffer
  mqtt.publish("v1/devices/me/telemetry", buffer);
  Serial.print("[MQTT >>] ");
  Serial.println(buffer);
}
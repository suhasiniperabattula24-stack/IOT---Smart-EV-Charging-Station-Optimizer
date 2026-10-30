#ifndef NETWORK_H
#define NETWORK_H

#include <WiFiClient.h>
#include <PubSubClient.h>

extern WiFiClient espClient;
extern PubSubClient mqtt;
extern const char* TOKEN ;

void connectWiFi();
void connectMQTT();
void reconnect();


void mqttCallback(char* topic, byte* payload, unsigned int length);




#endif
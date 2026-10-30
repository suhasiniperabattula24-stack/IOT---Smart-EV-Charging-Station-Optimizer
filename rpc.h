#ifndef RPC_H
#define RPC_H

#include <ArduinoJson.h>

// Function declaration for handling RPC commands
void handleRpc(String requestId, char* payload);

#endif

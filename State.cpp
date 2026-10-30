#include "State.h"

// Global variable definitions
String bayStatus = "FREE";   // initial state
float voltage = 0;
float current = 0;
float power = 0;
float temperature = 0;

unsigned long sessionStartMs = 0;

//edge  Ai variables
float predictedArrivalProb = 0.0;
int predictedDurationMin = 0;

int lastHourOfDay = 12; 

String loadDecision = "ALLOW";
int throttleLevel = 100;

float predictionThreshold = 0.5; // 0 to 1
int peakTariffStartHr = 18;
int peakTariffEndHr = 21;
bool overloadActive = false;
int overloadCurrentA = 16; 
int maxStationLoadW = 3000;
bool manualOverrideActive = 0;




#ifndef StATE_H
#define StATE_H

#include <Arduino.h>

extern String bayStatus;
extern float voltage, current, power, temperature;

extern unsigned long sessionStartMs;

extern float predictedArrivalProb;
extern int predictedDurationMin;
extern int lastHourOfDay;

extern String loadDecision ;
extern int throttleLevel ;

extern float predictionThreshold ; //0 to 1
extern int peakTariffStartHr ;
extern int peakTariffEndHr ;
extern bool overloadActive ;

extern int overloadCurrentA ;
extern int maxStationLoadW ; 

extern bool manualOverrideActive ;


#endif
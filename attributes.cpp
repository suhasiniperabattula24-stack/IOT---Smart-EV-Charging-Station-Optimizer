#include "attributes.h"
#include "Network.h"
#include "State.h"

void requestSharedAttributes() {
    JsonDocument doc;   // StaticJsonDocument deprecated warning avoid చేయాలంటే
    doc["sharedKeys"] = "maxStationLoadW,overloadCurrentA,peakTariffStartHr,peakTariffEndHr,predictionThreshold";
    char buffer[128];
    serializeJson(doc, buffer);
    mqtt.publish("v1/devices/me/attributes/request/1", buffer);
}

void applySharedAttributes(JsonObject& attrs) {
    if (attrs["maxStationLoadW"].is<int>()) {
        maxStationLoadW = attrs["maxStationLoadW"];
    }
    if (attrs["overloadCurrentA"].is<int>()) {
        overloadCurrentA = attrs["overloadCurrentA"];
    }
    if (attrs["peakTariffStartHr"].is<int>()) {
        peakTariffStartHr = attrs["peakTariffStartHr"];
    }
    if (attrs["peakTariffEndHr"].is<int>()) {
        peakTariffEndHr = attrs["peakTariffEndHr"];
    }
    if (attrs["predictionThreshold"].is<float>()) {
        predictionThreshold = attrs["predictionThreshold"];
    }

    Serial.print("[Attributes updated] maxStationLoadW: "); Serial.print(maxStationLoadW);
    Serial.print(", overloadCurrentA: "); Serial.print(overloadCurrentA);
    Serial.print(", peakTariffHr: "); Serial.print(peakTariffStartHr); Serial.print("-"); Serial.print(peakTariffEndHr);
    Serial.print(", predictionThreshold: "); Serial.print(predictionThreshold);
}

    
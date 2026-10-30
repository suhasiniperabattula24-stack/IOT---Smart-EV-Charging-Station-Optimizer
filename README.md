# ⚡ Edge AI Based Smart EV Charging Station Optimizer

An IoT-based EV charging station monitoring and load management system using ESP32, MQTT, Wokwi, and ThingsBoard.

## 📌 Overview

The **Edge AI Based Smart EV Charging Station Optimizer** is designed to monitor EV charging parameters and detect overload conditions. The ESP32 collects and processes charging data, while MQTT transmits the data to ThingsBoard for real-time visualization and centralized monitoring of multiple charging bays.

## 🎯 Objectives

- Monitor voltage, current, power, temperature, and charging status.
- Detect abnormal and overload conditions.
- Process charging data locally using ESP32.
- Support intelligent charging load management.
- Monitor multiple charging bays through a centralized dashboard.

## 🛠️ Technologies Used

- **ESP32** – Controller and edge processing
- **C/C++** – Embedded programming
- **Wokwi** – Hardware simulation
- **MQTT** – IoT communication
- **ThingsBoard** – Dashboard and alarm monitoring
- **DHT22** – Temperature monitoring
- **PlatformIO** – Development environment

## ⚙️ Key Features

- Real-time EV charging parameter monitoring
- Multi-bay charging status monitoring
- ESP32-based edge processing
- Overload detection and load-control decisions
- MQTT-based telemetry transmission
- Centralized ThingsBoard dashboard and alarms

## 🏗️ System Architecture

Sensors and Inputs → ESP32 Controller → Edge Data Processing → Overload Detection and Load Decision → MQTT Communication → ThingsBoard Dashboard and Alarms

## 🔄 Working Flow

1. Sensors provide charging parameter data.
2. ESP32 reads and processes the data.
3. The system checks for abnormal and overload conditions.
4. Load-control decisions are generated when required.
5. MQTT transmits telemetry to ThingsBoard.
6. The dashboard displays charging parameters and bay status.
7. Alarms help identify critical conditions.

## 🧪 Simulation and Monitoring

The system is simulated using **Wokwi** and integrated with **ThingsBoard** for cloud-based monitoring.

The dashboard displays:

- Voltage
- Current
- Power
- Temperature
- Charging status
- Charging bay status
- Alarms for abnormal conditions

## 📊 Results

The project demonstrates:

- Real-time charging parameter monitoring
- ESP32-based data processing
- MQTT-based telemetry transmission
- ThingsBoard dashboard integration
- Centralized multi-bay monitoring
- Overload condition detection

## 🚀 Live Dashboard

Monitor the EV charging station parameters through the ThingsBoard dashboard.

**ThingsBoard Dashboard:** [View Live Dashboard](https://thingsboard.cloud/dashboards/all/8da139d0-b299-11f1-973e-db7ef6e48014)


## 🚀 Future Scope

- Advanced Edge AI prediction models
- Dynamic load balancing between charging bays
- Battery State of Charge (SOC) monitoring
- Predictive maintenance
- Mobile application integration
- Integration with real EV charging hardware

## 📚 Project Domain

Embedded Systems | IoT | Edge AI | Electric Vehicles | Smart Energy Management

## 👩‍💻 Conclusion

The **Edge AI Based Smart EV Charging Station Optimizer** combines embedded systems, IoT communication, edge processing, and cloud monitoring to support smart EV charging station management. It demonstrates real-time monitoring, centralized visualization, and overload detection using ESP32, MQTT, Wokwi, and ThingsBoard.

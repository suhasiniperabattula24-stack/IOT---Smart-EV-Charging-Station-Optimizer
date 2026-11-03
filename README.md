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

## Circuit Connection

<img width="781" height="395" alt="image (4)" src="https://github.com/user-attachments/assets/b986df08-f67a-4f79-a54b-3ae298d59543" />

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

### Bay 1 Monitoring Dashboard

<img width="1582" height="693" alt="image (5)" src="https://github.com/user-attachments/assets/8c91f0fc-0302-480e-b675-9d445f3dd247" />

<img width="1568" height="903" alt="image (6)" src="https://github.com/user-attachments/assets/898f6d1c-a49f-4db5-b7a2-f6624fd86c01" />

### Bay 2 Monitoring Dashboard

<img width="1917" height="916" alt="image" src="https://github.com/user-attachments/assets/b3668c85-9138-4dba-aebf-940498540d69" />

### Bay 3 Monitoring Dashboard

<img width="1852" height="918" alt="image" src="https://github.com/user-attachments/assets/e389b58d-f852-4d1b-b3ce-4cc12082992a" />

### Alarm Monitoring

<img width="1791" height="922" alt="image" src="https://github.com/user-attachments/assets/57af094f-9090-4d8a-acf4-b03339c3bd18" />

### 🚀 Live Dashboard

<img width="1582" height="693" alt="image (5)" src="https://github.com/user-attachments/assets/e5500a5b-0864-4579-8b51-c068e938d59a" />

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

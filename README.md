# 🚗 Smart Parking System using Arduino

A simple **Smart Parking System** that uses **IR sensors**, **LCD**, and a **servo motor** to display available parking slots and control the entry gate.

## 🧰 Components
- Arduino UNO  
- 2 IR Sensors (entry & exit)  
- Servo Motor (for gate control)  
- 16x2 LCD (I2C)  

## ⚙️ Features
- Automatically detects cars entering/exiting using IR sensors  
- Updates number of available parking slots on LCD  
- Opens and closes gate automatically  
- Can be extended with IoT (ESP32 + Blynk or MQTT)

## 🧠 How It Works
1. When a car is detected at the entry sensor:
   - The servo opens the gate
   - Car count increases
2. When a car exits:
   - The servo opens again
   - Car count decreases
3. LCD displays remaining available slots.


# 🌍 Arduino Environmental Alert System

This project uses an Arduino to monitor environmental conditions like **temperature** and **light**. It alerts you when:
- **Light levels drop too low** (simulating darkness or obstruction)
- **Temperature rises too high** (e.g. overheating)

## 🧰 Components Used

| Component       | Quantity | Description                        |
|----------------|----------|------------------------------------|
| Arduino Uno     | 1        | Main microcontroller               |
| NTC Thermistor  | 1        | 10kΩ @ 25°C temperature sensor     |
| LDR (Photoresistor) | 1    | Light intensity sensor             |
| 10kΩ Resistor   | 2        | Pull-down resistors for sensors    |
| LEDs            | 2        | Indicate normal vs alert states    |
| Buzzer          | 1        | Alarm signal                       |
| Breadboard + jumper wires | N/A | For wiring                     |



### Connections:
- **NTC Thermistor:** One leg to **A1**, other to **GND**, 10k pull-up to **5V**
- **LDR:** One leg to **A0**, other to **5V**, 10k pull-down to **GND**
- **Buzzer:** Digital pin **12**
- **LED for Temp Warning:** Digital pin **13**
- **LED for LDR Alert:** Digital pin **11**
- **Normal Temp LED:** Digital pin **10**

---


## 🧠 Logic Overview

### 🌙 Light Detection (LDR)
- If ambient light drops below a certain analog threshold (`<= 400`), a buzzer and alert LED are activated.

### 🌡️ Temperature Detection (NTC Thermistor)
- The NTC thermistor reduces its resistance as temperature rises.
- Analog value is read and converted to voltage, then to temperature in °C.
- If temperature exceeds 42°C, a red LED and buzzer go off.


## 📟 Serial Output Sample

========= LDR ALARM ACTIVATED ========
Temperature: 39.5 °C
LDR ALARM DEACTIVATED
Temperature: 43.2 °C
🔥 Temperature TOO HIGH!


## 💾 How to Upload

1. Open `Environmental_Alert.ino` in the Arduino IDE.
2. Connect your Arduino via USB.
3. Select the correct board and port.
4. Upload and open Serial Monitor.

## 📝 License

Saganash licence

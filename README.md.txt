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

## 🧠 Logic Overview

- **LDR**: If light level is too low → buzzer + alert LED turn on.
- **NTC Thermistor**: If temperature > 42°C → buzzer + temp LED trigger.

## 📷 Real Components

![Thermistor and LDR](images/thermistor_photo.jpg)

## 📟 Serial Output Sample


## 💾 How to Upload

1. Open `Environmental_Alert.ino` in the Arduino IDE.
2. Connect your Arduino via USB.
3. Select the correct board and port.
4. Upload and open Serial Monitor.

## 📝 License

Saganash licence

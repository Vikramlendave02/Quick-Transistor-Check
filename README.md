# 🧪 Auto Transistor Detector

**Auto Transistor Detector** is a simple Arduino-based tool that automatically identifies whether a transistor is NPN, PNP, or faulty. It uses an Arduino board, an OLED display, and a basic testing circuit to provide real-time results on the screen.

---

## 🔧 Features

- ✅ Automatically detects NPN and PNP transistors  
- 🖥️ Displays results on a 128x64 OLED screen  
- 🔁 Continuously tests and updates every second  
- 🧰 Ideal for electronics hobbyists and beginners  
- 📏 Compact and easy-to-build setup  

---

## 🧱 Hardware Required

| Component                 | Quantity |
|---------------------------|----------|
| Arduino (Uno/Nano/etc)    | 1        |
| 128x64 OLED Display (I2C) | 1        |
| NPN/PNP Transistor        | 1 (for testing) |
| 1kΩ Resistor              | 1        |
| 10kΩ Resistor             | 1        |
| Breadboard + Jumper Wires | As needed |

---

## 🔌 Circuit Diagram

- `D5` → Transistor **Base** (through 1kΩ resistor)  
- `D6` → Transistor **Collector** (with 10kΩ pull-up to 3.3V or 5V)  
- Emitter → GND  

> Connect the OLED display via I2C:  
> `SCL` → A5 (on Uno) or corresponding SCL pin  
> `SDA` → A4 (on Uno) or corresponding SDA pin  
> `VCC` → 3.3V or 5V  
> `GND` → GND  

---

## 🧠 How It Works

1. The Arduino sends signals to the base of the transistor.  
2. It checks how the collector responds to HIGH/LOW signals.  
3. Based on behavior, it determines if the transistor is:  
   - **NPN**  
   - **PNP**  
   - Or **Faulty / Not Connected**  
4. Displays result and elapsed time on the OLED screen.

---

## 🚀 Getting Started

1. Clone or download this repository.  
2. Open the `.ino` file in the Arduino IDE.  
3. Connect the components as described.  
4. Upload the code to your Arduino board.  
5. Open the Serial Monitor (optional) and observe results on the OLED display.

---

## ⚠️ Note

> **This is not the final code; it will be modified and improved soon.**

---

## 📷 Preview

*Coming soon – project photos and circuit diagram!*

---

## 📜 License

This project is open-source under the [MIT License](LICENSE).

---

## 🙌 Credits

**Created by:** Vikram Lendave  
**Contact:** [vikramlendave80@gmail.com](mailto:vikramlendave80@gmail.com)  
**LinkedIn:** [https://www.linkedin.com/in/vikram-lendave-aa8231267/](https://www.linkedin.com/in/vikram-lendave-aa8231267/)

Built using:  
- [Adafruit SSD1306 library](https://github.com/adafruit/Adafruit_SSD1306)  
- [Adafruit GFX library](https://github.com/adafruit/Adafruit-GFX-Library)

---

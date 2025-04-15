// === Pin Definitions ===
const int ledPin1 = 13;       // Temperature Alert LED
const int buzzerPin = 12;     // Buzzer
const int ldrPin = A0;        // LDR sensor pin
const int tempPin = A1;       // Thermistor pin
const int ledPin2 = 11;       // LDR Alert LED
const int tempLed = 10;       // Normal Temperature LED

// === Thermistor Constants ===
const float seriesResistor = 10000.0;      // 10k resistor in series
const float nominalResistance = 10000.0;   // 10k at 25°C
const float nominalTemperature = 25.0;     // 25°C baseline
const float bCoefficient = 3950.0;         // B value
const float adcMax = 1023.0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(tempLed, OUTPUT);
}

void loop() {
  // === LDR Section ===
  int ldrValue = analogRead(ldrPin);
  if (ldrValue <= 400) {
    tone(buzzerPin, 100);
    digitalWrite(ledPin2, HIGH);
    Serial.println("========= LDR ALARM ACTIVATED ========");
  } else {
    noTone(buzzerPin);
    digitalWrite(ledPin2, LOW);
    Serial.println("LDR ALARM DEACTIVATED");
  }

  // === Thermistor Section ===
  int analogValue = analogRead(tempPin);
  float voltage = analogValue * (5.0 / adcMax);
  float resistance = seriesResistor * (adcMax / analogValue - 1.0);

  float steinhart;
  steinhart = resistance / nominalResistance;        // (R/Ro)
  steinhart = log(steinhart);                        // ln(R/Ro)
  steinhart /= bCoefficient;                         // 1/B * ln(R/Ro)
  steinhart += 1.0 / (nominalTemperature + 273.15);  // + (1/To)
  steinhart = 1.0 / steinhart;                       // Invert
  float temperatureC = steinhart - 273.15;           // Convert to °C

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  if (temperatureC >= 105.0) {
    digitalWrite(ledPin1, HIGH);   // High temp alert LED ON
    digitalWrite(tempLed, LOW);    // Normal temp LED OFF
    tone(buzzerPin, 150);           // Buzzer ON
    Serial.println("🔥 Temperature TOO HIGH!");
  } else {
    digitalWrite(tempLed, HIGH);   // Normal temp LED ON
    digitalWrite(ledPin1, LOW);    // Alert LED OFF
  }

  delay(500);
}

#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;
const int ledPin = 9;   // IR LED pin

// ---- Calibration constants (adjust after lab calibration) ----
float m = 0.05;   // slope (mg/dL per ADC count)
float c = 90.0;   // offset (baseline glucose level)

// ---- Moving Average Filter ----
const int windowSize = 10;
int32_t buffer[windowSize];
int bufferIndex = 0;
int32_t sum = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  if (!ads.begin()) {
    Serial.println("Failed to find ADS1115. Check wiring!");
    while (1);
  }

  ads.setGain(GAIN_ONE); // ±4.096V range
  Serial.println("Glucose Measurement Started...");
}

void loop() {
  // LED ON
  digitalWrite(ledPin, HIGH);
  delay(5);
  int16_t adcOn = ads.readADC_Differential_0_1();

  // LED OFF
  digitalWrite(ledPin, LOW);
  delay(5);
  int16_t adcOff = ads.readADC_Differential_0_1();

  // Compute clean signal
  int16_t adcDiff = adcOff - adcOn;   // keep positive
  float voltage = adcDiff * 0.000125;

  // ---- Moving Average ----
  sum -= buffer[bufferIndex];
  buffer[bufferIndex] = adcDiff;
  sum += buffer[bufferIndex];
  bufferIndex = (bufferIndex + 1) % windowSize;
  float smoothSignal = (float)sum / windowSize;

  // ---- Apply Calibration ----
  float glucose = m * smoothSignal + c;

  // ---- Print Results ----
  Serial.print("Raw Signal: ");
  Serial.print(adcDiff);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 6);
  Serial.print(" V | Glucose: ");
  Serial.print(glucose, 1);
  Serial.println(" mg/dL");

  delay(500);
}

# Non-Invasive-Neonatal-glucose-monitor-NIR
This project focuses on the development of a wearable, non-invasive device for monitoring neonatal glucose levels using Near-Infrared (NIR) spectroscopy. The system aims to reduce the need for frequent blood sampling in newborns by providing continuous, painless glucose estimation through optical sensing and signal processing.


## Proposed Solution

Neonatal hypoglycemia is a critical condition that requires continuous and safe monitoring. Conventional invasive methods such as blood pricking or enzymatic test strips are not suitable for neonates due to pain, risk of infection, and difficulty in frequent sampling. 

To address these limitations, this project proposes a wearable non-invasive glucose monitoring system based on Near-Infrared (NIR) spectroscopy, where variations in light absorption and reflection are converted into electrical signals that correlate with glucose concentration.

---

## Optical Source and Detection Setup

An NIR LED is used as the light source, emitting wavelengths sensitive to glucose absorption. The emitted light penetrates biological tissue, where part of it is absorbed and the remaining portion is reflected. A BPW34 photodiode captures the reflected light intensity.

---

## Analog Signal Conditioning

The photodiode generates a small photocurrent proportional to received light. This current is converted into voltage using a transimpedance amplifier based on the LM358 operational amplifier. Feedback components provide gain control and noise filtering, while decoupling capacitors stabilize the supply voltage.

---

## Data Acquisition

The conditioned analog signal is digitized using the ADS1115 16-bit ADC and transmitted to an Arduino microcontroller via I2C communication. To eliminate ambient light effects, differential sampling is used:

- Measurement with LED ON
- Measurement with LED OFF
- Difference calculation to remove noise

A moving average filter is applied in firmware to smooth the signal.

---

## Voltage–Glucose Calibration

The measured voltage is correlated with glucose concentration using a linear calibration model:

Glucose = m × ADC + b

where m and b are experimentally derived constants obtained using phantom tissue models and reference glucose solutions.

---

## Real-Time Monitoring

The processed glucose values are displayed in real time through the Arduino serial monitor and can be extended to a graphical interface for clinical monitoring applications.

---

## Results and Validation

The system was tested using tissue-mimicking phantom models and controlled optical setups. Calibration curves and time-series analysis confirmed a measurable relationship between optical signal intensity and glucose levels. Validation experiments were conducted on adult volunteers and phantom models only to ensure ethical compliance.

---

## Hardware Components

- NIR LED
- BPW34 Photodiode
- LM358 Operational Amplifier
- ADS1115 16-bit ADC
- Arduino Microcontroller

---

## Key Features
- Non-invasive glucose monitoring
- Wearable neonatal-friendly design
- Continuous real-time measurement
- Noise reduction using differential optical sampling

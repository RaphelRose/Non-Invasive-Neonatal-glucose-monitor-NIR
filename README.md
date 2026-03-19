# Non-Invasive-Neonatal-glucose-monitor-NIR
This project focuses on the development of a non-invasive prototype for monitoring neonatal glucose levels using Near-Infrared (NIR) spectroscopy. The system aims to reduce the need for frequent blood sampling in newborns by providing continuous, painless glucose estimation through optical sensing and signal processing.


## Proposed Solution

Neonatal hypoglycemia is a critical condition that requires continuous and safe monitoring. Conventional invasive methods such as blood pricking or enzymatic test strips are not suitable for neonates due to pain, risk of infection, and difficulty in frequent sampling. 

To address these limitations, this project proposes a prototype non-invasive glucose monitoring system based on Near-Infrared (NIR) spectroscopy, where variations in light absorption and reflection are converted into electrical signals that correlate with glucose concentration.


## Optical Source and Detection Setup

An NIR LED is used as the light source, emitting infrared light sensitive to glucose absorption. The emitted light penetrates biological tissue, where part of it is absorbed and the remaining portion is reflected. A BPW34 photodiode captures the reflected light intensity.


## Analog Signal Conditioning

The photodiode generates a small photocurrent proportional to received light. This current is converted into voltage using a transimpedance amplifier based on the LM358 operational amplifier. Feedback components provide gain control and noise filtering, while decoupling capacitors stabilize the supply voltage.


## Data Acquisition

The conditioned analog signal is digitized using the ADS1115 16-bit ADC and transmitted to an Arduino microcontroller via I2C communication. To eliminate ambient light effects, differential sampling is used:

- Measurement with LED ON
- Measurement with LED OFF
- Difference calculation to remove noise

A moving average filter is applied in firmware to smooth the signal.


## Voltage–Glucose Calibration

The measured voltage is correlated with glucose concentration using a linear calibration model:

Glucose = m × ADC + b

where m and b are experimentally derived constants obtained using phantom tissue models.


## Real-Time Monitoring

The processed glucose values are displayed in real time through the Arduino serial monitor.

## Results and Validation

The developed prototype was evaluated using controlled optical setups and experimental trials conducted on adult volunteers rather than neonates. Calibration curves and time-series signal analysis demonstrated a measurable relationship between optical signal intensity and glucose levels. This approach ensured safe preliminary validation of the system while avoiding direct testing on neonatal subjects during the initial development stage.

## Hardware Components

- NIR LED
- BPW34 Photodiode
- LM358 Operational Amplifier
- ADS1115 16-bit ADC
- Arduino Microcontroller



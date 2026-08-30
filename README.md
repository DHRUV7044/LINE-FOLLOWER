# Line Follower Robot - Team Abhimanyu

A high-performance autonomous line-following robotic platform featuring PID-controlled path tracking, multi-channel IR sensor integration, and precise motor driver control.

## Project Contributors
- **Bhavya Desai** (Team Lead): Integration, Testing, and Validation.
- **Dhruvkumar Shingala** (Hardware Designer): Schematic capture, power routing, sensor placement alignment, and chassis structural design.
- **Karan Prajapati** (Embedded Programmer): Microcontroller firmwares and H-bridge motor driver interface.
- **Harsh Patel & Rudra Prajapati** (Algorithm Developers): PID control modeling and state-machine path correction.
- **Vedant Thakkar**: System calibration and track testing.

## System Architecture & Features
- **Sensor Array**: 5-channel reflectance IR sensor array for real-time path detection and edge scanning.
- **Control Loop**: Closed-loop **Proportional-Integral-Derivative (PID) algorithm** for smooth navigation, micro-adjustments on straight paths, and fast recovery on sharp curves.
- **Motor Control**: TB6612FNG Dual H-Bridge motor driver providing high-efficiency pulse-width modulated (PWM) speed controls.
- **Power Delivery**: 3-cell 3.7V Li-ion battery supply with voltage regulation for logic and motor rails.
- **State Machine Recovery**: Fallback recovery search routines if the line is temporarily lost.

## Hardware Pin Connections (Arduino Uno)

| Component | Function | Arduino Pin |
|---|---|---|
| **Left Motor Enable** | PWM Speed Control | Pin 9 |
| **Left Motor IN1** | Direction Phase 1 | Pin 2 |
| **Left Motor IN2** | Direction Phase 2 | Pin 3 |
| **Right Motor Enable**| PWM Speed Control | Pin 10 |
| **Right Motor IN1** | Direction Phase 1 | Pin 4 |
| **Right Motor IN2** | Direction Phase 2 | Pin 5 |
| **IR Sensor 1** | Far Left Detector | Analog Pin A0 |
| **IR Sensor 2** | Inner Left Detector | Analog Pin A1 |
| **IR Sensor 3** | Center Detector | Analog Pin A2 |
| **IR Sensor 4** | Inner Right Detector| Analog Pin A3 |
| **IR Sensor 5** | Far Right Detector | Analog Pin A4 |

## Firmwares Catalog
- `FIRST_try_with_if_else.C`: Early-stage bang-bang threshold-based logic code.
- `SECOND_try_with_PID.c`: Refactored firmwares integrating the PID control equations.
- `experimental_code_pid.c`: Experimental branch optimizing the $K_p$, $K_i$, and $K_d$ gain coefficients and motor speeds.

## Simulation & Calibration
- **Calibration Procedure**: Place the robot over the white surface and execute the automatic baseline calibration routine to measure surface reflectance coefficients.
- **Black Thresholding**: Configure the `BLACK_THRESHOLD` variable in the firmwares based on regional ambient light conditions.
- **PID Tuning**: Adjust standard coefficients:
  ```c
  error = calculateLinePosition();
  adjustment = Kp * error + Ki * integral + Kd * derivative;
  setMotorSpeeds(baseSpeed + adjustment, baseSpeed - adjustment);
  ```

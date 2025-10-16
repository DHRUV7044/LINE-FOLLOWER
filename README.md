# Line Follower Robot - Team Abhimanyu
Project Overview
A sophisticated line follower robot developed by Team Abhimanyu featuring advanced sensor integration and precise motor control algorithms for optimal path tracking performance.

Features
5x IR Sensors for accurate line detection

PID Control Algorithm for smooth navigation

TB6612FNG Motor Driver for precise motor control

Modular Code Architecture for easy maintenance

Real-time Sensor Calibration

Technical Specifications
Microcontroller: Arduino Uno

Sensors: 5x IR Reflectance Sensors

Motor Driver: TB6612FNG Dual H-Bridge

Power Supply: 3xV  3.7V Li-ion Battery

Chassis: Pre-designed robotic platform

Repository Structure
text
LineFollower-Robot/
├── src/
│   ├── main.ino              # Main robot control program
│   ├── motor_control.cpp     # Motor driver functions
│   ├── sensor_reading.cpp    # IR sensor processing
│   └── pid_controller.cpp    # PID algorithm implementation
├── docs/
│   ├── schematics/           # Circuit diagrams
│   ├── technical_specs.md    # Detailed specifications
│   └── calibration_guide.md  # Sensor calibration procedures
├── assets/
│   ├── images/               # Robot photos and diagrams
│   └── videos/               # Demonstration videos
└── README.md

Installation & Setup
Prerequisites
Arduino IDE 1.8.x or later

Required libraries:

None (uses built-in Arduino functions)

Hardware Connections
Component	Arduino Pin
Left Motor Enable	9
Left Motor IN1	2
Left Motor IN2	3
Right Motor Enable	10
Right Motor IN1	4
Right Motor IN2	5
IR Sensor 1 (Left)	A0
IR Sensor 2	A1
IR Sensor 3	A2
IR Sensor 4 (Right)	A3
Installation Steps
Clone this repository:

bash
git clone https://github.com/Team-Abhimanyu/line-follower-robot.git
Open src/main.ino in Arduino IDE

Connect Arduino Uno via USB

Upload the code to the microcontroller

Calibration Procedure
Place robot over white surface and run calibration routine

Adjust BLACK_THRESHOLD values in code

Test on actual track and fine-tune PID constants

Optimize motor speeds for your specific track

Key Algorithms
Line Following Logic
cpp
// Advanced state machine for path decision
- Straight movement: Middle sensors on line
- Gentle turns: One middle sensor detects line
- Sharp turns: Outer sensors activate
- Line recovery: Systematic search pattern
PID Implementation
cpp
// Proportional-Integral-Derivative control
error = calculateLinePosition();
adjustment = Kp * error + Ki * integral + Kd * derivative;
setMotorSpeeds(baseSpeed ± adjustment);
Team Members
[Team Member 1 Name] - Embedded Programming

[Team Member 2 Name] - Hardware Design

[Team Member 3 Name] - Algorithm Development

[Team Member 4 Name] - Testing & Validation

Competition Performance
1st Place - [Competition Name, Date]

Best Algorithm - [Award Name, Date]

Fastest lap time: [Time] seconds

Reliability: [X]% completed runs

Documentation
Full Technical Documentation

Circuit Schematics

Troubleshooting Guide

License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Thanks to our mentors and technical advisors

Competition organizers for providing the platform

Open-source community for inspiration and resources

Team Abhimanyu - Engineering Excellence in Robotics

For questions or collaborations, please contact: [team.abhimanyu@email.com]


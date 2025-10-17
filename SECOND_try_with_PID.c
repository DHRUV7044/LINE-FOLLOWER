#define AIN1 7
#define AIN2 6
#define PWMA 5
#define BIN1 4
#define BIN2 3
#define PWMB 2
const int sensors[5] = {A0, A1, A2, A3, A4};

// PID Constants
const double Kp= 1.5;  // Proportional Gain
const double Ki = 0.005;   // Integral Gain
const double Kd = 2.0;  // Derivative Gain

// PID Variables
int lastError = 0;
float integral = 0;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    pinMode(sensors[i], INPUT);
  }
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

}

void loop() {
  int position = readSensors();
  int error = position - 2000; // Center position=2000

  int proportional=error;
  integral += error;
  int derivative = error - lastError;
  lastError = error;

  int correction = Kp * proportional + Ki * integral + Kd * derivative;

  int baseSpeed = 150;

  int leftSpeed = baseSpeed + correction;
  int rightSpeed = baseSpeed - correction;

  leftSpeed = constrain(leftSpeed, 0, 255);
  rightSpeed = constrain(rightSpeed, 0, 255);

  motorControl(leftSpeed, rightSpeed);
}

int readSensors() {
  int SensorNumber[5] = {0, 1000, 2000, 3000, 4000};
  int sum = 0;
  int total = 0;

  for (int i = 0; i < 5; i++) {
    int sensorValue = digitalRead(sensors[i]) == HIGH ? 1 : 0;
    sum += sensorValue * SensorNumber[i];
    total += sensorValue;
  }

  if (total == 0) return lastError > 0 ? 4000 : 0; // If no line detected, go to last direction

  return sum / total;
}

void motorControl(int leftSpeed, int rightSpeed) {
  if (leftSpeed > 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  } else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }

  if (rightSpeed > 0) {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  } else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }

  analogWrite(PWMA, abs(leftSpeed));
  analogWrite(PWMB, abs(rightSpeed));
}

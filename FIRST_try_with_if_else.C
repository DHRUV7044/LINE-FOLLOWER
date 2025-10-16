#define IR1 2
#define IR2 3
#define IR3 4
#define IR4 5
#define IR5 6
#define ENL 10
#define ENR 11
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 12
void setup(){
  Serial.begin(9600);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);
  pinMode(IR5,INPUT);
  pinMode(ENL,OUTPUT);
  pinMode(ENR,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  analogWrite(ENL,100);
  analogWrite(ENR,100);
}
void MoveForward(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}
void turnSleft(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}
void turnsharpleft(){
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
}
void turnSright(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
}
void turnsharpright(){
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
}
void stop(){
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);
}
void deadendr(){
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
}
void deadendl(){
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);
}

void loop(){
  int s1=digitalRead(IR1);
  int s2=digitalRead(IR2);
  int s3=digitalRead(IR3);
  int s4=digitalRead(IR4);
  int s5=digitalRead(IR5);
if((s1==1 && s2==1 && s3==0 && s4==1 && s5==1) || (s1==1 && s2==0 && s3==0 && s4==0 && s5==1)){
  MoveForward();
}
else if((s1==1 && s2==0 && s3==1 && s4==1 && s5==1) || (s1==1 && s2==0 && s3==0 && s4==1 && s5==1) || (s1==0 && s2==0 && s3==1 && s4==0 && s5==1) ||  (s1==0 && s2==1 && s3==1 && s4==0 && s5==1)|| (s1==0 && s2==0 && s3==0 && s4==0 && s5==1) ){
  turnSleft();
}
else if((s1==0 && s2==1 && s3==1 && s4==1 && s5==1) || (s1==0 && s2==0 && s3==1 && s4==1 && s5==1) || (s1==0 && s2==0 && s3==0 && s4==1 && s5==1) || (s1==0 && s2==1 && s3==0 && s4==1 && s5==1) ){
  turnsharpleft();
}
else if((s1==1 && s2==1 && s3==1 && s4==0 && s5==1) || (s1==1 && s2==1 && s3==0 && s4==0 && s5==1) || (s1==1 && s2==0 && s3==1 && s4==0 && s5==0) ||  (s1==1 && s2==0 && s3==1 && s4==1 && s5==0)|| (s1==1 && s2==0 && s3==0 && s4==0 && s5==0)){
  turnSright();
}  
else if((s1==1 && s2==1 && s3==1 && s4==1 && s5==0) || (s1==1 && s2==1 && s3==1 && s4==0 && s5==0) || (s1==1 && s2==1 && s3==0 && s4==0 && s5==0) || (s1==1 && s2==1 && s3==0 && s4==1 && s5==0) ){
  turnsharpright();
}
else if(s1==1 && s2==1 && s3==1 && s4==1 && s5==1 ){
  deadendr();
}
else{
  MoveForward();
}
delay(10);
}

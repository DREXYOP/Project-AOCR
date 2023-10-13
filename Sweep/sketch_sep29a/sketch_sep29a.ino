// GR MEANS GEAR MOTOR
// DC  MEANS DC MOTOR
//IN MEANS MOTOR PIN
#include <Servo.h>.
#include <NewPing.h>.  
const int trigPin = 2;
const int echoPin = 3;
long duration;
int distance;
Servo myServo;
String objectDetected;
//motor - A---------dc motor -propeller----l289n
int enDCA = 0;
int inDC1 = 5;
int inDC2 = 6;

// motor -B--------dc motor -propeller----l289n
int enDCB = 1;
int inDC3 = 7;
int inDC4 = 8;

// motor A--- gear motor -conveyor belt-l239d
int enGRA = 2;
int inGR1 = 9;
int inGR2 = 10;

// motor B----gear motor -conveyor belt-l239d
int enGRB = 3;
int inGR3 = 11;
int inGR4 = 12;

// motorc C-----gear motor -conveyor belt-l239d
int enGRC = 4;
int inGR5 = 13;
int inGR6 = 14;

// motor D-----gear motor -conveyor belt-l239d
int enGRD = 5;
int inGR7 = 15;
int inGR8 = 16;

void setup(){
  Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  myServo.attach(4);
  
// for 2 dc motor - propeller-l298n 

  pinMode(enDCA,OUTPUT);
  pinMode(inDC1,OUTPUT);
  pinMode(inDC2,OUTPUT);
  pinMode(enDCB,OUTPUT);
  pinMode(inDC3,OUTPUT);  
  pinMode(inDC4,OUTPUT);

  digitalWrite(inDC1,LOW);
  digitalWrite(inDC2,LOW);
  digitalWrite(inDC3,LOW);
  digitalWrite(inDC4,LOW);

//FOR 4 gear motor conveyor belt-- l293d

  pinMode(enGRA,OUTPUT);
  pinMode(inGR1,OUTPUT);
  pinMode(inGR2,OUTPUT);
  pinMode(enGRB,OUTPUT);
  pinMode(inGR3,OUTPUT);  
  pinMode(inGR4,OUTPUT);
  pinMode(enGRC,OUTPUT);
  pinMode(inGR5,OUTPUT);
  pinMode(inGR6,OUTPUT);
  pinMode(enGRA,OUTPUT);
  pinMode(inGR7,OUTPUT);
  pinMode(inGR8,OUTPUT);
   
}
void loop(){
  for(int i=15;i<=165;i++){
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(",");
    Serial.print(".");
  }
for(int i=165;i<=15;i--){
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(",");
    Serial.print(".");
}
if(distance<200){
// for 2 dc motor - propeller-l298n 

  int speedDCA = 255;
  int speedDCB = 255;

  digitalWrite(inDC1,HIGH);
  digitalWrite(inDC2,LOW);
  analogWrite(enDCA,speedDCA);

  digitalWrite(inDC3,HIGH);
  digitalWrite(inDC4,LOW);
  analogWrite(enDCB,speedDCB);

  delay(10000);

if(distance<3){
digitalWrite(inDC1,LOW);
  digitalWrite(inDC2,LOW);
  digitalWrite(inDC3,LOW);
  digitalWrite(inDC4,LOW);
} 

delay(1000);

}
if(Serial.available()>0){
  objectDetected = Serial.readString();
if(objectDetected == "plastic" || objectDetected == "paper")
{
//FOR 4 gear motor conveyor belt-- l293d

  int speedGRA = 255;
  int speedGRB = 255;
  int speedGRC = 255;
  int speedGRD = 255;
  digitalWrite(inGR1,HIGH);
  digitalWrite(inGR2,LOW);
  analogWrite(enGRA,speedGRA);

  digitalWrite(inGR3,HIGH);
  digitalWrite(inGR4,LOW);
  analogWrite(enGRB,speedGRB);

  digitalWrite(inGR5,HIGH);
  digitalWrite(inGR6,LOW);
  analogWrite(enGRC,speedGRC);

  digitalWrite(inGR7,HIGH);
  digitalWrite(inGR8,LOW);
  analogWrite(enGRD,speedGRD);

delay(10000);


   digitalWrite(inGR1,LOW);
   digitalWrite(inGR2,LOW);
   analogWrite(enGRA,0);

   digitalWrite(inGR3,LOW);
   digitalWrite(inGR4,LOW);
   analogWrite(enGRB,0);

    digitalWrite(inGR5,LOW);
    digitalWrite(inGR6,LOW);
    analogWrite(enGRC,0);

    digitalWrite(inGR7,LOW);
    digitalWrite(inGR8,LOW);
    analogWrite(enGRD,0);


delay(1000);
}
}
}

int calculateDistance(){
  digitalWrite(trigPin,LOW);
delay(1000);
digitalWrite(trigPin,HIGH);
delay(1000);
duration = pulseIn(echoPin,HIGH);
distance = (duration/2)/29.1; 
return distance;
}

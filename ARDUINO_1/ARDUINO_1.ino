// GR MEANS GEAR MOTOR
// DC  MEANS DC MOTOR
//IN MEANS MOTOR PIN
#include <Servo.h>.
#include <NewPing.h>.  
const int trigPin = 2;
const int echoPin = 3;
int pos = 90;
long duration;
int distance;
Servo myServo1;
Servo myServo2;
String objectDetected = "";
String data = ""; 
//motor - A---------dc motor -propeller----l289n
int enDCA = 0;
int inDC1 = 5;
int inDC2 = 6;

// motor -B--------dc motor -propeller----l289n
int enDCB = 1;
int inDC3 = 7;
int inDC4 = 8;


int calculateDistance(){
  digitalWrite(trigPin,LOW);
delay(1000);
digitalWrite(trigPin,HIGH);
delay(1000);
duration = pulseIn(echoPin,HIGH);
distance = (duration/2)/29.1; 
return distance;
}

void setup(){
myServo1.attach(4);
  Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  myServo2.attach(9);
  myServo2.write(pos);
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

}
void loop(){
  for(int i=15;i<=165;i++){
    myServo1.write(i);
    delay(30);
    distance = calculateDistance();
   /* Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(",");
    Serial.print(".");*/
  }
for(int i=165;i<=15;i--){
    myServo2.write(i);
    delay(30);
    distance = calculateDistance();
    /*Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(",");
    Serial.print(".");*/
}     
if(Serial.available()>0){
  objectDetected = Serial.readString();
if(objectDetected == "d"){
// for 2 dc motor - propeller-l298n 
while(Serial.available()){
char inChar = (char)Serial.read();
data += inChar;

if(inChar == '\n'){
  data.trim();
  
  if(data == "L"){
    for(pos=90; pos<=130; pos+=1)
    myServo2.write(pos);

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
data = "";
  }
 
  else if(data == "M"){ 
     myServo2.write(pos);

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
data = "";
  }

else if(data == "R"){
    for(pos =90; pos <=30; pos-=1)
    myServo2.write(pos);

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
 data = "";
  }
delay(1500);
 
  }
}
}
}
}
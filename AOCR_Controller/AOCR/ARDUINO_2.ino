#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define BUZZER 7
const int LDR_PIN = A0;
int LDR_VALUE;
void setup() {

Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(BUZZER, OUTPUT);

}


void loop() {

LDR_VALUE = analogRead(LDR_PIN);
if(LDR_VALUE<100){ 
  digitalWrite(LED5, HIGH);
}
  digitalWrite(LED1, HIGH);  
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH); 
  digitalWrite(LED4, HIGH);
  digitalWrite(BUZZER, HIGH);
  
  delay(1000);

  digitalWrite(LED1, LOW);  
  digitalWrite(LED2, LOW);  
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(BUZZER, LOW);

  delay(1000);
                        
}
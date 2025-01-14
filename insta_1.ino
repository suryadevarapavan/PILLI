void blink1(){
  pinMode(12,OUTPUT);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  delay(500);
  Serial.print("\nIt's Alive!!");
  
}

void blink(){
  pinMode(13,OUTPUT);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  //Serial.print("\nIt's Alive!!");
  
}
const int TRIG_PIN = 6; 
const int ECHO_PIN = 7; 
const int LED_PIN  = 13; 
const int DISTANCE_THRESHOLD = 20; 


float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);       
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);   
  pinMode(LED_PIN, OUTPUT);  
}

void loop() {
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  
  duration_us = pulseIn(ECHO_PIN, HIGH);
  
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)
    blink();
  else
    blink1();  

 
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
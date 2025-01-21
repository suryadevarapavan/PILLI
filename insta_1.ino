void blink1(){
  pinMode(12,OUTPUT);
  digitalWrite(12, HIGH);
  delay(100);
  digitalWrite(12, LOW);
  delay(100);
  //This function blinks second led which represents pilli is awake.

}

void blink(){
  pinMode(13,OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100);
  //This function blinks second led which represents pilli is sleeping.
  
}
const int TRIG_PIN = 6; //variable is used for specifying trigger pin of ultrasonic sensor to ardunio board.
const int ECHO_PIN = 7; //variable is used for specifying echo pin of ultrasonic sensor to ardunio board.
const int DISTANCE_THRESHOLD = 10; // variable is used for checking calculated distance. 

float duration_us, distance_cm; //Variables are used to caluclate distance.

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
  
  distance_cm = 0.017 * duration_us; // Used to calculte distance.

  if(distance_cm < DISTANCE_THRESHOLD)
    blink();
  else
    blink1();  
}

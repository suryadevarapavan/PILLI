#include<LiquidCrystal.h>
int contrast =75;
void blink1(){
  pinMode(10,OUTPUT);
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
  delay(100);
 }

void blink(){
  pinMode(13,OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
  delay(100); 
}
const int numAttributes = 3;
const int numExamples = 4;

const char* trainingData[numExamples][numAttributes] = {
    {"eat", "play", "fetch"},
    {"eat", "play", "fetch"},
    {"neat", "nplay", "fetch"},
    {"eat", "play", "nfetch"}
};
const bool isPositive[numExamples] = {true, true, false, true};
char hypothesis[numAttributes][10];
char inputHypothesis[numAttributes][10] = { "neat", "play", "fetch" }; //Happy Hypothesis

void initializeHypothesis() {
    for (int i = 0; i < numAttributes; i++) {
        strcpy(hypothesis[i], "0");
    }
}

void findS() {
    initializeHypothesis();
    for (int i = 0; i < numExamples; i++) {
        if (isPositive[i]) {
            for (int j = 0; j < numAttributes; j++) {
                if (strcmp(hypothesis[j], "0") == 0) {
                    strcpy(hypothesis[j], trainingData[i][j]);
                } else if (strcmp(hypothesis[j], trainingData[i][j]) != 0) {
                    strcpy(hypothesis[j], "?");
                }
            }
        }
    }
}

bool compareHypotheses(const char inputHypothesis[][10], const char hypothesis[][10], int numAttributes) {
    for (int i = 0; i < numAttributes; i++) {
        if (strcmp(inputHypothesis[i], hypothesis[i]) != 0 && strcmp(hypothesis[i], "?") != 0) {
            return false;
        }
    }
    return true;
}

const int TRIG_PIN = 8; 
const int ECHO_PIN = 9; 
const int LED_PIN_12 = 10; 
const int LED_PIN_13 = 13; 
const int DISTANCE_THRESHOLD = 20; 

float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);       
  pinMode(TRIG_PIN, OUTPUT); 
  pinMode(ECHO_PIN, INPUT);   
  pinMode(LED_PIN_12, OUTPUT);
  pinMode(LED_PIN_13, OUTPUT);

  findS();
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration_us = pulseIn(ECHO_PIN, HIGH);
  distance_cm = 0.017 * duration_us;

  if (distance_cm < DISTANCE_THRESHOLD ) {
    blink();
    Serial.println("Pilli is awake");
    if(compareHypotheses(inputHypothesis, hypothesis, numAttributes) ==true){
      Serial.println("Pilli is Happy");
      } else{
        Serial.println("Pilli is Sad");
      }

      
  } else {
      blink1();
      Serial.println("Pilli is sleeping");
  }
}

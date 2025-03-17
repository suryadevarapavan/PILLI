void blink(){
  pinMode(13,OUTPUT);
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  Serial.print("\nIt's Alive!!");
  
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  if (Serial.available() > 0) {
  String cha=Serial.readStringUntil('\n');
  cha.trim();
  if (cha=="j"){
    Serial.println("RUNNING\n");
  }
  else{
    blink();
  }
  }
  
}

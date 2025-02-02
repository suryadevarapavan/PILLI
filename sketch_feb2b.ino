#include<LiquidCrystal.h>
int contrast=75;
LiquidCrystal lcd(13,12,5,4,3,2);
void setup() {
  int contrast=75;
  analogWrite(6,75);
  lcd.begin(16,2);

}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("HELLO WOLRD!!");
  lcd.setCursor(0,1);
  lcd.print("HW");

}

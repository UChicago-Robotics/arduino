#include <LiquidCrystal.h>

const int d4 = 4, d5 = 5, d6 = 6, d7 = 7;
const int rs = 11, en = 12;
const int ledPin = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("LED STATUS:");
}

void loop() {
  lcd.setCursor(0, 1);
  //lcd.print(millis() / 1000);
  int val = digitalRead(ledPin);
  if (val == 1) {
    lcd.print("ON ");
  }
  else {
    lcd.print("OFF");
  }
  Serial.println(val);

}

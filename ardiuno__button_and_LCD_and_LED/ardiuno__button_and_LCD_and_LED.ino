#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
int ledstatus = 0;
int buttonState=0;
String mytext ="";
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("your led status");
  lcd.setCursor(0, 1);
  lcd.print("is : ");
  
}

void loop() {
  buttonState = digitalRead(7);
  if(buttonState!=1){
    if(ledstatus==0){
      ledstatus=1;
        digitalWrite(2, HIGH);
        delay(500);
        Serial.println("11111111111");
        mytext="high";

    }else if(ledstatus==1){
         ledstatus=0;
        digitalWrite(2, LOW);
                delay(500);
                Serial.println("000000000");
                mytext="low";

    }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("your led status");
  lcd.setCursor(0, 1);
  lcd.print("is : ");
    lcd.print(mytext);

  }
  }

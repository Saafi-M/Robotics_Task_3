#include <LiquidCrystal_I2C.h>
#include <Wire.h>;
#include <Servo.h>

LiquidCrystal_I2C lcd1(0x27, 16, 2);
Servo myservo;

void setup()
{
  pinMode(A4, OUTPUT);
  pinMode(9, INPUT);
  pinMode(13, INPUT);
  lcd1.begin();
  lcd1.backlight();
  myservo.attach(0);
  Serial.begin(9600);
}

void loop()
{
  myservo.write(0);
  Serial.println(myservo.read());
  delay(500);
  myservo.write(360);
  Serial.println(myservo.read());
  delay(500);

  if(digitalRead(9) == HIGH)
  {
    lcd1.setCursor(0,0);
    lcd1.print("Player 1");
    lcd1.setCursor(0,1);
    lcd1.print("wins!");
  }
  else if (digitalRead(13) == HIGH)
  {
    lcd1.setCursor(0, 0);
    lcd1.print("Player 2");
    lcd1.setCursor(0, 1);
    lcd1.print("wins!");
  }
}
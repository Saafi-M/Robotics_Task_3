#include <LiquidCrystal_I2C.h>
#include <Wire.h>;

LiquidCrystal_I2C lcd1(0x27, 16, 2);

void setup()
{
  lcd1.begin();
  lcd1.backlight();
}

void loop()
{
  delay(1000);
  // tell the screen to get ready to write on the top row, first character
  lcd1.setCursor(0,0);
  // print a line where we set the cursor
  lcd1.print("Hello, From");
  // Second line printing
  lcd1.setCursor(0,1);
  lcd1.print("Screen 1");
}
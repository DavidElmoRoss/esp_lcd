/**********************************************************************
  Filename    : Drive LiquidCrystal I2C to display characters
  Description : I2C is used to control the display characters of LCD1602.
  Auther      : www.freenove.com
  Modification: 2024/06/19
**********************************************************************/
#include "arduino.h"              // include arduino.h
#include <LiquidCrystal_I2C.h>    // include LiquidCrysal_I2C.h
#include <Wire.h>                 // include Wire.h

#define SDA 13                    //Define SDA pin as pin 13
#define SCL 14                    //Define SCL pin as pin 14

LiquidCrystal_I2C lcd(0x27,16,2); // lcd i2c address 0x27, 16 cols, 2 rows
void setup() {
  Wire.begin(SDA, SCL);           // attach the IIC pin

  lcd.init();                     // LCD driver initialization
  lcd.backlight();                // Open the backlight
  lcd.setCursor(0,0);             // Move the cursor to row 0, column 0
  lcd.print("hello, world!");     // The print content is displayed on the LCD
}

void loop() {
  lcd.setCursor(0,1);             // Move the cursor to row 1, column 0
  lcd.print("Counter:");          // The count is displayed every second
  lcd.print(millis() / 1000);     // print scaled millis on LCD
  
  delay(1000);                    // delay for 1 second
}

bool i2CAddrTest(uint8_t addr) 
{
  Wire.beginTransmission(addr);
  if (Wire.endTransmission() == 0) 
  {
    return true;
  }
  return false;
}


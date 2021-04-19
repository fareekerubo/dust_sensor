#include "PMS.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//#define I2C_ADDR      0x27

//SoftwareSerial pmsSerial(2, 3);

PMS pms(Serial);
PMS::DATA data;
float dustlevel;
LiquidCrystal_I2C lcd (0x27,16,2); 

void setup()
{
  Serial.begin(9600);
  init_LCD();
}

void init_LCD()
{
  lcd.begin();                                                                 
  lcd.backlight();
  lcd.clear();
  lcd.home();
}

void loop()
{


  while( pms.read(data));
  delay(1000);
  {
    dustlevel =  data.PM_AE_UG_2_5;
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);
    delay(1000);
    Serial.print("PM2.5(ug/m3):");
    Serial.println(data.PM_AE_UG_2_5);
    delay(1000);
  }
}

  

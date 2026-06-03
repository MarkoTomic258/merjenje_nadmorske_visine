#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <LiquidCrystal_I2C.h>

#define SEALEVELPRESSURE_HPA (1022)

Adafruit_BME280 bme;
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  lcd.init();
  lcd.backlight();

  if (!bme.begin(0x76)) {
    lcd.print("BME280 error!");
    while (1);
  }
  
  lcd.setCursor(0, 0); lcd.print("TEMP:");
  lcd.setCursor(0, 1); lcd.print("VLAGA:");
  lcd.setCursor(0, 2); lcd.print("TLAK:");
  lcd.setCursor(0, 3); lcd.print("VIS.:");
}

void loop() {
  float temp   = bme.readTemperature();
  float tlak   = bme.readPressure() / 100.0F;
  float vlaga  = bme.readHumidity();
  float visina = bme.readAltitude(SEALEVELPRESSURE_HPA);

  // Vrstica 1: Temperatura
  lcd.setCursor(11, 0);
  if (temp < 10 && temp >= 0) lcd.print(" ");
  lcd.print(temp, 1); lcd.print(" "); lcd.print((char)223); lcd.print("C");

  // Vrstica 2: Vlaga
  lcd.setCursor(11, 1);
  if (vlaga < 100) lcd.print(" ");
  if (vlaga < 10)  lcd.print(" ");
  lcd.print(vlaga, 1); lcd.print(" %");

  // Vrstica 3: Tlak (hPa)
  lcd.setCursor(9, 2); 
  if (tlak < 1000) lcd.print(" ");
  lcd.print(tlak, 1); lcd.print(" hPa");

  // Vrstica 4: Nadmorska višina
  lcd.setCursor(12, 3);
  if (visina < 1000 && visina >= 0) lcd.print(" ");
  if (visina < 100 && visina >= 0)  lcd.print(" ");
  lcd.print(visina, 0); lcd.print(" m ");

  delay(2000);
}

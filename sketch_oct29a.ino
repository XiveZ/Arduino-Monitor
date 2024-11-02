
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 20, 4);
uint8_t customChar[] = { 0x08, 0x14, 0x08, 0x06, 0x09, 0x08, 0x09, 0x06 };
void setup() {
  Serial.begin(2000000);
  Serial.setTimeout(2000);
  LCD.init();
  LCD.backlight();
  LCD.createChar(0, customChar);
}
void loop() {
  String data;

  while (Serial.available() > 0) {

    data = Serial.readString();
    Serial.flush();
    LCD.setCursor(0, 0);
    LCD.print("  GeForce RTX 3070");

    LCD.setCursor(0, 1);
    LCD.print("GPU:" + data.substring(0, 2));
    LCD.setCursor(6, 1);
    LCD.write(byte(0));
    LCD.setCursor(8, 1);
    LCD.print(data.substring(14, 19) + "W " + data.substring(4, 8) + "M");

    LCD.setCursor(0, 2);
    LCD.print(" Core(TM) i7-12700H ");

    LCD.setCursor(0, 3);
    LCD.print(data.substring(22, 27));
    LCD.setCursor(5, 3);
    LCD.write(byte(0));
  }
}
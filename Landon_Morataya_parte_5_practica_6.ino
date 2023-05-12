/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: TERMOMETRO
   Dev: Landon Morataya
   Fecha: 12/05/2023
*/
#include <LiquidCrystal_I2C.h>

#include <OneWire.h>
#include <DallasTemperature.h>
#define S 2
LiquidCrystal_I2C LCD(0x27, 16, 2);
OneWire ourWire(S);
DallasTemperature sensor(&ourWire);

void setup() {
  LCD.init();
  LCD.backlight();
  delay(1000);
  sensor.begin();
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);


}
void loop() {

  sensor.requestTemperatures();

  LCD.setCursor(0, 0);
  LCD.print("Grados C");
  LCD.setCursor(9, 0);
  LCD.print(sensor.getTempCByIndex(0));
  LCD.setCursor(0, 1);
  LCD.print("Grados F");
  LCD.setCursor(9, 1);
  LCD.print(sensor.getTempFByIndex(0));

  if (sensor.getTempCByIndex(0) >= 30) {
    digitalWrite(3, HIGH);
  }
  else {
    digitalWrite(3, LOW);
  }
  if (sensor.getTempCByIndex(0) <= 16) {
    digitalWrite(4, HIGH);
  }
  else {
    digitalWrite(4, LOW);
  }
  if (sensor.getTempCByIndex(0) >= 16 && sensor.getTempCByIndex(0) <= 30) {
    digitalWrite(5, HIGH);
  }

  else {
    digitalWrite(5, LOW);
    }
   
    }

 
 
 

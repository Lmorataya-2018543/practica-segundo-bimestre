/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: SENSOR DE PARQUEO
   Dev: Landon Antonio Morataya Mejia
   Fecha: 11/05/2023
*/

#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C LCD(0x27, 16, 2); 

int trig = 11;
int echo = 12;
int duracion;
int distancia;
int contador = 0;
byte BLOCK[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11011,
  B11111
};
void setup() {
  
  LCD.init();
  LCD.backlight();
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  LCD.createChar(0, BLOCK);
}

void loop() {
  // Sensor ultraSonico
  digitalWrite(trig, LOW);//Apaga el ping Triger del sensor
  delay(10);
  digitalWrite(trig, HIGH);//Enciende el ping Triger del sensor
  delay(10);
  digitalWrite(trig, LOW);//Apaga el ping Triger del sensor


  //Encender y apagar el boton triger hace que este mande un pulso
  // Medio segundo para que asi el boton Echo resiva la señal 

  duracion = pulseIn(echo, HIGH); 
  

  distancia = duracion * 0.034 / 2;
  Serial.print(String(distancia)); 
  Serial.println(" cm");
  delay(400);

  if(distancia >=20 && distancia <= 25){
    
    LCD.setCursor(3, 0);
    LCD.print("    50    ");
    LCD.setCursor(5, 1);
    LCD.print("libre  ");  
    LCD.setCursor(0, 0);
    LCD.write(0);
    LCD.setCursor(1, 0);
    LCD.write(0);
    LCD.setCursor(2, 0);
    LCD.write(0);
    LCD.setCursor(15, 0);
    LCD.write(0);
    LCD.setCursor(14, 0);
    LCD.write(0);
    LCD.setCursor(13, 0);
    LCD.write(0);
  }
  if(distancia >= 10 && distancia <= 19){
    
    LCD.setCursor(5, 0);
    LCD.print("  30  ");
    LCD.setCursor(5, 1);
    LCD.print("Cuidado");  
    LCD.setCursor(0, 0);
    LCD.write(0);
    LCD.setCursor(1, 0);
    LCD.write(0);
    LCD.setCursor(2, 0);
    LCD.write(0);
    LCD.setCursor(3, 0);
    LCD.write(0);
    LCD.setCursor(4, 0);
    LCD.write(0);
    LCD.setCursor(15, 0);
    LCD.write(0);
    LCD.setCursor(14, 0);
    LCD.write(0);
    LCD.setCursor(13, 0);
    LCD.write(0);
    LCD.setCursor(12, 0);
    LCD.write(0);
    LCD.setCursor(11, 0);
    LCD.write(0);
  }
  if(distancia >=0&& distancia <= 9){
    
    LCD.setCursor(7, 0);
    LCD.print("10");
    LCD.setCursor(5, 1);
    LCD.print(" ALTO   ");  
    LCD.setCursor(0, 0);
    LCD.write(0);
    LCD.setCursor(1, 0);
    LCD.write(0);
    LCD.setCursor(2, 0);
    LCD.write(0);
    LCD.setCursor(3, 0);
    LCD.write(0);
    LCD.setCursor(4, 0);
    LCD.write(0);
    LCD.setCursor(5, 0);
    LCD.write(0);
    LCD.setCursor(6, 0);
    LCD.write(0);
    LCD.setCursor(15, 0);
    LCD.write(0);
    LCD.setCursor(14, 0);
    LCD.write(0);
    LCD.setCursor(13, 0);
    LCD.write(0);
    LCD.setCursor(12, 0);
    LCD.write(0);
    LCD.setCursor(11, 0);
    LCD.write(0);
    LCD.setCursor(10, 0);
    LCD.write(0);
    LCD.setCursor(9, 0);
    LCD.write(0);
  }
  

  

}

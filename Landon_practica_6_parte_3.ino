/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto:practica 6 parte 3
   alumno: Landon Antonio
   Fecha: 5/5/2023 de mayo
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2); 
#define DWH(pin)   digitalWrite(pin, HIGH)
#define DWL(pin)   digitalWrite(pin, LOW)
#define buzzer A1
#define LD11 A0

void  configPinesInput(void);
void  configpinesOutput(void);
int trig = 12;
int echo = 13;
int duracion;
int distancia;
int contador = 0;

void setup()
{
  LCD.init();
  LCD.backlight();
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  configpinesOutput();
}
void loop()
{
  digitalWrite(trig, LOW);//Apaga el ping Triger del sensor
  delay(10);
  digitalWrite(trig, HIGH);//Enciende el ping Triger del sensor
  delay(10);
  digitalWrite(trig, LOW);//Apaga el ping Triger del sensor


  

  duracion = pulseIn(echo, HIGH); 
  distancia = duracion * 0.034 / 2;
  Serial.print(String(distancia)); 
  Serial.println(" cm");
  delay(400);
  if (distancia >= 30 && distancia <= 45)
  {
    LCD.setCursor(0, 0);
    LCD.print("Persona/objeto  ");
    LCD.setCursor(0, 1);
    LCD.print("Acercandose     ");  


          if (distancia >= 46 && distancia <= 50) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(A0, LOW);
          }
    if (distancia >= 40 && distancia <= 45) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(A0, LOW);
          }
          if (distancia >= 35 && distancia <= 39) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(A0, LOW);
          }
          if (distancia >= 30 && distancia <= 34) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(A0, LOW);

    }
  }

  if (distancia >= 15 && distancia <= 29) {
    LCD.setCursor(0, 0);
    LCD.print("    Cuidado     ");
    LCD.setCursor(0, 1);
    LCD.print("Espacio Privado ");
    
    if (distancia >= 25 && distancia <= 29) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(A0, LOW);
          }
          if (distancia >= 20 && distancia <= 24) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(A0, LOW);
    }
          if (distancia >= 15 && distancia <= 19) {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(A0, LOW);
    }
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    noTone(buzzer);
    tone(buzzer, 659, 100);
    delay(1000);
   
  }
      
  if (distancia >= 0 && distancia <= 14) {
  LCD.setCursor(0, 0);
    LCD.print("   Invadiendo   ");
    LCD.setCursor(0, 1);
    LCD.print("Espacio Privado ");
    
    if (distancia >= 10 && distancia <= 14) {
          digitalWrite(2, HIGH);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(6, HIGH);
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(9, HIGH);
          digitalWrite(10, LOW);
          digitalWrite(A0, LOW);
        }
        if (distancia >= 5 && distancia <= 9) {
          digitalWrite(2, HIGH);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(6, HIGH);
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(9, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(A0, LOW);
        }
        if (distancia >= 0 && distancia <= 5) {
          digitalWrite(2, HIGH);
          digitalWrite(3, HIGH);
          digitalWrite(4, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(6, HIGH);
          digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(9, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(A0, HIGH);
        }
    
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);;
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    noTone(buzzer);
    tone(buzzer, 659, 1000);
    delay(1000);
  }
    
    if (distancia >= 46) {
      LCD.setCursor(0, 0);
      LCD.print("Fuera de alcanze");
      LCD.setCursor(0, 1);
      LCD.print("Fuera de alcanze");
            digitalWrite(2, LOW);
            digitalWrite(3, LOW);
            digitalWrite(4, LOW);
            digitalWrite(5, LOW);
            digitalWrite(6, LOW);
            digitalWrite(7, LOW);
            digitalWrite(8, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            digitalWrite(A0, LOW);
    }
  
          
          

        
}

void  configpinesOutput(void) {

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(A0, OUTPUT);

}

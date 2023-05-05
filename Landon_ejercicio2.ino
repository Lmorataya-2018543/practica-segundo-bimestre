/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: nombre y carnet en display
   alumno:Landon Morataya
   Fecha: 4/5/2023 de abril
*/


#include <LiquidCrystal.h>

#define RS   12
#define enable 11
#define  D4  5
#define D5  4
#define D6  3
#define D7  2
#define DWH(pin)   digitalWrite(pin, HIGH)
#define DWL(pin)   digitalWrite(pin, LOW)
#define buzzer 8
void  configPinesInput(void);
void  configpinesOutput(void);
int trig = 9;
int echo = 10;
int duracion;
int distancia;
int contador=0;
int dis7;

LiquidCrystal LCD (RS, enable, D4, D5, D6, D7);
  byte LANDONLCD[8] = {
  B01110,
  B01110,
  B01110,
  B10001,
  B01010,
  B00100,
  B01010,
  B10001
};


  void setup(){
   
  LCD.begin(16,2);  
  Serial.begin(9600);
  configPinesInput();
  configpinesOutput();
  LCD.print("Conteo de ");
  LCD.setCursor(0,2);
  LCD.print("Personas:  0");
  LCD.createChar(0, LANDONLCD);


}

void loop (){

 
   digitalWrite(trig, LOW);
  delay(10);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
             

 
 
 
  duracion = pulseIn(echo, HIGH);
 
  distancia= duracion*0.034/2;    
  Serial.print(String(distancia));
  Serial.println(" cm");
  delay(400);                    
           



  if(distancia>=6 && distancia <=10)
  {
   
    contador++;
     delay(1000);
      LCD.setCursor(0,0);
      LCD.print("Conteo de ");
      LCD.setCursor(0,2);
      LCD.print("Personas: ");
      LCD.setCursor(11,2);
      LCD.print(contador);  
    }
   
    if(contador>=17){

      contador=60;
      tone(buzzer, 659, 1000);    
      LCD.setCursor(0,0);
      LCD.print("TOTAL MAXIMO DE ");
      LCD.setCursor(0,1);
      LCD.print("    PERSONAS    ");
       LCD.setCursor(0,1);
      LCD.write(1);
      LCD.setCursor(15,1);
      LCD.write(1);
      LCD.setCursor(0,0);
      delay(1000);
      LCD.print("                ");
      LCD.setCursor(0,1);
      LCD.print("                ");
      delay(1000);
      LCD.setCursor(0,0);
      tone(buzzer, 659, 1000);
      LCD.print("TOTAL MAXIMO DE ");
      LCD.setCursor(0,1);
      LCD.print("    PERSONAS    ");
      LCD.setCursor(0,1);
      LCD.write(1);
       LCD.setCursor(15,1);
      LCD.write(1);
      delay(1000);
      
      
     
    }
                         
   }

 void  configPinesInput(void){
  pinMode(echo, INPUT);
 
 }

void  configpinesOutput(void)
{
     pinMode(trig, OUTPUT);  
     
                     
}

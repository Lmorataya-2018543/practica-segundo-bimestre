/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: sensor
   alumno:Landon Antonio Morataya Mejia
   Fecha: 28 de abril
*/
int trig = 11;
int echo = 12;
int duracion;
int distancia;
#define Buzzer 2
int Do=261;
int Re=293;
int Mi=329;
int Fa=349;
int Sol=392;
int La=440;
int Si=493;
void  configPinesInput(void);
void  configpinesOutput(void);


  
void setup() {
  Serial.begin(9600); 
  configPinesInput();
  configpinesOutput();
}



void loop() {
  
  digitalWrite(trig, LOW);//Apaga el ping Triger del sensor 
  delay(10); 
  digitalWrite(trig, HIGH);//Enciende el ping Triger del sensor 
  delay(10);
  digitalWrite(trig, LOW);//Apaga el ping Triger del sensor
             


  
  duracion = pulseIn(echo, HIGH); 
                                 
  
  distancia= duracion*0.034/2;    
  Serial.print(String(distancia)); 
  Serial.println(" cm");
  delay(400);  


if(distancia>=5 && distancia <=10)
{

   tone(Buzzer, Do, 1000);
   
 }
 if(distancia>=11 && distancia <=15){

   tone(Buzzer, Re, 1000);
  
 }
 if(distancia>=16 && distancia <=20){

   tone(Buzzer, Mi, 1000);
   
 }
 if(distancia>=21 && distancia <=25){

   tone(Buzzer, Fa, 1000);
   
 }
 if(distancia>=26 && distancia <=30){

   tone(Buzzer, Sol, 1000);
  
 }
 if(distancia>=31 && distancia <=35){

   tone(Buzzer, La, 1000);
   
 }
 if(distancia>=36 && distancia <=40){

   tone(Buzzer, Si, 1000);
   
 }
 
 if(distancia>=0 && distancia <=4)
   noTone(Buzzer);
   

 if(distancia>=37){
   noTone(Buzzer);
   
 }
}

void  configPinesInput(void){
  pinMode(echo, INPUT); 
 }

void  configpinesOutput(void)
{ 
     pinMode(trig, OUTPUT);
     pinMode(Buzzer, OUTPUT);                      
}

  
  

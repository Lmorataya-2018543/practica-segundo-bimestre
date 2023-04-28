/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM / EB5AV 
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: sensor
   alumno:landon Antonio
   Fecha: 27 de abril
*/





void  configPinesInput(void);
void  configpinesOutput(void);
int   contador_display(int a, int b, int c, int d, int e, int f, int g, int B);
int trig = 11;
int echo = 12;
int duracion;
int distancia;
int contador=0;
int dis7;

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

  if(distancia>=6 && distancia <=10) 
  {
  
    contador++;
     Serial.println("contador");
     delay(1000);
    } 
 
    contador_display(3,4,5,6,7,8,9,10);    
}
 void  configPinesInput(void){
  pinMode(echo, INPUT);
  
 }

void  configpinesOutput(void)
{
     
     pinMode(trig, OUTPUT);  
     pinMode(3, OUTPUT);
     pinMode(4, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(6, OUTPUT);
     pinMode(7, OUTPUT);
     pinMode(8, OUTPUT);
     pinMode(9, OUTPUT);
     pinMode(10, OUTPUT);           
                     
}
int   contador_display(int a, int b, int c, int d, int e, int f, int g, int B){
switch(contador){
          
          case(0):
              digitalWrite(a, HIGH);
              digitalWrite(b, HIGH);
              digitalWrite(c, HIGH);
              digitalWrite(d, HIGH);
              digitalWrite(e, HIGH);
              digitalWrite(f, HIGH);
             digitalWrite(g, LOW);
             digitalWrite(B, HIGH);
            break;
          case(1):
             digitalWrite(a, LOW);
             digitalWrite(b, HIGH);
             digitalWrite(c, HIGH);
             digitalWrite(d, LOW);
             digitalWrite(e, LOW);
             digitalWrite(f, LOW);
             digitalWrite(g, LOW);
             digitalWrite(B, HIGH);
         break;
           case(2):
             digitalWrite(a, HIGH);
             digitalWrite(b, HIGH);
             digitalWrite(c, LOW);
             digitalWrite(d, HIGH);
             digitalWrite(e, HIGH);
             digitalWrite(f, LOW);
             digitalWrite(g, HIGH);
             digitalWrite(B, HIGH);
         break;
          case(3):
             digitalWrite(a, HIGH);
             digitalWrite(b, HIGH);
             digitalWrite(c, HIGH);
             digitalWrite(d, HIGH);
           digitalWrite(e, LOW);
            digitalWrite(f, LOW);
             digitalWrite(g, HIGH);
             digitalWrite(B, HIGH);
         break;
          case(4):
            digitalWrite(a, LOW);
             digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);
            digitalWrite(d, LOW);
            digitalWrite(e, LOW);
            digitalWrite(f, HIGH);
            digitalWrite(g, HIGH);
            digitalWrite(B, HIGH);
         break;                
          case(5):
            digitalWrite(a, HIGH);
             digitalWrite(b, LOW);
            digitalWrite(c, HIGH);
            digitalWrite(d, HIGH);
            digitalWrite(e, LOW);
            digitalWrite(f, HIGH);
            digitalWrite(g, HIGH);
            digitalWrite(B, HIGH);
         break;       
          case(6):
             digitalWrite(a, HIGH);
             digitalWrite(b, LOW);
            digitalWrite(c, HIGH);
            digitalWrite(d, HIGH);
             digitalWrite(e, HIGH);
            digitalWrite(f, HIGH);
            digitalWrite(g, HIGH);
            digitalWrite(B, HIGH);
         break;        
          case(7):
            digitalWrite(a, HIGH);
            digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);
           digitalWrite(d, LOW);
             digitalWrite(e, LOW);
             digitalWrite(f, LOW);
             digitalWrite(g, HIGH);
             digitalWrite(B, HIGH);
         break;
          case(8):
            digitalWrite(a, HIGH);
            digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);
            digitalWrite(d, HIGH);
             digitalWrite(e, HIGH);
            digitalWrite(f, HIGH);
            digitalWrite(g, HIGH);
            digitalWrite(B, HIGH);
         break;
           case(9):
            digitalWrite(a, HIGH);
            digitalWrite(b, HIGH);
            digitalWrite(c, HIGH);
            digitalWrite(d, LOW);
             digitalWrite(e, LOW);
            digitalWrite(f, HIGH);
            digitalWrite(g, HIGH);
             digitalWrite(B, LOW);
            contador=9;
         break; 
             
    }
  
}

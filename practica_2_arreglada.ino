#define LEER(pin) digitalRead(pin)
#define ENTRADA(pin) pinMode(pin, INPUT)
#define BOTON0 2
#define BOTON1 3
int x = 0;
struct productos
{
  String NOMBRE;
  int CANTIDAD;
}L1 = {"takis", 45}, L2 = {"cheetos", 52}, L3 = {"tosinitos", 25}, L4 = {"doritos", 38};
void setup() {
  ENTRADA(BOTON0);

}

void loop() {
  Serial.begin(9600);
  bool VERIFY_FORWARD = LEER(BOTON0);
  bool VERIFY_REVERSE = LEER(BOTON1);

  if ((VERIFY_FORWARD == HIGH) & (VERIFY_REVERSE == LOW))
  {
   delay(200);
   x++ ;
    if(x == 1)
    {
      Serial.println("Nombre          Cantidad");
      Serial.print(L1.NOMBRE);
      Serial.print("            ");
      Serial.println(L1.CANTIDAD);
      x++;
      delay(50);
    }

    if(x == 3){
      Serial.print(L2.NOMBRE);
      Serial.print("          ");
      Serial.println(L2.CANTIDAD);
      x++;
      delay(50);
    }

    if(x == 5){
      Serial.print(L3.NOMBRE);
      Serial.print("            ");
      Serial.println(L3.CANTIDAD);
      x++;
      delay(50);
    }

    if(x == 7){
      Serial.print(L4.NOMBRE);
      Serial.print("        ");
      Serial.println(L4.CANTIDAD);
      x++;
      delay(50);
    }
   
  }
  if((VERIFY_REVERSE == HIGH) & (VERIFY_FORWARD == LOW))
  {
    delay(200);
    x--;
      if(x == 1){
        Serial.print(L4.NOMBRE);
        Serial.print("        ");
        Serial.println(L4.CANTIDAD);
        delay(50);
        x=8;
      }

      if(x == 3){
        Serial.print(L1.NOMBRE);
        Serial.print("            ");
        Serial.println(L1.CANTIDAD);
        delay(50);
        x--;
      }

      if(x == 5){
        Serial.print(L2.NOMBRE);
        Serial.print("          ");
        Serial.println(L2.CANTIDAD);
        delay(50);
        x--;    
      }

      if(x==7){
        Serial.print(L3.NOMBRE);
        Serial.print("            ");
        Serial.println(L3.CANTIDAD);
        delay(50);
        x--;
      }

      if(x<0){
        x = 7;
      }
     
  }
}

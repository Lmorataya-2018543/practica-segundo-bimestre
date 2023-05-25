#include <Adafruit_NeoPixel.h>
#include <Wire.h>    
#include <LiquidCrystal_I2C.h>
#define Cantidad_Leds 7
#define pin_Led 2
#define botton 3
#define botton1 4
#define botton2 5

Adafruit_NeoPixel anillo(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);
LiquidCrystal_I2C LCDKEVIN(0x27,16,2);

void setup()
{
  LCDKEVIN.begin(16,2); 
  anillo.begin();
  pinMode(botton,OUTPUT);
  pinMode(botton1,OUTPUT);
  LCDKEVIN.init();
  LCDKEVIN.backlight();
  
}

void loop()
{
  
  if(digitalRead(botton)==HIGH) {//secuencia NO.1
   LCDKEVIN.clear(); 
   LCDKEVIN.setCursor(0,0);
   LCDKEVIN.print("Secuencia NO.1:");
   delay(100);
   LCDKEVIN.setCursor(0,1);
   LCDKEVIN.print("Ascendente");   
  for(int i =0; i<8;i++)
  {
    anillo.setPixelColor(i,anillo.Color(255,0,0));
    anillo.show();  //muestro el color en el led
    delay(250);
  } 
    anillo.clear();
  }
  
  
  if(digitalRead(botton1)==HIGH) {//secuencia NO.2
   LCDKEVIN.clear(); 
   LCDKEVIN.setCursor(0,0);
   LCDKEVIN.print("Secuencia NO.1:");
   delay(100);
   LCDKEVIN.setCursor(0,1);
   LCDKEVIN.print("Descendente"); 
    
  for(int i =7; i>=0;i--)
  {
    anillo.setPixelColor(i,anillo.Color(0,0,255));
    anillo.show();  //muestro el color en el led
    delay(250);
  } 
    anillo.clear();
  }
  
  if(digitalRead(botton2)==HIGH) { //secuencia NO.3
   LCDKEVIN.setCursor(0,0);
   LCDKEVIN.print("Secuencia NO.3:");
   LCDKEVIN.setCursor(0,1);
   LCDKEVIN.print("Autofantastico"); 
    
  for(int i =0; i<=8;i++)
  {
    anillo.setPixelColor(i,anillo.Color(0,255,0));
    anillo.show();  //muestro el color en el led
    delay(140);
  } 
    anillo.clear();

   LCDKEVIN.setCursor(0,0);
   LCDKEVIN.print("Secuencia NO.3:");
   LCDKEVIN.setCursor(0,1);
   LCDKEVIN.print("Autofantastico"); 
    
 for(int i =7; i>=0;i--)
  {
    anillo.setPixelColor(i,anillo.Color(0,255,0));
    anillo.show();  //muestro el color en el led
    delay(120);
  } 
    anillo.clear();
    
 
  }
  
  }

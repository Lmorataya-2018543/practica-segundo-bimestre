
  
#include <LiquidCrystal.h>

  
LiquidCrystal landon(12,11,5,4,3,2);
  
void setup() 
{
  landon.begin(16,2);
    
    landon.print("Landon Morataya");
    landon.setCursor(0,1);
    landon.print("2018543");
  }
    
    void loop() 
    
   { 
  
  }

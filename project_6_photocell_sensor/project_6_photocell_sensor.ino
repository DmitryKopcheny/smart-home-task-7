#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int LED = 5; 
int val = 0; 
LiquidCrystal_I2C lcd (0x27,16,2);
void setup () {
      pinMode (LED, OUTPUT); 
      lcd.init (); 
      lcd.init (); 
      lcd.backlight ();
}
void loop () {
       val = analogRead (A1);
      lcd.clear ();
      lcd.print (val); // LED print hello, world!
       if (val <900)
       {
       digitalWrite (LED, LOW);
       } 
       else 
       {
       digitalWrite (LED, HIGH);
       }
       delay (100); 
} 


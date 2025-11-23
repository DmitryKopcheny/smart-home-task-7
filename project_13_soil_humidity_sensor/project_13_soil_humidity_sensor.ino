#include <Wire.h>
#include <LiquidCrystal_I2C.h>
volatile int value;
LiquidCrystal_I2C mylcd (0x27,16,2); 
void setup () {
  Serial.begin (9600); 
  value = 0;
  mylcd.init ();
  mylcd.backlight (); 
  mylcd.clear (); 
  Serial.begin (9600); 
  pinMode (A2, INPUT); 
}
void loop () {
  Serial.print ("Soil moisture value:"); 
  Serial.print ("");
  Serial.println (value);
  delay (500); 
  value = analogRead (A2); 
  if (value <300) 
{
    mylcd.clear (); 
    mylcd.setCursor (0, 0);
    mylcd.print ("value:"); 
    mylcd.setCursor (6, 0);
    mylcd.print (value);
    mylcd.setCursor (0, 1);
    mylcd.print ("dry soil"); 
    delay (300); 
  } 
  else if ((value>=300) && (value <= 700)) 
 {
    mylcd.clear (); 
    mylcd.setCursor (0, 0);
    mylcd.print ("value:");
    mylcd.setCursor (6, 0);
    mylcd.print (value);
    mylcd.setCursor (0, 1);
    mylcd.print ("humid soil"); 
    delay (300); 
  } else if (value> 700) 
 {
    mylcd.clear ();
    mylcd.setCursor (0, 0);
    mylcd.print ("value:");
    mylcd.setCursor (6, 0);
    mylcd.print (value);
    mylcd.setCursor (0, 1);
    mylcd.print ("in water"); 
    delay (300); 
  }}

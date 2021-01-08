#include <dht11.h>
#define DHT11PIN 4 // broche DATA -> broche 4

dht11 DHT11;
 int pinled =7;
 int pinled1=6;
 int incomingByte =0; 
 char data;
void setup()
{ pinMode(pinled,OUTPUT);
pinMode(pinled1,OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect. Needed for native USB (LEONARDO)
  }
  
  
}
 
void loop()
{
  DHT11.read(DHT11PIN);
  data=Serial.read();
if(DHT11.temperature>28)
{
 Serial.write('1'); 
 delay(20);
}
else if(DHT11.temperature<28)
{
   Serial.write('2'); 
    delay(20);

}   
if(Serial.available())
{data=Serial.read();
if(data=='3')
{
  digitalWrite(pinled,LOW);
    digitalWrite(pinled1,HIGH);

}else if(data=='4')
{
  digitalWrite(pinled1,LOW);
    digitalWrite(pinled,HIGH);

}
}
}

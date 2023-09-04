#include <RH_ASK.h>
#include <SPI.h>
#include <string.h>
RH_ASK driver;
String text;



void setup()
{
    Serial.begin(9600); 
   
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  
    uint8_t buf[30];
    uint8_t buflen = sizeof(buf);
   if (driver.recv(buf, &buflen)) 
    {
      text = (char*)buf;
     Serial.println(text);
    if(text.indexOf("START xxxxxxxx")>=0)
    {
    Serial.print("motor starts");
                          
    } 
    else if(text.indexOf("STOP xxxxxxxx")>=0)
    {
    Serial.print("motor STOPS");
    
    } 
     text.remove(0,100);
   }
}

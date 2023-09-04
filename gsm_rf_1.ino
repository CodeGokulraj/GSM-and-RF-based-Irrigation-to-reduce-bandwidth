#include<String.h>
#include<SoftwareSerial.h>
#include <RH_ASK.h>
#include <SPI.h>
SoftwareSerial gsm(9,10);
RH_ASK rf_driver;
String text;
String texta,textb;
void setup()
{
  gsm.begin(9600);  
  Serial.begin(9600);
  delay(2000);
  gsm.println("AT+CMGF=1");  
  delay(1000);
  gsm.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
  delay(1000);    
  gsm.print("WELCOME TO YOUR SMART AUTOMATED FARM \n \n SEND 'START' TO CONTINUE");    
  delay(1000);    
  gsm.println((char)26);
  rf_driver.init();
     
}
void loop()
{    
  gsm.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
  if(gsm.available()>0)
  {  
    Serial.println("The system 1");  
    text = gsm.readString();
    Serial.print(text);
   
  }
     
  if((text.indexOf("START")>=0 && text.indexOf("xxxxxxxxxx")>=0))        
  {  
  gsm.println((char)26);
  delay(1000);
  Serial.println("it works!");  
  gsm.println("AT+CMGF=1");  
  delay(1000);
  gsm.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
  delay(1000);    
  gsm.print("1. GET YOUR FIELD DATA(ONE) \n 2.CONTROL PUMP(TWO) \n 3.AUTOMATIC MODE(THREE) \n 3.EXIT");    
  delay(1000);    
  gsm.println((char)26);    
  delay(1000);
  for(int i=0;i<=30;i++)
  {
  gsm.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
  if(gsm.available()>0)
  {  
    Serial.println("The system 2");  
    texta = gsm.readString();
    Serial.print(texta);
  }
 
  if(texta.indexOf("TWO")>=0 && texta.indexOf("xxxxxxxxxx")>=0)        
  {  
  gsm.println((char)26);
  delay(1000);
  Serial.println("it works!");  
  gsm.println("AT+CMGF=1");  
  delay(1000);
  gsm.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
  delay(1000);    
  gsm.print("1.ON PUMP \n 2.OFF PUMP \n 3.BACK");    
  delay(100);    
  gsm.println((char)26);    
  delay(1000);
  textb.remove(0,100);
  for(int j=0;j<=30;j++)
  {
 
  gsm.println("AT+CNMI=2,2,0,0,0");      
  delay(1000);  
  textb.remove(0,100);
  if(gsm.available()>0)
  {  
    Serial.println("The system 3");
    textb = gsm.readString();
    Serial.print(textb);
  }        
  if((textb.indexOf("ON PUMP")>=0 )&& (textb.indexOf("xxxxxxxxxx")>=0))
  {
    gsm.println((char)26);
    delay(1000);
    const char *msg = "START xxxxxxxxxx";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
    Serial.print("SIGNAL TRANSMITTED");
   
  }
  else if((textb.indexOf("OFF PUMP")>=0) && (textb.indexOf("xxxxxxxxxx")>=0))  
  {
    gsm.println((char)26);
    delay(1000);
    const char *msg = "STOP xxxxxxxxxx";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
   
  }
   else if((textb.indexOf("BACK")>=0) && (textb.indexOf("xxxxxxxxxx")>=0))  
  {
     break;
  }
  }
  delay(1000);
  }
  else if(texta.indexOf("EXIT")>=0 && textb.indexOf("xxxxxxxxxx")>=0)  
  {
     break;
  }
  delay(1000);
  }
  text.remove(0,100);  
   texta.remove(0,100);  
   textb.remove(0,100);
   while(1);
  }  
  delay(2000);
 
 
}

#include <ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h>

ESP8266WiFiMulti hello;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  hello.addAP("there isnot wifi","1234567890987654321");
  hello.addAP("hello","12345678");
  
  Serial.print("Connecting");
  hello.run();
  
  Serial.print("please wait a mement");
  while(hello.run()!=WL_CONNECTED){
    delay(1000);
    Serial.print(".");}
  Serial.println(WiFi.localIP());
    
  Serial.print("connect scessful");
}

void loop() {
  // put your main code here, to run repeatedly:

}

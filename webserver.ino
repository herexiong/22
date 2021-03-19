#include<ESP8266WiFi.h>
#include<ESP8266WiFiMulti.h>
#include<ESP8266WebServer.h>

ESP8266WiFiMulti wifi_connect;
ESP8266WebServer Web_Serial(80);

void handleRoot() {   //处理网站根目录“/”的访问请求 
  Web_Serial.send(200, "text/plain", "Hello from ESP8266");   // NodeMCU将调用此函数。
}
 
// 设置处理404情况的函数'handleNotFound'
void handleNotFound(){                                        // 当浏览器请求的网络资源无法在服务器找到时，
  Web_Serial.send(404, "text/plain", "404: Not found");   // NodeMCU将调用此函数。
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  wifi_connect.addAP("there isnot wifi","1234567890987654321");
  wifi_connect.addAP("void","void");

  Serial.print("Connecting to wifi now/n");
  wifi_connect.run();
  while(wifi_connect.run()!=WL_CONNECTED){
    delay(1000);
    Serial.print(".");}
  Serial.print("WiFi was connect scessful");
  Serial.print(WiFi.localIP());
  Serial.print("/n");
  
  Serial.print("Booting WebSerial");
  Web_Serial.begin();
  Web_Serial.on("/", handleRoot); 
  Web_Serial.onNotFound(handleNotFound);

}

void loop() {
  // put your main code here, to run repeatedly:
  Web_Serial.handleClient();
} 


#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "pageControl.h"

#define STA_MODE

#ifdef STA_MODE
  //SSID and Password of your WiFi router
  // const char *ssid = "wifi cua toi";
  // const char *password = "deochonhe";

  const char *ssid = "cdttech.vn";
  const char *password = "117duongso3";
#endif

ESP8266WebServer server(80);

int led1 = D1;
int led2 = D2;
int led3 = D3;
int led4 = D4;

void setupLed(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void handleRoot()
{
  String s1 = MAIN_page_1;
  server.send(200, "text/html", s1); 
}
//==============================================================
//                  SETUP
//==============================================================
void setup(void)
{
  Serial.begin(9600);
  Serial.println("");

  setupLed();

  #ifdef STA_MODE
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password); //Connect to your WiFi router
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      Serial.print(".");
    }
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    if (!MDNS.begin("esp8266")) {
      Serial.println("Error setting up MDNS responder!");
      while (1) {
        delay(1000);
      }
    }
    Serial.println("http://esp8266.local/");
  #else
    WiFi.mode(WIFI_AP);
    WiFi.softAP("my wifi", "12344321");
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());
  #endif

  server.on("/", handleRoot); //Which routine to handle at root location

  server.begin(); //Start server
  Serial.println("HTTP server started");
}
//==============================================================
//                     LOOP
//==============================================================
void loop(void)
{
  server.handleClient(); //Handle client requests
  if (server.args() > 0)
  { // Arguments were received
    for (uint8_t i = 0; i < server.args(); i++)
    {
      if (server.argName(i) == "LED1")
      {
        if(server.arg(i) == "ON"){
          Serial.println("LED 1 ON");
          digitalWrite(led1, HIGH);
        } else {
          Serial.println("LED 1 OFF");
          digitalWrite(led1, LOW);
        }
      } else if (server.argName(i) == "LED2"){
        if(server.arg(i) == "ON"){
          Serial.println("LED 2 ON");
          digitalWrite(led2, HIGH);
        } else {
          Serial.println("LED 2 OFF");
          digitalWrite(led2, LOW);
        }
      } else if (server.argName(i) == "LED3"){
        if(server.arg(i) == "ON"){
          Serial.println("LED 3 ON");
          digitalWrite(led3, HIGH);
        } else {
          Serial.println("LED 3 OFF");
          digitalWrite(led3, LOW);
        }
      } else {
        if(server.arg(i) == "ON"){
          Serial.println("LED 4 ON");
          digitalWrite(led4, HIGH);
        } else {
          Serial.println("LED 4 OFF");
          digitalWrite(led4, LOW);
        }
      }
    }
  }
}

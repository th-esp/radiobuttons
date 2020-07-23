#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#define WLAN_SSID   "Will be redefined"
#define WLAN_PASSWORD "in next include"
#include "WLAN_Luftb.hh" // not in git

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.hostname("radiobuttons");
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle();
  delay(5);
}

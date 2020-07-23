#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#define HOSTNAME "radiobuttons"
#define OTA_PASSWORD "private"
#define WLAN_SSID   "Will be redefined"
#define WLAN_PASSWORD "in next include"
#include "WLAN_Luftb.hh" // not in git

void setup_wifi() {
  WiFi.mode(WIFI_STA);
  WiFi.hostname(HOSTNAME);
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
}

void setup_over_the_air_updates() {
    ArduinoOTA.setHostname(HOSTNAME);
    ArduinoOTA.begin();
}

void setup() {
  setup_wifi();
  setup_over_the_air_updates();
}

void loop() {
  ArduinoOTA.handle();
  delay(5);
}

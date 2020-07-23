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
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.hostname(HOSTNAME);
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
}

void setup_over_the_air_updates() {
    ArduinoOTA.setHostname(HOSTNAME);
    ArduinoOTA.begin();
}

char button_states[5] = "0000";
unsigned long button_times[4] = {0,0,0,0};
const char * const button_functions[] = {"turnoff","louder","softer","forward"};
void setup_buttons() {
  pinMode(D1, INPUT_PULLUP);
  pinMode(D2, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
  pinMode(D4, INPUT_PULLUP);
}

void setup() {
  setup_buttons();
  setup_wifi();
  setup_over_the_air_updates();
}

void loop() {
  ArduinoOTA.handle();
  delay(5);
}

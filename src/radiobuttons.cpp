#include "radiobuttons.hh"
#include "wifi.hh"
#include <ArduinoOTA.h>

wifi_t wifi;

void setup_over_the_air_updates() {
    ArduinoOTA.setHostname(wifi.get_hostname());
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
  setup_over_the_air_updates();
}

void loop() {
  ArduinoOTA.handle();
  wifi.handle();
  delay(5);
}

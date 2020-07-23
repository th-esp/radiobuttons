#include "radiobuttons.hh"
#include "wifi.hh"
#include "ota.hh"

wifi_t wifi;
ota_t ota(wifi.get_hostname());

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
}

void loop() {
  wifi.handle();
  ota.handle();
}

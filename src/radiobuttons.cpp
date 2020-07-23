#include "radiobuttons.hh"
#include "wifi.hh"
#include "ota.hh"
#include "buttons.hh"

wifi_t wifi;
ota_t ota(wifi.get_hostname());
buttons_t buttons;

void setup() {}

void loop() {
  wifi.handle();
  ota.handle();
  buttons.handle();
}

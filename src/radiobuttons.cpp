#include "radiobuttons.hh"
#include "wifi.hh"
#include "ota.hh"
#include "buttons.hh"
#include "mqtt.hh"

wifi_t wifi;
ota_t ota(wifi.get_hostname());
buttons_t buttons;
mqtt_t mqtt;

void setup() {}

void loop() {
  wifi.handle();
  ota.handle();
  auto messages = buttons.handle();
  mqtt.handle(messages);
}

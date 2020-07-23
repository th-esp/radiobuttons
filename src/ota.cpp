#include "ota.hh"

#include <ArduinoOTA.h>

ota_t::ota_t(const char * hostname) {
    ArduinoOTA.setHostname(hostname);
    ArduinoOTA.begin();
}
void ota_t::handle() {
  ArduinoOTA.handle();
}

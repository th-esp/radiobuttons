#include "wifi.hh"

#define HOSTNAME "radiobuttons"
#define WLAN_SSID   "Will be redefined"
#define WLAN_PASSWORD "in next include"
#include "WLAN_     .hh" // not in git

wifi_t::wifi_t() {
  WiFi.persistent(false);
  WiFi.mode(WIFI_STA);
  WiFi.hostname(HOSTNAME);
  WiFi.begin(WLAN_SSID, WLAN_PASSWORD);
}

void wifi_t::handle() {}

const char * wifi_t::get_hostname() const {
    return HOSTNAME;
}

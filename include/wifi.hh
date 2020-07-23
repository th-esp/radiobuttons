#ifndef WIFI_HH
#define WIFI_HH

#include <ESP8266WiFi.h>

class wifi_t {
public:
    /// connects to wireless network
    wifi_t();
    /// performs maintenance as required
    void handle();
    /// Hostname of this ESP
    const char * get_hostname() const;
};
#endif
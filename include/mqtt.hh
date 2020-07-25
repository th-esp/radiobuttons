#ifndef MQTT_HH
#define MQTT_HH

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "milliseconds.hh"

class mqtt_t {
public:
  milliseconds_t last_connection_attempt = 0;
  static constexpr milliseconds_t time_between_reconnection_attempts = 2000;
  WiFiClient espClient;
  PubSubClient client;
  mqtt_t();
  void handle(const std::vector<String>&);
};

#endif
#include "mqtt.hh"
#include "wifi.hh"

// These defines will be overwritten in the following include file.
#define MQTT_SERVER_HOST   "mosquitto.example.com"
#define MQTT_SERVER_PORT   1883
#define MQTT_CLIENT_NAME   wifi_t::get_hostname()
#define MQTT_USERNAME      "mosquitto_username"
#define MQTT_PASSWORD      "mosquitto_secret_password"
#define MQTT_DEFAULT_TOPIC MQTT_CLIENT_NAME
#include "MQTT_openhab.hh"

mqtt_t::mqtt_t() :  client(MQTT_SERVER_HOST, MQTT_SERVER_PORT, espClient) {}

void mqtt_t::handle(const std::vector<String> & messages) {
  if (millis() - last_connection_attempt > time_between_reconnection_attempts
      && ! client.connected()) {
    client.connect(MQTT_CLIENT_NAME, MQTT_USERNAME, MQTT_PASSWORD);
  } else {
    for (const String & message : messages)
      client.publish(MQTT_DEFAULT_TOPIC, message.c_str());
  }
}

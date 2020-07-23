#ifndef BUTTONS_HH
#define BUTTONS_HH
#include <Arduino.h>
class button_t {
public:
    char state = '0';
    const uint8_t pin;
    unsigned long time = 0;
    const String label;
    button_t(uint8_t pin, const String & label);
    void handle();
};
class buttons_t {
public:
    button_t buttons[4] = {{D1,"turnoff"},{D2,"louder"},{D3,"softer"},{D4,"forward"}};
    buttons_t() = default;
    void handle();
};
#endif

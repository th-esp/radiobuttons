#include "buttons.hh"

button_t::button_t(uint8_t pin, const String & label)
  : pin(pin)
  , label(label)
{
  pinMode(pin, INPUT_PULLUP);
}

void button_t::handle() {}

void buttons_t::handle() {
  for (auto & button : buttons)
    button.handle();
}

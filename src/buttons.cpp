#include "buttons.hh"

button_state_t next_state(button_state_t current_state) {
  switch (current_state) {
  case UNPRESSED: return PRESSING;
  case PRESSING:  return PRESSED;
  case PRESSED:   return RELEASING;
  case RELEASING: return UNPRESSED;
  }
}

button_t::button_t(uint8_t pin, const String & label)
  : pin(pin)
  , label(label)
{
  pinMode(pin, INPUT_PULLUP);
}

bool button_t::is_state_change_starting() const {
  bool stored_state_is_pressed = state == PRESSED;
  bool actual_state_is_pressed = digitalRead(pin) == pressed_pin_state;
  return stored_state_is_pressed != actual_state_is_pressed;
}

void button_t::init_debounce()
{
  state = next_state(state);
  last_changed_time = millis();
}

String button_t::handle_stable_state() {
  if (is_state_change_starting()) {
    init_debounce();
    // publish as a button press.
    if (state == PRESSING) 
      return label;
  }
  return "";
}

String button_t::handle_debounce() {
  if (millis() - last_changed_time > debounce_duration) {
    state = next_state(state);
  }
  return "";
}

String button_t::handle() {
  switch (state) {
  case UNPRESSED: case PRESSED:
    return handle_stable_state();
  case PRESSING: case RELEASING:
    handle_debounce();
    break;
  }
  return "";
}

std::vector<String> buttons_t::handle() {
  std::vector<String> detected_events;
  for (auto & button : buttons) {
    String event = button.handle();
    if (event.length() > 0)
      detected_events.push_back(event);
  }
  return detected_events;
}

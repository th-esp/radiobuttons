#ifndef BUTTONS_HH
#define BUTTONS_HH
#include <Arduino.h>

enum button_state_t : char {
    PRESSED='1',
    UNPRESSED='0',
    PRESSING='P',
    RELEASING='R'
};

/// Repeating sequence of button states is
/// UNPRESSED -> PRESSING -> PRESSED -> RELEASING -> ...(repeat).
/// @return the next state that follows the current state
/// @param current_state state to compute the next state from
button_state_t next_state(button_state_t current_state);

/// type for pin identifiers and pi states
typedef uint8_t pin_t;
/// Type for durations and clock times in milliseconds
typedef unsigned long int milliseconds_t;

/** The button class keeps track of the button's state and does debouncing
 * in software.  Responds to state changes of a push button connected to
 * a digital input. */
class button_t {
public:
    /// debounce duration is fixed.
    static constexpr milliseconds_t debounce_duration = 40;
    /// last known state of the button
    button_state_t state = UNPRESSED;
    /// the ARDUINO pin ID to read from, e.g. D1
    const pin_t pin;
    /// which pin state, when stable, corresponds to PRESSED
    const pin_t pressed_pin_state = LOW;
    /// Instant when the state changed last time
    milliseconds_t last_changed_time = 0;
    /// Label of the button, used for MQTT messages
    String label;

    /// Initialize new button object.
    /// @param pin The ARDUINO PIN ID of the digital pin to which the button
    ///            is connected. Constructor configures a pullup resistor for
    ///            the pin and sets it to input mode.  The physical pushbutton
    ///            will short the pin to ground when pressed.
    /// @param label Human-readable label to return from handle() when the
    ///              button is pressed.
    button_t(pin_t pin, const String & label);

    /// Manages button state update including debouncing.
    /// @return This button's label when a new button press happens.
    /// @return Empty string otherwise.
    String handle();

    /// @pre May only be called when the button state is PRESSED or UNPRESSED.
    /// @return true when the current electrical state does not match its
    ///         stored state.
    /// @return false otherwise.
    bool is_state_change_starting() const;

    /// @pre May only be called when the button state is PRESSED or UNPRESSED.
    /// To be called when a button press or a button release has just started.
    /// Advances the button's state to PRESSING or RELEASING.  Starts the
    /// debouncing timer.
    void init_debounce();

    /// @pre May only be called when the button state is PRESSED or UNPRESSED.
    /// Determines if a button press or button release is starting, and if yes,
    /// starts debouncing.
    /// @return This button's label when a new button press starts.
    /// @return Empty string otherwise.
    String handle_stable_state();

    /// @pre May only be called when the button state is PRESSING or RELEASING.
    /// Checks how much time has passed since the beginning of the debouncing
    /// and if the time exceeds debounce_duration, advances the state of this
    /// button from PRESSING to PRESSED or from RELEASEING to UNPRESSED.
    /// @return Empty string.
    String handle_debounce();


};

/// Container of multiple button objects.
class buttons_t {
public:
    /// Array with all buttons that this object manages.
    button_t buttons[4] = {{D5,"turnoff"},{D4,"louder"},{D3,"softer"},{D7,"forward"}};
    buttons_t() = default;
    /// Updates the states of all buttons.
    /// @return A vector with the labes with all buttons that experience a new
    ///         button press.  The vector will be empty when is newly pressed.
    std::vector<String> handle();
};
#endif

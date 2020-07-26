# Radiobuttons

A small project to build a panel with buttons that publish MQTT messages
that can be used to control a radio.

## How to use

Edit [src/wifi.cpp](src/wifi.cpp), adjust the line

`#include "WLAN_     .hh" // not in git`

to include a header file named after your own wireless network, containing

    #undef WLAN_SSID
    #undef WLAN_PASSWORD
    #define WLAN_SSID "The SSID of your own wireless network"
    #define WLAN_PASSWORD "The password of your own wireless network"

Edit [src/mqtt.cpp](src/mqtt.cpp), adjust the line

`#include "MQTT_openhab.hh"`

to include a header file named after your own MQTT server, containing

    #undef MQTT_SERVER_HOST 
    #undef MQTT_SERVER_PORT 
    #undef MQTT_CLIENT_NAME 
    #undef MQTT_USERNAME    
    #undef MQTT_PASSWORD    
    #undef MQTT_DEFAULT_TOPIC
    
    #define MQTT_SERVER_HOST   "Host name or IP address of your MQTT server"
    #define MQTT_SERVER_PORT   1883 // Or another port if you use another
    #define MQTT_CLIENT_NAME   "Unique name for this panel of buttons"
    #define MQTT_USERNAME      "A valid username for your MQTT server"
    #define MQTT_PASSWORD      "The password for that user"
    #define MQTT_DEFAULT_TOPIC "The MQTT topic to publish button presses"

The ESP8266 will publish the messages "turnoff", "louder", "softer", "forward"
when the corresponding buttons are pressed.  The messages and also the digital
input pins to which the buttons are connected can be changed in file
`radiobuttons.hh`. The pins that you choose should support internal pullup
resistors so that you only need buttons connecting the pins to ground and
no other external parts.  Debouncing is done in software.

## Hardware

I have used a Wemos D1 mini, a 20x14 Perfboard, 4 pushbuttons, a USB power
supply and some plywood and scrap would for making a case. See images:

![See caption below image](Pictures/01-Perfboard-Front.jpg)

Front side of perfboard.  The two header pins closest to the pushbuttons
(3V and 5V) are not soldered, too close and not needed.

---

![See caption below image](Pictures/02-Perfboard-Backside.jpg)

Back side of perfboard.  Headers for mounting the D1 mini protrude on the
back side.

---

![See caption below image](Pictures/03-D1-Mini-Headers.jpg)

Headers soldered to D1 mini allow attaching the D1 mini to the headers
on the perfboard.

---

![See caption below image](Pictures/04-Perfboard-Backside-with-D1.jpg)

D1 mounted on the perfboard.

---

![See caption below image](Pictures/05-Thickness01.jpg)

Thickness of D1 mini mounted with headers.  Need some spacer near the buttons
to create the same thickness there, transfering the force of button pushes
to the back wall of the case.

---

![See caption below image](Pictures/06-Scrap-Wood-Thickness.JPG)

A piece of scrapwood is a bit too thick and needs to be cut.

---

![See caption below image](Pictures/07-Buttons-Thickness.JPG)

Buttons protrude from perfboard, front cover cannot be nearer to perfboard than
their thickness.

---

![See caption below image](Pictures/08-Mark-Scrapwood.JPG)

Cut mark on scrapwood to create spacer.

---

![See caption below image](Pictures/09-Scrapwood-Attached.JPG)

Spacer attached to perfboard.

---

![See caption below image](Pictures/11-Plan-USB-Feedthrough.JPG)

USB cable (power supply) needs to feed through the spacer.

---

![See caption below image](Pictures/12-Feedthrough-Markings.JPG)

Cut marks on spacer.

---

![See caption below image](Pictures/13-Feedthrough-Cuts.JPG)

Cuts done to spacer.

---

![See caption below image](Pictures/14-Feedthrough-Chisel.JPG)

Chiseling out the feedthrough.

---

![See caption below image](Pictures/15-Feedthrough-Test.JPG)

Testing that the power cable fits in the new cut.

---

![See caption below image](Pictures/16-Screw-too-long.JPG)

The mounting screw is now too long.

---

![See caption below image](Pictures/17-Cut-Screw.JPG)

Cut screw.

---

![See caption below image](Pictures/18-Spacer-Held-By-Cut-Screw.JPG)

Spacer held by shortened screw.

---

![See caption below image](Pictures/19-Magnets-on-Back-Cover.JPG)

Magnets for detachable wall mounting attachet to back cover.

---

![See caption below image](Pictures/20-Magnet-Screws-Protrude.JPG)

Magnet mounting screws protrude on inside.  Will be screwed into spacer.

---

![See caption below image](Pictures/21-Glue-Dots.jpg)

Apply some glue dots to fix electronic parts on backside cover in addition
to the magnet mounting screws.

---

![See caption below image](Pictures/22-Glued-Back-Mark-Buttonholes-Front.JPG)

Mark positions for button holes in front cover.

---

![See caption below image](Pictures/23-Button-Hole-Centers.JPG)

Button hole centers.

---

![See caption below image](Pictures/24-Button-Diameter.JPG)

Diameters of button holes need to be a bit larger than the button diameters.

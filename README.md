# Irrigator

ESP8266 Arduino IDE sketch forsmall automated irrigation system: it checks every
3 mins for soil humidity and if it's less that the threshold, it launches a pump
(connected through a MOSFET) for a few secs.

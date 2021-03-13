# Irrigator

Arduino IDE sketch for small automated irrigation system for you house plant: it checks every 3 mins for soil humidity and if it's less that the threshold, it launches a pump (connected through a MOSFET) for 2 seconds. It is tested to be enough to keep your plant moisturized when you are away or if you forget to water it.

It is configured for usage with [capacitive moisture sensor](https://www.seeedstudio.com/Grove-Capacitive-Moisture-Sensor-Corrosion-Resistant.html). For usage with resistive sensor, try `irrigator_resistive.ino` sketch.

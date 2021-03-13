#define PUMP_PIN              13
#define HUMIDITY_PIN          A0
#define HUMIDITY_THRESHOLD    200 // for resistive moisture sensor

// interval between humidity probes
#define INTERVAL        60000 * 3
#define PUMP_TIME       2000

unsigned int humidity = 0;

unsigned long waitTime = 0;

void setup() {
  pinMode(PUMP_PIN, OUTPUT);
}

void loop()
{
  int humidityNow = analogRead(HUMIDITY_PIN);
  
  if(humidityNow != humidity) {
    humidity = humidityNow;
  }

  if ((waitTime == 0 || millis() - waitTime > INTERVAL) && humidity < HUMIDITY_THRESHOLD ) {
    digitalWrite(PUMP_PIN, HIGH);
    delay(PUMP_TIME);
    digitalWrite(PUMP_PIN, LOW);
    waitTime = millis();
  }
}

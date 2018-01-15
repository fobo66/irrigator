#define POMP_PIN        13
#define HUMIDITY_PIN    A0
// минимальный порог влажности почвы
#define HUMIDITY_MIN    200
// максимальный порог влажности почвы
#define HUMIDITY_MAX    800
// интервал между проверкой на полив растения
#define INTERVAL        60000 * 3   
// переменная для хранения показания влажности почвы
unsigned int humidity = 0;

// статическая переменная для хранения времени
unsigned long waitTime = 0;

void setup(void)
{
  // пин помпы в режим выхода
  pinMode(POMP_PIN, OUTPUT);
}

void loop(void)
{
  // считываем текущее показания датчика влажности почвы
  int humidityNow = analogRead(HUMIDITY_PIN);
  // если показания текущей влажности почвы
  // не равняется предыдущему запросу 
  if(humidityNow != humidity) {
    // сохраняем текущие показания влажности
    humidity= humidityNow;
  }
  // если прошёл заданный интервал времени
  // и значения датчика влажности меньше допустимой границы
  if ((waitTime == 0 || millis() - waitTime > INTERVAL) && humidity < HUMIDITY_MIN ) {
    // включаем помпу
    digitalWrite(POMP_PIN, HIGH);
    // ждём 2 секунды
    delay(2000);
    // выключаем помпу
    digitalWrite(POMP_PIN, LOW);
    // приравниваем переменной waitTime
    // значение текущего времени плюс 3 минуты 
    waitTime = millis();
  }
}

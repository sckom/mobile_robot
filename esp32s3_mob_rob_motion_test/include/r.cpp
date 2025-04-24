// #include <Arduino.h>

// #define LED 21
// hw_timer_t *My_timer = NULL;

// void IRAM_ATTR onTimer()
// {
// digitalWrite(LED, !digitalRead(LED));
// }
// void setup()
// {
// pinMode(LED, OUTPUT);
// My_timer = timerBegin(0, 80, true);
// timerAttachInterrupt(My_timer, &onTimer, true);
// timerAlarmWrite(My_timer, 1000000, true);
// timerAlarmEnable(My_timer); //Just Enable
// }

// void loop() 
// {
// }


/*
  Лабораторная работа №1. Энергонезависимая память и программный перезапуск микроконтроллера.
*/

/*
    Условная компиляция.
  Необходимо раскомментировать один из следующих макросов для запуска нужной программы.
  В один момент времени может быть раскомментирован только один макрос.
*/

// Выбор компиляции примера по теме "Программный перезапуск микроконтроллера"
//#define TASK_1_SOFTWARE_REBOOT
// Выбор компиляции примера по теме "Энергонезаисимая память"
//#define TASK_2_EEPROM

// Если выбрано компилировать проект "Программный перезапуск микроконтроллера"
#ifdef TASK_1_SOFTWARE_REBOOT

// Задержка для запуска перезагрузки
#define TIME_TO_RESTART (uint16_t)(2000)

// Начальное значение таймера
unsigned long tm_rst = 0;

/** \brief Функция для вызова перезагрузки с использованием установленной задержки
 *  \note Для изменения задержки необходимо задать новое значение макроса TIME_TO_RESTART
 *  \return None
 */
void rebooting()
{
  // Если прошло заданное время
  if((millis() - tm_rst) >= TIME_TO_RESTART)
  {
    // Вызов функции перезагрузки
    ESP.restart();
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S3!");
  tm_rst = millis();
}

void loop() {
  // Задержка выполнения инструкций программы
  delay(10); 
  // Запуск функции с инструкциями по перезагрузке микроконтроллера
  rebooting();
}

#endif

// Если выбрано компилировать проект "Энергонезаисимая память"
#ifdef TASK_2_EEPROM

// Подключения инструментов для работы с энергонезависимой памятью
#include <EEPROM.h>

#include <Wire.h>

// Указываем количество байтов, к которым будет открыт доступ чтения/записи 
#define EEPROM_SIZE 1 // Максимальное значение 512

void setup()
{
  // Инициализация UART_0 с указанной скоростью передачи данных
  Serial.begin(115200);
  // Инициализация EEPROM с указанным размером
  EEPROM.begin(EEPROM_SIZE);
}

void loop()
{
  /*
    Поддерживаемый тип данных byte, принимает значение от 0 до 255
  */
  // Значение из первой ячейки энергонезависимой памяти 
  byte data = EEPROM.read(0);
  /* Вывод значения в считанной ячейке памяти */
  Serial.print("past data: ");
  Serial.println(String(data));

  // Если значение в считанной ячейке памяти равно нулю
  if (data == 0)
  {
    // Меняем значение переменной на отличное от нуля
    data = 1;
    // Производим подготовку к фиксации данных в указанную ячейку памяти
    EEPROM.write(0, data);
    // Производим запись всех подготовленных данных по указанным ячейкам памяти
    EEPROM.commit();
    // Управление build-in RGB-led платы ESP32-S3-DevKitC-1
    neopixelWrite(38, 0x00, 0x00, 0x00);
    /* Вывод значения в считанной ячейке памяти */
    Serial.print("new data: ");
    Serial.println(String(data));
  }
  // Если значение в считанной ячейке памяти не равно нулю
  else
  {
    // Меняем значение переменной на нуль
    data = 0;
    // Производим подготовку к фиксации данных в указанную ячейку памяти
    EEPROM.write(0, data);
    // Производим запись всех подготовленных данных по указанным ячейкам памяти
    EEPROM.commit();
    // Управление build-in RGB-led платы ESP32-S3-DevKitC-1
    neopixelWrite(38, 0xFF, 0x00, 0x00);
    /* Вывод значения в считанной ячейке памяти */
    Serial.print("new data: ");
    Serial.println(String(data));
  }
  // Небольшая задержка для работы светодиода
  delay(5000);
  // Вызов функции перезагрузки
    ESP.restart();
}

#endif

#ifdef FUNC_WAKEUP
/** \brief Функция вывода причины выхода из режима глубокого сна
  \return None
*/
void print_wakeup_reason()
{
  /*
      Переменная, для хренения кода одной из причин выхода из режима 
    глубокого сна. Может принимать одно из значений перечисления esp_sleep_source_t .
  */
  esp_sleep_wakeup_cause_t wakeup_reason;

  // Получиение кода причины выхода из режима глубокого сна
  wakeup_reason = esp_sleep_get_wakeup_cause();

  // Выбор действий на основе кода причины выхода из режима глубокого сна
  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 :
      Serial.println("Wakeup caused by external signal using RTC_IO");
      break;
    case ESP_SLEEP_WAKEUP_EXT1 :
      Serial.println("Wakeup caused by external signal using RTC_CNTL");
      break;
    case ESP_SLEEP_WAKEUP_TIMER :
      Serial.println("Wakeup caused by timer");
      break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD :
      Serial.println("Wakeup caused by touchpad");
      break;
    case ESP_SLEEP_WAKEUP_ULP :
      Serial.println("Wakeup caused by ULP program");
      break;
    default :
      Serial.println("Wakeup was not caused by deep sleep: " + String(wakeup_reason));
      break;
  }
}
#endif
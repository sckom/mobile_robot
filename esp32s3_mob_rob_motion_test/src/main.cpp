/**
 * \file main.cpp
 * \author Sckom
 * \brief Основной файл программы
 * \version 0.1
 * \date 2025-02-11
 *
 * \copyright Copyright (c) 2025
 *
 */

// Подключение фенкций и данных фреймворка Arduino
#include <Arduino.h>
// Подключение библиотеки для работы веб-приложения
#include "../lib/mrp_wifi_client/inc/mrp_wifi_client.h"
// Подключение библиотеки управления движением
#include "../lib/mrp_test/inc/mrp_func_test.h"

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

// Функция предварительной настройки МК
void setup()
{
    // Установка скорости UART 115200 бит/с
    Serial.begin(115200);
    // Подключение к существующей сети WiFI
    WiFi.begin(ssid, password);
    // Ручная конфигурация подключения по WiFi для изменения DNS
    MDNS.begin(nameDNS);
    // Полный код веб-страницы
    server.on("/", handle_root);
    /* Регистрация событий (event) */
    server.on("/wheel_1", readDataWheel_1);
    server.on("/wheel_2", readDataWheel_2);
    server.on("/wheel_3", readDataWheel_3); 
    server.on("/wheel_4", readDataWheel_4);
    server.on("/cfg_wheel", reConfigDataWheels);

    // Запуск сервера
    server.begin();

    // Вывод по UART (в монитор порта, если подключено к ПК)
    Serial.println("Initing...");
    // Инициализация данных управления ДПТ
    //mDriver_func.init(&mDriver_dat, &bts7960_func);
}

// Основной цикл программы МК
void loop()
{
    // Принимать действия пользователя
    server.handleClient();
    // // Запуск вращения в одну сторону
    // mDriver_func.forward(&mDriver_dat);
    // // Запуск вращения в другую сторону
    // mDriver_func.backward(&mDriver_dat);

}
/**
 * \file mrp_wifi_client.h
 * \author your name (you\domain.com)
 * \brief 
 * \version 0.1
 * \date 2025-03-28
 * 
 * \copyright Copyright (c) 2025
 * 
 */

#ifndef MRP_WIFI_WEB_APP_TEST
#define MRP_WIFI_WEB_APP_TEST

// Для WiFi
#include <WiFi.h>
// Для веб-сервера
#include <WebServer.h>
// Смены имени в сети
#include <ESPmDNS.h>
// Энергонезависимая память
#include <EEPROM.h>
// Код для WebApp
#include "../../../include/page_webapp.h"

// Object of WebServer(HTTP port, 80 is defult)
static WebServer server(80);

/**
 * \brief Первоначальный запуск веб-страницы, отправка основного скелета веб-приложения
 * 
 */
void handle_root();

/**
 * \brief Первоначальная настройка блока select по назначению id колёс
 * 
 */
void configDataSetWeb();

/**
 * \brief Сохранение даных в энергонезависимую память
 * 
 */
void write_eeprom_data();

/**
 * \brief Считывание данных по сколости для колеса id=1
 * 
 */
void readDataWheel_1();

/**
 * \brief Считывание данных по сколости для колеса id=2
 * 
 */
void readDataWheel_2();

/**
 * \brief Считывание данных по сколости для колеса id=3
 * 
 */
void readDataWheel_3();

/**
 * \brief Считывание данных по сколости для колеса id=4
 * 
 */
void readDataWheel_4();

/**
 * \brief Считывание новых данных о позиции колеса
 * 
 */
void reConfigDataWheels();

#endif
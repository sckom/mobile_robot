/**
 * \file mrp_wifi_client.cpp
 * \author Sckom
 * \brief 
 * \version 0.1
 * \date 2025-03-28
 * 
 * \copyright Copyright (c) 2025
 * 
 */

// Заголовочный файл с инициализацией фнкций и данных
#include "../inc/mrp_wifi_client.h"



// Handle root url (/)
void handle_root()
{
    server.send(200, "text/html", HTML);
    // Время обновления веб-страницы
    delay(100);
}


void configDataSetWeb()
{
    
}

void write_eeprom_data()
{
    
}

void readDataWheel_1()
{
    String wheelSpeed = server.arg("wheel_1");
}

void readDataWheel_2()
{
    String wheelSpeed = server.arg("wheel_2");
}

void readDataWheel_3()
{
    String wheelSpeed = server.arg("wheel_3");
}

void readDataWheel_4()
{
    String wheelSpeed = server.arg("wheel_4");
}

void reConfigDataWheels()
{
    String cfg = server.arg("cfg_wheel");
}
/**
 * \file mrp_reg_pr.h
 * \author Sckom
 * \brief Функции для считывания и записи данных в EEPROM, напрямую связвны с 
 * используемым фреймворком и микроконтроллером
 * \version 0.1
 * \date 2025-06-01
 * 
 * \copyright Copyright (c) 2025
 * 
 */


#ifndef MRP_REG_PRIVATE_H
#define MRP_REG_PRIVATE_H

#include <Arduino.h>
// Энергонезависимая память
#include <EEPROM.h>

/**
 * \brief Функция инициализации данных для объекта работы с EEPROM для ESP32
 * 
 * \param max_data Размер выделенных блок в Flash-памяти для хранения данных 
 * (используется в качестве EEPROM)
 * 
 * \return None 
 */
void eeprom_begin(uint16_t max_data)
{
    EEPROM.begin(max_data);
}

/**
 * \brief Функция записи 8 бит данных в указанный адрес папяти Flash (EEPROM) 
 * 
 * \param [in] addr Адрес памяти (номер блока), где необходимо сохранить данные
 * \param [in] val Значение, которое нужно сохранить по указанному адресу
 * 
 * \return None
 */
void eeprom_write(uint16_t addr, uint16_t val)
{
    // Подготовка к выполнению записи данных
    EEPROM.write(addr, val);
    // Производение запись данных в указанную ячейкам памяти
    EEPROM.commit();
}

/**
 * \brief 
 * 
 * \param [in] addr Адрес памяти (номер блока), где необходимо сохранить данные 
 * 
 * \return byte Значение, которое хранится по указанному адресу
 */
byte eeprom_read(uint16_t addr)
{
    // Считанные данных из указанного адреса
    uint8_t val = EEPROM.read(addr);
    return val;
}

#endif // MRP_REG_PRIVATE_H
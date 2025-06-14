/**
 * \file mrp_reg_pr.h
 * \author Sckom
 * \brief Функции для считывания и записи данных в EEPROM, напрямую связаны с 
 * используемым фреймворком и микроконтроллером
 * \version 0.2
 * \date 2025-06-01
 * 
 * \copyright Copyright (c) 2025
 * 
 */


#ifndef MRP_REG_DATA_PRIVATE_H
#define MRP_REG_DATA_PRIVATE_H

// Инструменты фреймворка
#include <Arduino.h>
// Энергонезависимая память
#include <EEPROM.h>

/**
 * \brief Перечисление статус-кодов выполнения функций, напрямую связанных с 
 * используемым фреймворком и микроконтроллером
 */
typedef enum
{
    // Функция выполнена без ошибок
    EEPROM_EXEC_OK = 0,
    // Функция не выполнена, ошибка выполнения функция фреймворка
    EEPROM_EXEC_ERR = 0,
} EEPROM_EXEC;

/**
 * \brief Функция инициализации данных для объекта работы с EEPROM для ESP32
 * 
 * \param [in] max_data - Размер выделенных блок в Flash-памяти для хранения данных 
 * (используется в качестве EEPROM)
 * 
 * \return EEPROM_EXEC - Статус-код выполнения функции 
 */
EEPROM_EXEC eeprom_begin(uint16_t max_data)
{
    // Код исполнения функции
    EEPROM_EXEC err = EEPROM_EXEC::EEPROM_EXEC_OK;

    // Если функция инициализации выполнилась с ошибкой 
    if(EEPROM.begin(max_data))
    {
        err = EEPROM_EXEC::EEPROM_EXEC_ERR;
    }
    return err;
}

/**
 * \brief Функция записи 8 бит данных в указанный адрес папяти Flash (EEPROM) 
 * 
 * \param [in] addr - Адрес памяти (номер блока), где необходимо сохранить данные
 * \param [in] val - Значение, которое нужно сохранить по указанному адресу
 * 
 * \return EEPROM_EXEC - Статус-код выполнения функции
 */
EEPROM_EXEC eeprom_write(uint16_t addr, uint16_t val)
{
    // Код исполнения функции
    EEPROM_EXEC err = EEPROM_EXEC::EEPROM_EXEC_OK;

    // Подготовка к выполнению записи данных
    EEPROM.write(addr, val);
    // Если функция производения запись данных в памяти выполнилась с ошибкой
    if(EEPROM.commit())
    {
        err = EEPROM_EXEC::EEPROM_EXEC_ERR;
    }
    return err;
}

/**
 * \brief Функция чтения данных, хранящихся по указанному адресу
 * 
 * \param [in] addr - Адрес памяти (номер блока), где необходимо сохранить данные 
 * 
 * \return byte - Значение, которое хранится по указанному адресу
 */
byte eeprom_read(uint16_t addr)
{
    // Считанные данных из указанного адреса
    uint8_t val = EEPROM.read(addr);
    return val;
}



#endif // MRP_REG_PRIVATE_H
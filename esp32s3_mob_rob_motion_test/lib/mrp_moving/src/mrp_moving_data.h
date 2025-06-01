/**
 * \file mrp_moving_data.h
 * \author Sckom
 * \brief Файл содержит структуры данных и функций для взаимодействия с
 * поворотным механизмом платформы SMIF
 * \version 0.1
 * \date 2025-03-04
 * 
 * \copyright Copyright (c) 2025
 * 
 */

// Защита от множественной инициализации
#ifndef MRP_DATA_TEST_H
#define MRP_DATA_TEST_H

// Подключение фенкций и данных фреймворка Arduino
#include <Arduino.h>
// Функиции интерфейса I2C для работы с build-in RGB-LED
#include <Wire.h>
// Макросы и переменные для контроля работы SMIF 
#include "../../../include/mrp_cfg.h"

/**
 * \brief Перечисление методов подачи питания на ДПТ 
 */
typedef enum
{
    DRIVER_PWR_NO_POWER, // Нет питания двигателя
    DRIVER_PWR_L_POWER,  // Питание left
    DRIVER_PWR_R_POWER,  // Питание right
    DRIVER_PWR_ALL_POWER // Питание right и left
} DRIVER_PWR_ST;

/**
 * \brief Структура с номерами I/O МК для драйвера двигателя
 * \param l_pwm Номер PWM I/O МК для right 
 * \param r_pwm Номер PWM I/O МК для left
 * \param l_en Номер Digital I/O МК для right
 * \param r_en Номер Digital I/O МК для left
 * \param l_is Номер Analog I/O МК для right
 * \param r_is Номер Analog I/O МК для left
 */
typedef struct
{
    uint8_t l_pwm;  // Пин МК для L_PWM
    uint8_t r_pwm;  // Пин МК для R_PWM
    uint8_t l_en;   // Пин МК для L_EN
    uint8_t r_en;   // Пин МК для R_EN
    uint8_t l_is;   // Пин МК для L_IS
    uint8_t r_is;   // Пин МК для R_IS
} driver_pins;

/**
 * \brief Структура с параметрами контроллера вращения ДПТ
 * \param l_pwm ШИМ для скорости вращения
 * \param r_pwm ШИМ для скорости вращения
 * \param l_is Ток при вращении left
 * \param r_is Ток при вращении right
 * \param en Доступ питания к обмоткам двигателя
 */
typedef struct
{
    uint8_t l_pwm;    // ШИМ для скорости вращения left
    uint8_t r_pwm;    // ШИМ для скорости вращения right
    float l_is;       // Ток при вращении left
    float r_is;       // Ток при вращении right
    DRIVER_PWR_ST en; // Доступ питания к обмоткам двигателя
} motor_driver_param;

/**
 * \brief Структура функций управления контроллером вращения ДПТ
 * \param move(...) Функция выполнения вращения
 * \param stop(...) Функция выполнения остановки вращения
 */
typedef struct
{
    // Функция выполнения вращения
    void (*move)(const driver_pins*, motor_driver_param*);
    // Функция выполнения остановки вращения
    void (*stop)(const driver_pins*, motor_driver_param*);
} motor_driver_func;

/**
 * \brief Структура параметров управления двигателем
 * \param driver_pins Структура номеров I/O МК для драйвера двигателя
 * \param driver Структура параметров управления драйвером двигателя
 * \param motor_func Структура функций управления драйвером двигателя
 */
typedef struct
{
    driver_pins* driver_pin;
    motor_driver_param* driver;
    motor_driver_func* motor_func;
} motorDrivers_param;

/**
 * \brief Структура функций управления двигателем в составе поворотного 
 * механизма
 * \param init(...) Функция инициализции данных и настройки I/O
 * \param stop(...) Функция задания остановки вращения
 * \param forward(...) Функция задания запуска вращения по часовой
 * \param backward(...) Функция задания запуска вращения против часовой
 */
typedef struct
{
    // Функция инициализции данных и настройки I/O
    void (*init)(motorDrivers_param*, motor_driver_func*);
    // Функция остановки вращения
    void (*stop)(motorDrivers_param*);
    // Функция запуска вращения по часовой
    void (*forward)(motorDrivers_param*);
    // Функция запуска вращения против часовой
    void (*backward)(motorDrivers_param*);
} motorDrivers_func;

#endif
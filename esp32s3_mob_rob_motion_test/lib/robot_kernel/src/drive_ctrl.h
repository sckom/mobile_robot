/**
 * \file drive_ctrl.h
 * \author your name (you\domain.com)
 * \brief 
 * \version 0.1
 * \date 2025-06-15
 * 
 * \copyright Copyright (c) 2025
 * 
 */


#ifndef DRIVE_CTRL_H
#define DRIVE_CTRL_H

#include "mrp_moving_func.h"

/**
 * \brief Перечисление статус-кодов выполнения функций
 * движения
 */
typedef enum
{
    MV_CTRL_OK,
    MV_CTRL_ERR_DATA,
    MV_CTRL_ERR_INP_ARG,
    MV_CTRL_ERR_CALC_PARAMS,
} MOVING_CTRL_EXEC;

/**
 * \brief Структура данных верхнего уровня управлени движением 
 * 
 */
typedef struct
{
    // Значение проекции вектора движения по оси X
    int8_t vector_x;
    // Значение проекции вектора движения по оси Y
    int8_t vector_y;
    // Значение проекции вектора для движения в режиме OMNI
    int8_t vector_omni;
    // Коэффициент, задающий радиус поворота для движения без OMNI
    uint8_t turn_radius;
    // Коэффициент для скорости перемещения
    uint8_t speed_factor;
} moving_params;

/*
 Начало низкоуровных функций
*/

MOVING_CTRL_EXEC calc_drive_params(moving_params *mv_dt);
MOVING_CTRL_EXEC move(moving_params *mv_dt);

/*
 Конец низкоуровных функций
*/

/**
 * \brief Структура функций управления движением 
 * 
 */
typedef struct
{
    MOVING_CTRL_EXEC (*init)(void);
    MOVING_CTRL_EXEC (*move)(void);
    MOVING_CTRL_EXEC (*calc_move)(void);
} moving;

#endif
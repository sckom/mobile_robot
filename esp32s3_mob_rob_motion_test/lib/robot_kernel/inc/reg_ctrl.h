/**
 * @file reg_ctrl.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-06-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#ifndef REG_CONTROL_H
#define REG_CONTROL_H

#include <mrp_reg_data.h>

/**
 * \brief Структура данных с регистрами, связанными с управлением дравером 
 * двигателя мобильного робота
 */
typedef struct
{
    reg_key* reg_f_pwm;
    reg_key* reg_b_pwm;
    reg_key* reg_f_en;
    reg_key* reg_b_en;
    reg_key* reg_f_is;
    reg_key* reg_b_is;
} reg_data_wheel;

/**
 * \brief 
 * 
 */
typedef struct
{
    reg_key* reg_pid_p;
    reg_key* reg_pid_i_1;
    reg_key* reg_pid_i_2;
    reg_key* reg_pid_d_1;
    reg_key* reg_pid_d_2;
    reg_key* reg_move_rad;
} reg_data_ctr;

/**
 * \brief 
 * 
 */
typedef struct
{
    reg_data_wheel* fl_wheel;
    reg_data_wheel* fr_wheel;
    reg_data_wheel* bl_wheel;
    reg_data_wheel* br_wheel;
    reg_data_ctr* ctr_move;
} reg_data;

/* Функция для смены местами данных двух структур данных управления драйвером 
двигателя */
REG_ERROR reg_wheel_swap()
{

}

/* Функция для смены местами данных о направлении вращения для двух двигателей */
REG_ERROR reg_dir_swap()
{

}

#endif // REG_CONTROL_H
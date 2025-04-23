/**
 * @file mrp_reg_data.c
 * @author Sckom
 * @brief 
 * @version 0.1
 * @date 2025-04-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// Подключение заголовочного файла
#include "../inc/mrp_reg_data.h"

//
REG_ERROR reg_read(reg_data* regs)
{
    
}

//
REG_ERROR reg_write(byte* reg_val, reg_data* regs)
{

}

//
REG_ERROR reg_init(reg_data* regs)
{
    //
    REG_ERROR error = REG_ERROR_OK;
    // Проверка на нулевой указатель
    if(regs == NULL)
    {
        return REG_ERROR_WRONG_VAL;
    }
    else
    {
        regs = calloc(1, sizeof(reg_data));

        regs->fl_wheel.reg_f_pwm = PIN_R_PWM_1;
        regs->fl_wheel.reg_b_pwm = PIN_L_PWM_1;
    }
    // Инициализация EEPROM с указанным размером
    EEPROM.begin(EEPROM_SIZE);

    error = reg_read(regs);

    return error;
}

//
REG_ERROR reg_free(reg_data* regs)
{
    //
    REG_ERROR error = REG_ERROR_OK;
    // Проверка на нулевой указатель
    if(regs == NULL)
    {
        error = REG_ERROR_WRONG_VAL;
    }
    else{
        free(regs);
    }
    
    return error;
}

REG_ERROR reg_wheel_swap(reg_data_wheel* wheel, reg_data* regs)
{

}

// Структура данных регистров
static reg_data* regs = 0;
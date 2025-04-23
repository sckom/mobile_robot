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
REG_ERROR reg_write(reg_data* regs)
{

}

//
REG_ERROR reg_init(reg_data* regs)
{
    //
    REG_ERROR error = REG_ERROR_OK;

    if(regs == NULL)
    {
        return REG_ERROR_WRONG_VAL;
    }
    // Инициализация EEPROM с указанным размером
    EEPROM.begin(EEPROM_SIZE);

    error = reg_read(regs);

}


/**
 * \file mrp_reg_data.c
 * \author Sckom
 * \brief
 * \version 0.1
 * \date 2025-04-23
 *
 * \copyright Copyright (c) 2025
 *
 */

// Подключение заголовочного файла
#include "mrp_reg_data.h"

reg_key createRegKey(char *name, uint8_t memNum, byte value)
{
    reg_key* regs = (reg_key*)calloc(1, sizeof(reg_key));

    if ((name == NULL) || (strlen(name) > MAX_LEGHT_REG_NAME) || (memNum >= EEPROM_SIZE))
    {    
        name = strchr("None", 4);
        strcpy(regs->name, name); 
        return *regs;
    }
    else
    {
        strcpy(regs->name, name);
        regs->mem_num = memNum;
        regs->val = value;
        return *regs;
    }
}

//
byte regReadByName(reg_data *regs)
{
}

byte regReadByNum(reg_data *regs)
{
}

//
REG_ERROR regWrite(byte *reg_val, reg_data *regs)
{
}

//
REG_ERROR reg_init(reg_data *regs)
{
    //
    REG_ERROR error = REG_ERROR_OK;
    // Проверка на нулевой указатель
    if (regs == NULL)
    {
        return REG_ERROR_WRONG_VAL;
    }

    // Инициализация EEPROM с указанным размером
    EEPROM.begin(EEPROM_SIZE);
    reg_key keys[EEPROM_SIZE];
    
    keys[0] = createRegKey(NAME_DFN(PIN_R_PWM_1), 0, PIN_R_PWM_1);
    keys[1] = createRegKey(NAME_DFN(PIN_L_PWM_1), 1, PIN_L_PWM_1);
    keys[2] = createRegKey(NAME_DFN(PIN_R_EN_1), 2, PIN_R_EN_1);
    keys[3] = createRegKey(NAME_DFN(PIN_L_EN_1), 3, PIN_L_EN_1);
    keys[4] = createRegKey(NAME_DFN(PIN_R_IS_1), 4, PIN_R_IS_1);
    keys[5] = createRegKey(NAME_DFN(PIN_L_IS_1), 5, PIN_L_IS_1);
    
    keys[6] = createRegKey(NAME_DFN(PIN_R_PWM_2), 6, PIN_R_PWM_2);
    keys[7] = createRegKey(NAME_DFN(PIN_L_PWM_2), 7, PIN_L_PWM_2);
    keys[8] = createRegKey(NAME_DFN(PIN_R_EN_2), 8, PIN_R_EN_2);
    keys[9] = createRegKey(NAME_DFN(PIN_L_EN_2), 9, PIN_L_EN_2);
    keys[10] = createRegKey(NAME_DFN(PIN_R_IS_2), 10, PIN_R_IS_2);
    keys[11] = createRegKey(NAME_DFN(PIN_L_IS_2), 11, PIN_L_IS_2);
    
    keys[12] = createRegKey(NAME_DFN(PIN_R_PWM_3), 12, PIN_R_PWM_3);
    keys[13] = createRegKey(NAME_DFN(PIN_L_PWM_3), 13, PIN_L_PWM_3);
    keys[14] = createRegKey(NAME_DFN(PIN_R_EN_3), 14, PIN_R_EN_3);
    keys[15] = createRegKey(NAME_DFN(PIN_L_EN_3), 15, PIN_L_EN_3);
    keys[16] = createRegKey(NAME_DFN(PIN_R_IS_3), 16, PIN_R_IS_3);
    keys[17] = createRegKey(NAME_DFN(PIN_L_IS_3), 17, PIN_L_IS_3);
    
    keys[18] = createRegKey(NAME_DFN(PIN_R_PWM_4), 18, PIN_R_PWM_4);
    keys[19] = createRegKey(NAME_DFN(PIN_L_PWM_4), 19, PIN_L_PWM_4);
    keys[20] = createRegKey(NAME_DFN(PIN_R_EN_4), 20, PIN_R_EN_4);
    keys[21] = createRegKey(NAME_DFN(PIN_L_EN_4), 21, PIN_L_EN_4);
    keys[22] = createRegKey(NAME_DFN(PIN_R_IS_4), 22, PIN_R_IS_4);
    keys[23] = createRegKey(NAME_DFN(PIN_L_IS_4), 23, PIN_L_IS_4);
    
    keys[24] = createRegKey("CTR_PID_P", 24, 1);
    keys[25] = createRegKey("CTR_PID_I_1", 25, 0);
    keys[26] = createRegKey("CTR_PID_I_2", 26, 0);
    keys[27] = createRegKey("CTR_PID_D_1", 27, 0);
    keys[28] = createRegKey("CTR_PID_D_2", 28, 0);
    keys[29] = createRegKey(NAME_DFN(RAD_MOVE), 29, RAD_MOVE);


    return error;
}

//
REG_ERROR reg_free(reg_data *regs)
{

}

REG_ERROR reg_wheel_swap(reg_data_wheel *wheel, reg_data *regs)
{
}

REG_ERROR reg_dir_swap(reg_data_wheel *wheel, reg_data *regs)
{
}

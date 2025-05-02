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

//
reg_key* regKeyListCreate()
{
    // Массив структур с регистрами, созданным в ОЗУ с возможностью изменения выделенной памяти
    reg_key* regs = (reg_key*)calloc(1, sizeof(reg_key));
    // Массив символов, полученный преобразованием из строки
    char *name = strchr("INIT_LIST", 9);
    // Задание имени путём копирования из локальной переменной функции
    strcpy(regs->name, name);
    // Задание адресса
    regs->addr = 0;
    // Задание значения
    regs->val = 0;

    return regs;
}

//
REG_ERROR regKeyListAdd(char *name, uint8_t addr, byte val, reg_key *regs)
{
    // Код испольнения функции
    REG_ERROR error = REG_ERROR::REG_ERROR_OK;

    if ((name == NULL) || (strlen(name) > MAX_LEGHT_REG_NAME) || (addr >= EEPROM_SIZE))
    {    
        name = strchr("None", 4);
        strcpy(regs->name, name);
        // Присвоение кода ошибки
        error = REG_ERROR::REG_ERROR_WRONG_VAL;
    }
    else if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_ERROR::REG_ERROR_NULL_PTR;
    }
    else
    {
        // Количество структур reg_key
        uint8_t size = sizeof(*regs) / sizeof(reg_key);

        // Локальный массив структур для копирования
        reg_key* new_regs[(size + 1)];

        // Копирование значений в локльный массив существующих структур
        for(uint8_t i = 0; i < size; i++)
        {
            // Имя следующего регистра
            const char* n_name = regs[i].name;
            // Адресс следующего регистра
            uint8_t n_addr = regs[i].addr;
            // Значение следующего регистра
            byte n_val = regs[i].val;
            // Копирование имени
            strcpy(new_regs[i]->name, n_name);
            // Копирование адресса
            new_regs[i]->addr = n_addr;
            // Копирование значения
            new_regs[i]->val = n_val;
        }

        /* Заполнение данных нового ключа, помещённого в колнец списка */
        
        // Копирование имени
        strcpy(new_regs[size]->name, name);
        // Копирование адресса
        new_regs[size]->addr = addr;
        // Копирование значения
        new_regs[size]->val = val;

        // Меняем размер выделенной памяти
        regs = (reg_key*)realloc(regs, (size + 1) * sizeof(reg_key));
        // Во избежания утечки памяти заполняем значениями локального массива reg_key
        regs = *new_regs;
    }

    return error;
}

//
byte regReadByName(char *name, reg_data *regs)
{
}

//
byte regReadByAddr(uint8_t addr, reg_data *regs)
{
}

//
REG_ERROR regKeyListWrite(reg_key *regs)
{
    // Код испольнения функции
    REG_ERROR error = REG_ERROR_OK;

    // Проверка на нулевой указатель
    if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_ERROR::REG_ERROR_NULL_PTR;
    }
    else
    {
        // Инициализация EEPROM с указанным размером
        EEPROM.begin(EEPROM_SIZE);
        // Количество структур reg_key
        uint8_t size = sizeof(*regs) / sizeof(reg_key); 
        
        // Произведение записи данных в EEPROM микроконтроллера
        for (uint8_t i = 0; i < size; i++)
        {
            // Производим подготовку к фиксации данных в указанную ячейку памяти
            EEPROM.write(regs[i].addr, regs[i].val);
            // Производим запись всех подготовленных данных по указанным ячейкам памяти
            EEPROM.commit();
        }
    }

    return error;
}

//
REG_ERROR regKeyListRemove(uint8_t addr, reg_key* regs)
{
    // Код испольнения функции
    REG_ERROR error = REG_ERROR_OK;

    // Количество структур reg_key
    const uint8_t size = sizeof(*regs) / sizeof(reg_key);

    // Проверка на нулевой указатель
    if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_ERROR::REG_ERROR_NULL_PTR;
    }
    else if ((addr < 0) || (addr >= EEPROM_SIZE) || (addr < (size - 1)))
    {
        // Присвоение кода ошибки
        error = REG_ERROR::REG_ERROR_WRONG_VAL;
    }
    else if (addr == 0)
    {
        // Локальный массив структур для копирования
        reg_key* new_regs[(size - 1)];
        // Копирование значений в локльный массив до удаляемого ключа
        for(uint8_t i = 0; i < (size - 1); i++)
        {
            // Имя следующего регистра
            const char* name = regs[i+1].name;
            // Адресс следующего регистра
            uint8_t addr = regs[i+1].addr;
            // Значение следующего регистра
            byte val = regs[i+1].val;
            // Копирование имени
            strcpy(new_regs[i]->name, name);
            // Копирование адресса
            new_regs[i]->addr = addr;
            // Копирование значения
            new_regs[i]->val = val;
        }

        // Меняем размер выделенной памяти
        regs = (reg_key*)realloc(regs, (size - 1) * sizeof(reg_key));
        // Во избежания утечки памяти заполняем значениями локального массива reg_key
        regs = *new_regs;
    }
    else if (addr == (size - 1))
    {
        // Локальный массив структур для копирования
        reg_key* new_regs[(size - 1)];

        // Копирование значений в локльный массив до удаляемого ключа
        for(uint8_t i = 0; i < (size - 1); i++)
        {
            // Имя следующего регистра
            const char* name = regs[i].name;
            // Адресс следующего регистра
            uint8_t addr = regs[i].addr;
            // Значение следующего регистра
            byte val = regs[i].val;
            // Копирование имени
            strcpy(new_regs[i]->name, name);
            // Копирование адресса
            new_regs[i]->addr = addr;
            // Копирование значения
            new_regs[i]->val = val;
        }

        // Меняем размер выделенной памяти
        regs = (reg_key*)realloc(regs, (size - 1) * sizeof(reg_key));
        // Во избежания утечки памяти заполняем значениями локального массива reg_key
        regs = *new_regs;
    }
    else
    {
        // Локальный массив структур для копирования
        reg_key* new_regs[(size - 1)];

        // Копирование значений в локльный массив до удаляемого ключа
        for(uint8_t i = 0; i < addr; i++)
        {
            // Имя следующего регистра
            const char* name = regs[i].name;
            // Адресс следующего регистра
            uint8_t addr = regs[i].addr;
            // Значение следующего регистра
            byte val = regs[i].val;
            // Копирование имени
            strcpy(new_regs[i]->name, name);
            // Копирование адресса
            new_regs[i]->addr = addr;
            // Копирование значения
            new_regs[i]->val = val;
        }

        // Копирование значений в локльный массив после удаляемого ключа
        for(uint8_t i = addr; i < (size - 1); i++)
        {
            // Имя следующего регистра
            const char* name = regs[i+1].name;
            // Адресс следующего регистра
            uint8_t addr = regs[i+1].addr;
            // Значение следующего регистра
            byte val = regs[i+1].val;
            // Копирование имени
            strcpy(new_regs[i]->name, name);
            // Копирование адресса
            new_regs[i]->addr = addr;
            // Копирование значения
            new_regs[i]->val = val;
        }

        // Меняем размер выделенной памяти
        regs = (reg_key*)realloc(regs, (size - 1) * sizeof(reg_key));
        // Во избежания утечки памяти заполняем значениями локального массива reg_key
        regs = *new_regs;
    }

    return error;
}

//
REG_ERROR regKeyListFree(reg_key *regs)
{
    REG_ERROR error = REG_ERROR::REG_ERROR_OK;
    
    if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_ERROR::REG_ERROR_NULL_PTR;
    }
    else
    {
        // Освобождение памяти в ОЗУ
        free(regs);
    }

    return error;
}

REG_ERROR reg_wheel_swap(reg_data_wheel *wheel, reg_data *regs)
{
}

REG_ERROR reg_dir_swap(reg_data_wheel *wheel, reg_data *regs)
{
}

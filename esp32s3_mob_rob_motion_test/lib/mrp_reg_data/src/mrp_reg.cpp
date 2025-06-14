/**
 * \file mrp_reg_data.c
 * \author Sckom
 * \brief Инструкции для публичных функций библиотеки
 * \version 0.1
 * \date 2025-04-23
 *
 * \copyright Copyright (c) 2025
 *
 */

// Подключение заголовочного файла
#include "mrp_reg_pub.h"

// Фнкция для создания списка структур данных регистров
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

// Функция добаления элемента данных регистра в список регистров
REG_EXEC regKeyListAdd(char *name, uint8_t addr, byte val, reg_key *regs)
{
    // Код исполнения функции
    REG_EXEC error = REG_EXEC::REG_EXEC_OK;

    if ((name == NULL) || (strlen(name) > MAX_LEGHT_REG_NAME) || (addr >= EEPROM_SIZE))
    {    
        name = strchr("None", 4);
        strcpy(regs->name, name);
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_WRONG_VAL;
    }
    else if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_NULL_PTR;
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

// Фнкция записи данных из списка регистров в энергонезависимую память 
REG_EXEC regKeyListWrite(reg_key *regs, uint8_t addr)
{
    // Код исполнения функции
    REG_EXEC error = REG_EXEC_OK;

    // Проверка на нулевой указатель
    if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_NULL_PTR;
    }
    else
    {
        // Инициализация EEPROM с указанным размером
        eeprom_begin(EEPROM_SIZE);

        // Количество структур reg_key
        uint8_t size = sizeof(*regs) / sizeof(reg_key); 

        // Произведение записи данных в EEPROM микроконтроллера
        for (uint8_t i = 0; i < size; i++)
        {
            if (regs[i].addr == addr)
            {
                // Производим подготовку к фиксации данных в указанную ячейку памяти
                eeprom_write(regs[i].addr, regs[i].val);
            }
        }
    }
    return error;
}

// Фнкция записи данных всего списка регистров в энергонезависимую память 
REG_EXEC regKeyListWriteFull(reg_key *regs)
{
    // Код исполнения функции
    REG_EXEC error = REG_EXEC_OK;

    // Проверка на нулевой указатель
    if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_NULL_PTR;
    }
    else
    {
        // Инициализация EEPROM с указанным размером
        eeprom_begin(EEPROM_SIZE);
        // Количество структур reg_key
        uint8_t size = sizeof(*regs) / sizeof(reg_key); 
        
        // Произведение записи данных в EEPROM микроконтроллера
        for (uint8_t i = 0; i < size; i++)
        {
            // Производим подготовку к фиксации данных в указанную ячейку памяти
            eeprom_write(regs[i].addr, regs[i].val);
        }
    }

    return error;
}

// Функция удаления элемента данных регистра в список регистров
REG_EXEC regKeyListRemove(uint8_t addr, reg_key* regs)
{
    // Код исполнения функции
    REG_EXEC error = REG_EXEC_OK;

    // Количество структур reg_key
    const uint8_t size = sizeof(*regs) / sizeof(reg_key);

    // Проверка на нулевой указатель
    if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_NULL_PTR;
    }
    else if ((addr < 0) || (addr >= EEPROM_SIZE) || (addr > (size - 1)))
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_WRONG_VAL;
    }
    else if (addr == 0)
    {
        // Локальный массив структур для копирования
        reg_key* new_regs[(size)];
        // Копирование значений в локльный массив до удаляемого ключа
        for(uint8_t i = 0; i < (size); i++)
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
        regs = (reg_key*)realloc(regs, (size) * sizeof(reg_key));
        // Во избежания утечки памяти заполняем значениями локального массива reg_key
        regs = *new_regs;
    }
    else if (addr == (size))
    {
        // Локальный массив структур для копирования
        reg_key* new_regs[(size)];

        // Копирование значений в локльный массив до удаляемого ключа
        for(uint8_t i = 0; i < (size); i++)
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
        regs = (reg_key*)realloc(regs, size * sizeof(reg_key));
        // Во избежания утечки памяти заполняем значениями локального массива reg_key
        regs = *new_regs;
    }
    else
    {
        // Локальный массив структур для копирования
        reg_key* new_regs[size];

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
        for(uint8_t i = addr; i < size; i++)
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
        regs = (reg_key*)realloc(regs, (size) * sizeof(reg_key));
        // Во избежания утечки памяти заполняем значениями локального массива reg_key
        regs = *new_regs;
    }

    return error;
}

// Функция очистки памяти от списка структур данных о регистрах
REG_EXEC regKeyListFree(reg_key *regs)
{
    // Код исполнения функции
    REG_EXEC error = REG_EXEC::REG_EXEC_OK;
    
    // Проверка на нулевой указатель
    if (regs == NULL)
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_NULL_PTR;
    }
    else
    {
        // Освобождение памяти в ОЗУ
        free(regs);
    }

    return error;
}

// Функция считывания значения регистра, найденного по названию
REG_EXEC regReadByName(reg_key *regs, char *name, byte *val)
{
    // Код исполнения функции
    REG_EXEC error = REG_EXEC::REG_EXEC_OK;

    // Количество структур reg_key
    const uint8_t size = sizeof(*regs) / sizeof(reg_key);

    // Проверка на нулевой указатель
    if (regs == NULL || val == NULL)
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_NULL_PTR;
    }
    else if ((sizeof(name) < 3) || (strlen(name) > MAX_LEGHT_REG_NAME))
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_WRONG_VAL;
        return error;
    }
    else
    {
        bool found_str = false;
        // Поиск среди списка регистров в их описании аргументра-строки как подстроки
        for (uint8_t i = 0; i < size; i++)
        {
            const char* n_name = regs[i].name; 
            char *res = strstr(n_name, name);
            if (res)
            {
                *val = eeprom_read(regs[i].val);
                found_str = true;
            }
        }

        if (!found_str)
        {
            // Присвоение кода ошибки
            error = REG_EXEC::REG_EXEC_NULL_PTR;
        }
    }
    return error;
}

// Функция считывания значения регистра, найденного по адресу
REG_EXEC regReadByAddr(reg_key *regs, uint8_t addr, byte *val)
{
    // Код исполнения функции
    REG_EXEC error = REG_EXEC::REG_EXEC_OK;

    // Проверка на нулевой указатель
    if (regs == NULL || val == NULL)
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_NULL_PTR;
    }
    else if ((addr < 0) || (addr >= EEPROM_SIZE))
    {
        // Присвоение кода ошибки
        error = REG_EXEC::REG_EXEC_WRONG_VAL;
    }
    else
    {
        *val = eeprom_read(regs[addr].val);
    }
    return error;
}
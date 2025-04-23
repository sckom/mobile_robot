/**
 * \file mrp_data.cpp
 * \author Sckom
 * \brief Файл содержит описание функций (инструкции) управления 
 * поворотным механизмом SMIF
 * \version 0.1
 * \date 2025-03-04
 *
 * \copyright Copyright (c) 2025
 *
 */

// // Подключение заголовочного файла с объявлением функций и структур
// #include "../inc/mrp_func_test.h"

// /* Begin SMIF area */

// /* End SMIF area */

// // Функция выполнения вращения
// void motorMove(const driver_pins *bts7960_pins,
//                motor_driver_param *bts7960_data)
// {
//     // Если питание left активирано
//     if (bts7960_data->en == DRIVER_PWR_L_POWER)
//     {
//         // Выбор направления вращения ДПТ
//         digitalWrite(bts7960_pins->l_en, HIGH);
//         digitalWrite(bts7960_pins->r_en, LOW);
//         // Задание ШИМ-сигналов
//         analogWrite(bts7960_pins->l_pwm, bts7960_data->l_pwm);
//         analogWrite(bts7960_pins->r_pwm, 0);
//     }
//     // Если питание right активирано
//     else if (bts7960_data->en == DRIVER_PWR_R_POWER)
//     {
//         // Выбор направления вращения ДПТ
//         digitalWrite(bts7960_pins->l_en, LOW);
//         digitalWrite(bts7960_pins->r_en, HIGH);
//         // Задание ШИМ-сигналов
//         analogWrite(bts7960_pins->l_pwm, 0);
//         analogWrite(bts7960_pins->r_pwm, bts7960_data->r_pwm);
//     }
//     // Если питание left и right активирано
//     else if (bts7960_data->en == DRIVER_PWR_ALL_POWER)
//     {
//         // Выбор направления вращения ДПТ
//         digitalWrite(bts7960_pins->l_en, HIGH);
//         digitalWrite(bts7960_pins->r_en, HIGH);
//         // Задание ШИМ-сигналов
//         analogWrite(bts7960_pins->l_pwm, 0);
//         analogWrite(bts7960_pins->r_pwm, 0);
//     }
//     // Если питание не активирано
//     else if (bts7960_data->en == DRIVER_PWR_NO_POWER)
//     {
//         // Выбор направления вращения ДПТ
//         digitalWrite(bts7960_pins->l_en, LOW);
//         digitalWrite(bts7960_pins->r_en, LOW);
//         // Задание ШИМ-сигналов
//         analogWrite(bts7960_pins->l_pwm, 0);
//         analogWrite(bts7960_pins->r_pwm, 0);
//     }
//     // В случае некорректных данных 
//     else
//     {
//         // Ассемблерная вставка “Nо OPeration“, холостой такт процессора
//         asm("nop"); // Пропуск времени t = 1 / F_CPU, (секунд)
//     }
// }

// // Функция выполнения остановки вращения
// void motorStop(const driver_pins *bts7960_pins,
//                motor_driver_param *bts7960_data)
// {
//     // Питание обмоток ДПТ не активирано
//     bts7960_data->en = DRIVER_PWR_NO_POWER;    
//     // Выбор направления вращения ДПТ
//     digitalWrite(bts7960_pins->l_en, LOW);
//     digitalWrite(bts7960_pins->r_en, LOW);
//     // Задание ШИМ-сигналов 
//     bts7960_data->l_pwm = 0;
//     bts7960_data->r_pwm = 0;
//     analogWrite(bts7960_pins->l_pwm, bts7960_data->l_pwm);
//     analogWrite(bts7960_pins->r_pwm, bts7960_data->r_pwm);
// }

// // Функция инициализции данных и настройки I/O
// void driversInit(motorDrivers_param *moveData, motor_driver_func *moveFunc)
// {
//     // Настройка работы I/O, используемых для контроллера ДПТ
//     pinMode(moveData->driver_pin->l_pwm, OUTPUT);
//     pinMode(moveData->driver_pin->r_pwm, OUTPUT);
//     // Настройка разрешения в битах для сигнала ШИМ
//     analogWriteResolution(8);
//     // Настройка частоты сигнала ШИМ
//     analogWriteFrequency(25000U);

//     /* Begin SMIF area */

//     // Считывание состояния концевиков поворотного механизма
//     // caseOpenSt = digitalRead(0);
//     // caseCloseSt = digitalRead(0);

//     // Настройка работы I/O, используемых для контроля SMIF
//     // pinMode(SMIF_SWITCH_CASE_OPEN, INPUT_PULLDOWN);
//     // pinMode(SMIF_SWITCH_CASE_CLOSE, INPUT_PULLDOWN);
//     // pinMode(SMIF_SWITCH_CASE_DETECT, INPUT_PULLDOWN);

//     /* End SMIF area */

//     // Включение buid-in RGB-LED 
//     neopixelWrite(48, 0x00, 0xFF, 0x00);
// }

// // Функция задания остановки вращения
// void driversStop(motorDrivers_param *moveData)
// {
//     // Структура параметров I/O
//     driver_pins *pins = moveData->driver_pin;
//     // Структура параметров контроллера ДПТ
//     motor_driver_param *dr_par = moveData->driver;
//     // Включение buid-in RGB-LED 
//     neopixelWrite(48, 0xFF, 0x00, 0x00);
//     // Вывод по UART (в монитор порта, если подключено к ПК)
//     Serial.println("Was stoped...");
//     // Запуска процесса остановки работы ДПТ
//     moveData->motor_func->stop(pins, dr_par);
//     // Сохранение изменений в структуру параметров
//     moveData->driver = dr_par;

    
// }

// // Функция задания запуска вращения по часовой
// void driversForward(motorDrivers_param *moveData)
// {   
//     // Считывание состояния концевиков поворотного механизма
//     // caseOpenSt = digitalRead(SMIF_SWITCH_CASE_OPEN);
//     // caseCloseSt = digitalRead(SMIF_SWITCH_CASE_CLOSE);

//     // Условие для запуска вращения вала ДПТ
//     if (caseOpenSt == 0 && caseCloseSt == 1)
//     {
//         // Структура параметров I/O
//         driver_pins *pins = moveData->driver_pin;
//         // Структура параметров контроллера ДПТ
//         motor_driver_param *dr_par = moveData->driver;
//         // Установка коэф. заполнения импулься ШИМ
//         dr_par->r_pwm = SMIF_MAX_PWM_DRIVER;
//         // Установка сигнала EN для вращения по часовой
//         dr_par->en = DRIVER_PWR_R_POWER;

//         /* Begin SMIF area */

//         // Включение buid-in RGB-LED 
//         neopixelWrite(48, 0xFF, 0x00, 0xFF);
//         // Запуск вращения ДПТ
//         moveData->motor_func->move(pins, dr_par);

//         while (true)
//         {
//             // Считывание состояния концевиков поворотного механизма
//             caseOpenSt = digitalRead(SMIF_SWITCH_CASE_OPEN);
//             caseCloseSt = digitalRead(SMIF_SWITCH_CASE_CLOSE);

//             // Вывод по UART (в монитор порта, если подключено к ПК)
//             Serial.print("Forward moving, stop: ");
//             // Вывод по UART (в монитор порта, если подключено к ПК)
//             Serial.println(String(caseOpenSt));

//             // Условие окончания работы ДПТ
//             if (caseOpenSt == 1 && caseCloseSt == 0)
//             {
//                 // Запуска процесса остановки работы ДПТ
//                 moveData->motor_func->stop(pins, dr_par);
//                 break;
//             }
//         }

//         // Сохранение изменений в структуру параметров
//         moveData->driver = dr_par;

//         /* End SMIF area */
//     }
//     else
//     {
//         // Ассемблерная вставка “Nо OPeration“, холостой такт процессора
//         asm("nop"); // Пропуск времени t = 1 / F_CPU, (секунд)
//     }
// }

// // Функция задания запуска вращения против часовой
// void driversBackward(motorDrivers_param *moveData)
// {
//     // Считывание состояния концевиков поворотного механизма
//     caseOpenSt = digitalRead(SMIF_SWITCH_CASE_OPEN);
//     caseCloseSt = digitalRead(SMIF_SWITCH_CASE_CLOSE);

//     // Условие для запуска вращения вала ДПТ
//     if (caseOpenSt == 1 && caseCloseSt == 0)
//     {
//         // Структура параметров I/O
//         driver_pins *pins = moveData->driver_pin;
//         // Структура параметров контроллера ДПТ
//         motor_driver_param *dr_par = moveData->driver;
//         // Установка коэф. заполнения импулься ШИМ
//         dr_par->l_pwm = SMIF_MAX_PWM_DRIVER;
//         // Установка сигнала EN для вращения против часовой
//         dr_par->en = DRIVER_PWR_L_POWER;

//         /* Begin SMIF area */

//         // Включение buid-in RGB-LED 
//         neopixelWrite(48, 0xFF, 0xFF, 0x00);
//         // Запуск вращения ДПТ
//         moveData->motor_func->move(pins, dr_par);

//         while (true)
//         {
//             // Считывание состояния концевиков поворотного механизма
//             caseOpenSt = digitalRead(SMIF_SWITCH_CASE_OPEN);
//             caseCloseSt = digitalRead(SMIF_SWITCH_CASE_CLOSE);
//             // Вывод по UART (в монитор порта, если подключено к ПК)
//             Serial.print("Backward moving, stop: ");
//             // Вывод по UART (в монитор порта, если подключено к ПК)
//             Serial.println(String(caseCloseSt));
//             // Условие окончания работы ДПТ
//             if (caseOpenSt == 0 && caseCloseSt == 1)
//             {
//                 // Запуска процесса остановки работы ДПТ
//                 moveData->motor_func->stop(pins, dr_par);
//                 break;
//             }
//         }

//         // Сохранение изменений в структуру параметров
//         moveData->driver = dr_par;

//         /* End SMIF area */
//     }
//     else
//     {
//         // Ассемблерная вставка “Nо OPeration“, холостой такт процессора
//         asm("nop"); // Пропуск времени t = 1 / F_CPU, (секунд)
//     }
// }
/**
 * \file smif_cfg.h
 * \author Sckom
 * \brief Файл содержит настраиваемые параметры, относящиеся непостредственно
 * к "функционалу" контроллеров вращения ДПТ.
 * Уканы переменные для хранения состояния работы концевиков с асинхронным доступом.
 * \version 0.1
 * \date 2025-03-04
 * 
 * \copyright Copyright (c) 2025
 * 
 */

// Защита от множественной инициализации
#ifndef MRP_CONFIG_H
#define MRP_CONFIG_H


/**
 * \brief Перечисление всех GPIO, к которые используются для взаимодействия 
 * с драйверами двигателей мобильного робота
 */
enum DRIVE_PINS 
{
    PIN_R_PWM_1 = 46,
    PIN_L_PWM_1 = 9,
    PIN_R_EN_1 = 10,
    PIN_L_EN_1 = 11,
    PIN_R_IS_1 = 12,
    PIN_L_IS_1 = 13,

    PIN_R_PWM_2 = 6,
    PIN_L_PWM_2 = 7,
    PIN_R_EN_2 = 15,
    PIN_L_EN_2 = 16,
    PIN_R_IS_2 = 17,
    PIN_L_IS_2 = 18,

    PIN_R_PWM_3 = 37,
    PIN_L_PWM_3 = 36,
    PIN_R_EN_3 = 35,
    PIN_L_EN_3 = 45,
    PIN_R_IS_3 = 48,
    PIN_L_IS_3 = 47,

    PIN_R_PWM_4 = 1,
    PIN_L_PWM_4 = 42,
    PIN_R_EN_4 = 41,
    PIN_L_EN_4 = 40,
    PIN_R_IS_4 = 39,
    PIN_L_IS_4 = 38,
};

/**
 * \brief Перечисление параметров управления движением мобильного робота 
 * 
 */
enum MRP_PARAMS
{
    CTRL_PID_P = 0,
    CTRL_PID_I_1 = 0,
    CTRL_PID_I_2 = 0,
    CTRL_PID_D_1 = 0,
    CTRL_PID_D_2 = 0,
    RAD_MOVE = 1,
};


/*
    Макросы для указания I/O МК под управления котроллером
 вращения ДПТ (BTS7960)
*/

// Сигнал PWM для вращения по часовой драйвера 1
#define PIN_R_PWM_1     (DRIVE_PINS::PIN_R_PWM_1)
// Сигнал PWM для вращения против часовой драйвера 1
#define PIN_L_PWM_1     (DRIVE_PINS::PIN_L_PWM_1)
// Сигнал EN для вращения по часовой драйвера 1
#define PIN_R_EN_1      (DRIVE_PINS::PIN_R_EN_1)
// Сигнал EN для вращения против часовой драйвера 1     
#define PIN_L_EN_1      (DRIVE_PINS::PIN_L_EN_1)
// Сигнал IS при вращении по часовой драйвера 1
#define PIN_R_IS_1      (DRIVE_PINS::PIN_R_IS_1)
// Сигнал IS при вращении против часовой драйвера 1
#define PIN_L_IS_1      (DRIVE_PINS::PIN_L_IS_1)

// Сигнал PWM для вращения по часовой драйвера 2
#define PIN_R_PWM_2     (DRIVE_PINS::PIN_R_PWM_2)
// Сигнал PWM для вращения против часовой драйвера 2
#define PIN_L_PWM_2     (DRIVE_PINS::PIN_L_PWM_2)
// Сигнал EN для вращения по часовой драйвера 2
#define PIN_R_EN_2      (DRIVE_PINS::PIN_R_EN_2)
// Сигнал EN для вращения против часовой драйвера 2
#define PIN_L_EN_2      (DRIVE_PINS::PIN_L_EN_2)
// Сигнал IS при вращении по часовой драйвера 2
#define PIN_R_IS_2      (DRIVE_PINS::PIN_R_IS_2)
// Сигнал IS при вращении против часовой драйвера 2
#define PIN_L_IS_2      (DRIVE_PINS::PIN_L_IS_2)

// Сигнал PWM для вращения по часовой драйвера 3
#define PIN_R_PWM_3     (DRIVE_PINS::PIN_R_PWM_3)
// Сигнал PWM для вращения против часовой драйвера 3
#define PIN_L_PWM_3     (DRIVE_PINS::PIN_L_PWM_3)
// Сигнал EN для вращения по часовой драйвера 3
#define PIN_R_EN_3      (DRIVE_PINS::PIN_R_EN_3)
// Сигнал EN для вращения против часовой драйвера 3
#define PIN_L_EN_3      (DRIVE_PINS::PIN_L_EN_3)
// Сигнал IS при вращении по часовой драйвера 3
#define PIN_R_IS_3      (DRIVE_PINS::PIN_R_IS_3)
// Сигнал IS при вращении против часовой драйвера 3
#define PIN_L_IS_3      (DRIVE_PINS::PIN_L_IS_3)

// Сигнал PWM для вращения по часовой драйвера 4
#define PIN_R_PWM_4     (DRIVE_PINS::PIN_R_PWM_4)
// Сигнал PWM для вращения против часовой драйвера 4
#define PIN_L_PWM_4     (DRIVE_PINS::PIN_L_PWM_4)
// Сигнал EN для вращения по часовой драйвера 4
#define PIN_R_EN_4      (DRIVE_PINS::PIN_R_EN_4)
// Сигнал EN для вращения против часовой драйвера 4
#define PIN_L_EN_4      (DRIVE_PINS::PIN_L_EN_4)
// Сигнал IS при вращении по часовой драйвера 4
#define PIN_R_IS_4      (DRIVE_PINS::PIN_R_IS_4)
// Сигнал IS при вращении против часовой драйвера 4
#define PIN_L_IS_4      (DRIVE_PINS::PIN_L_IS_4)

/*
    Макросы для указания I/O МК под управления движением мобильного робота
*/

// Радиус поврота при движении по дуге
#define RAD_MOVE    (MRP_PARAMS::RAD_MOVE)

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif
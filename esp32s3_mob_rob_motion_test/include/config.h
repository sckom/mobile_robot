/**
 * \file config.h
 * \author your name (you\domain.com)
 * \brief 
 * \version 0.1
 * \date 2025-03-12
 * 
 * \copyright Copyright (c) 2025
 * 
 */

#ifndef MOBILE_ROBOT_CONFIG_H
#define MOBILE_ROBOT_CONFIG_H

#include <Arduino.h>
#include <Update.h>
#include "FS.h"
#include "FFat.h"
#include "SPIFFS.h"

// ; PlatformIO Project Configuration File
// ;
// ;   Build options: build flags, source filter
// ;   Upload options: custom upload port, speed and extra flags
// ;   Library options: dependencies, extra library storages
// ;   Advanced options: extra scripting
// ;
// ; Please visit documentation for the other options and examples
// ; https://docs.platformio.org/page/projectconf.html

// ; Env name 
// [env:esp32-s3-devkitc-1]
// ; Platform MCU
// platform = espressif32
// ; Name Dev-board is used for base
// board = esp32-s3-devkitc-1
// ; Using microcontroller
// board_build.mcu = esp32s3
// ; Frequence CPU in SoC-module ESP32S3
// board_build.f_cpu = 240000000U
// ; Used Framework
// framework = arduino
// ; Speed to print COM-port
// monitor_speed = 115200
// ; ; Custom FLASH wire mode
// ; board_build.arduino.memory_type = opi_opi
// ; ; Custom FLASH wire mode
// ; board_build.flash_mode = opi
// ; ; Custom PSRAM wire mode
// ; board_build.psram_type = opi
// ; ; Custom FLASH size
// ; board_upload.flash_size = 16MB
// ; ; Custom maximum program size
// ; board_upload.maximum_size = 16777216
// ; ; Configure by flag buil-in SoC PSRAM
// ; board_build.extra_flags = 
// ;   -D BOARD_HAS_PSRAM







#endif
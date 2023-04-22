/**
 * @file key.h
 * @author Neolux Lee (neolux.lee@gmail.com)
 * @brief Key function for STM32F103VET6
 * @version 0.1
 * @date 2023-04-20
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"
#include "stdio.h"

#define __KEY_DEBUG

#ifdef __KEY_DEBUG

#define key_info(format, ...) printf("[key.c] info:  " format "\r\n", ##__VA_ARGS__)
#define key_debug(format, ...) printf("[key.c] debug: " format "\r\n", ##__VA_ARGS__)
#define key_error(format, ...) printf("[key.c] error: " format "\r\n", ##__VA_ARGS__)
#else

#define key_info(format, ...)
#define key_debug(format, ...)
#define key_error(format, ...)
#endif

#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)

#define KEY1_PRESSED 1
#define KEY2_PRESSED 2
#define NONE_PRESSED 0

/**
 * @brief Function for key scan
 *
 * @param mode 0 支持连续按键，1 支持单次按键
 * @return uint8_t
 */
uint8_t KEY_Scan(int mode);

#endif

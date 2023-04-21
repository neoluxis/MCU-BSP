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
#include "stm32f1xx_hal.h"

#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define KEY2 HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)

#define KEY1_PRESSED 1
#define KEY2_PRESSED 2
#define NONE_PRESSED 0

/**
 * @brief 扫描按键
 *
 * @param mode 0, 不支持连按; 1, 支持连按
 * @return uint8_t
 */
uint8_t KEY_Scan(int mode);

#endif

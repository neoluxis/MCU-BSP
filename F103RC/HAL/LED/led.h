//
// Created by neolux on 23-4-3.
//

#ifndef STARTLED_LED_H
#define STARTLED_LED_H

#include "main.h"

#define LED0_ON() HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET)
#define LED0_OFF() HAL_GPIO_WritePin(LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET)
#define LED0_TOG() HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin)
#define LED1_ON() HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET)
#define LED1_OFF() HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET)
#define LED1_TOG() HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin)

void LED_Init(void);

#endif //STARTLED_LED_H

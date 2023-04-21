//
// Created by neolux on 23-4-3.
//

#ifndef STARTLED_KEY_H
#define STARTLED_KEY_H

#include "main.h"

// if defined, the key 2 will be used as system wakeup key
//#define ENA_SYS_WKUP

// read keys
#define KEY0 HAL_GPIO_ReadPin(KEY0_GPIO_Port, KEY0_Pin)
#define KEY1 HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)
#define WKUP HAL_GPIO_ReadPin(WK_UP_GPIO_Port, WK_UP_Pin)

// key value
#define NONE_PRES 0
#define KEY0_PRES 1
#define KEY1_PRES 2
#define WKUP_PRES 3

void KEY_Init(void);
uint8_t KEY_Scan(uint8_t mode);

#endif //STARTLED_KEY_H

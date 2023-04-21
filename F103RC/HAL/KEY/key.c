//
// Created by neolux on 23-4-3.
//

#include "key.h"

#ifdef ENA_SYS_WKUP

void KEY_Init(void) {}

#endif

#ifndef ENA_SYS_WKUP

void KEY_Init(void) {}

#endif

#ifdef ENA_SYS_WKUP

// 此时， WK_UP 作为系统唤醒按键，不需要读取
/**
 * @brief 读取按键值
 * @param mode 0: 不支持连按; 1: 支持连按
 * @return
 */
uint8_t KEY_Scan(uint8_t mode) {
    static uint8_t key_up = 1; // 按键按松开标志
    if (mode) key_up = 1; // 支持连按
    if (key_up) {
        if (KEY0 == 0 || KEY1 == 0) {
            HAL_Delay(5); // 去抖动
            if (KEY0 == 0) {
                key_up = 0;
                return KEY0_PRES;
            } else if (KEY1 == 0) {
                key_up = 0;
                return KEY1_PRES;
            }
        }
    } else if (KEY0 == 1 && KEY1 == 1) {
        key_up = 1;
    }
    return NONE_PRES;
}

#endif

#ifndef ENA_SYS_WKUP

// 此时， WK_UP 作为普通按键，需要读取
/**
 * @brief 读取按键值
 * @param mode 0: 不支持连按; 1: 支持连按
 * @return
 */
uint8_t KEY_Scan(uint8_t mode) {
    static uint8_t key_up = 1; // 按键按松开标志
    if (mode) key_up = 1; // 支持连按
    if (key_up) {
        if (KEY0 == 0 || KEY1 == 0 || WKUP == 1) {
            HAL_Delay(5); // 去抖动

            if (KEY0 == 0) {
                key_up = 0;
                return KEY0_PRES;
            } else if (KEY1 == 0) {
                key_up = 0;
                return KEY1_PRES;
            } else if (WKUP == 1) {
                key_up = 0;
                return WKUP_PRES;
            }
        }
    } else if (KEY0 == 1 && KEY1 == 1 && WKUP == 0) {
        key_up = 1;
    }
    return NONE_PRES;
}

#endif
#include "key.h"

uint8_t KEY_Scan(int mode)
{
    int static key_up = 1; // 按键按松开标志
    if (mode)
    {
        key_up = 1; // 支持连续按键
        key_info("Continuous scanning enabled");
    }
    else
    {
        key_info("Continuous scanning disabled");
    }
    if (key_up)
    {
        if (KEY1 == 1 || KEY2 == 1)
        {
            HAL_Delay(5);
            key_up = 0;
            if (KEY1 == 1)
            {
                key_info("Key 1 pressed. ");
                return KEY1_PRESSED;
            }
            else if (KEY2 == 1)
            {
                key_info("Key 2 pressed. ");
                return KEY2_PRESSED;
            }
        }
    }
    else
    {
        if (KEY1 == 0 && KEY2 == 0)
            key_up = 1;
    }
    key_info("No key pressed. ");
    return NONE_PRESSED;
}

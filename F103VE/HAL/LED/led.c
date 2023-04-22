#include "led.h"

#ifdef LED_PWM_OUT

void LED_RGB(uint8_t r, uint8_t g, uint8_t b)
{
    if (r > 255)
        r = 0;
    if (g > 255)
        g = 0;
    if (b > 255)
        b = 0;
    TIM3->CCR2 = r;
    TIM3->CCR3 = g;
    TIM3->CCR4 = b;
    led_info("Set LED colour to R: %03d, G: %03d, B: %03d", r, g, b);
}

void LED_Hex(uint32_t hex)
{
    if (hex > 0xFFFFFF)
        hex = 0;
    TIM3->CCR2 = (hex >> 16) & 0xFF;
    TIM3->CCR3 = (hex >> 8) & 0xFF;
    TIM3->CCR4 = hex & 0xFF;
    led_info("Set LED colour to 0x%06X", hex);
}

#endif /* defined LED_PWM_OUT */

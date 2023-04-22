/**
 * @file led.h
 * @author Neolux Lee (neolux.lee@gmail.com)
 * @brief LED control function for STM32F103VET6
 * @version 0.1
 * @date 2023-04-20
 *
 * @note If set the GPIO Port/Pin to GPIO_Output, the color can't be ajusted by RGB or Hex. Use the ON/OFF/Toggle function instead.
 * @note If set the GPIO Port/Pin to PWM Output, don't use the ON/OFF/Toggle function, use the RGB or Hex function instead.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __LED_H__
#define __LED_H__

#include "main.h"
#include "stdio.h"

#define __LED_DEBUG

#ifdef __LED_DEBUG

#define led_info(format, ...) printf("[led.c] info:  " format "\r\n", ##__VA_ARGS__)
#define led_debug(format, ...) printf("[led.c] debug: " format "\r\n", ##__VA_ARGS__)
#define led_error(format, ...) printf("[led.c] error: " format "\r\n", ##__VA_ARGS__)
#else

#define led_info(format, ...)
#define led_debug(format, ...)
#define led_error(format, ...)
#endif

#define LED_GPIO_OUT // comment this line if you use pwm, uncomment this line if you use gpio output
#define LED_PWM_OUT  // comment this line if you use gpio output, uncomment this line if you use pwm

#ifdef LED_GPIO_OUT

#define LED_R_ON() HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_RESET)
#define LED_R_OFF() HAL_GPIO_WritePin(LED_R_GPIO_Port, LED_R_Pin, GPIO_PIN_SET)
#define LED_R_TOGGLE() HAL_GPIO_TogglePin(LED_R_GPIO_Port, LED_R_Pin)

#define LED_G_ON() HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_RESET)
#define LED_G_OFF() HAL_GPIO_WritePin(LED_G_GPIO_Port, LED_G_Pin, GPIO_PIN_SET)
#define LED_G_TOGGLE() HAL_GPIO_TogglePin(LED_G_GPIO_Port, LED_G_Pin)

#define LED_B_ON() HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_RESET)
#define LED_B_OFF() HAL_GPIO_WritePin(LED_B_GPIO_Port, LED_B_Pin, GPIO_PIN_SET)
#define LED_B_TOGGLE() HAL_GPIO_TogglePin(LED_B_GPIO_Port, LED_B_Pin)

#endif /* LED GPIO Out functions */

#ifdef LED_PWM_OUT

/**
 * @brief LED control function
 *
 * @param r Red.    (0~255)(00H~FFH), 0 is off, 255 is on, out of range is invalid, set to 0
 * @param g Green.  (0~255)(00H~FFH), 0 is off, 255 is on, out of range is invalid, set to 0
 * @param b Blue.   (0~255)(00H~FFH), 0 is off, 255 is on, out of range is invalid, set to 0
 */
void LED_RGB(uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief LED control function
 *
 * @param hex Hexadecimal color code. (0x000000~0xFFFFFF)(000000H~FFFFFFH), out of range is invalid, set to 0
 */
void LED_Hex(uint32_t hex);

#endif /* defined LED_PWM_OUT */

#endif

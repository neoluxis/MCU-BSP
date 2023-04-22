/**
 * @file uart.h
 * @author Neolux Lee <neolux.lee@gmail.com>
 * @brief 
 * @version 0.1
 * @date 2023-04-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef __UART_H__
#define __UART_H__

#include "main.h"
#include "stdio.h"
#include "usart.h"

// #define __UART_DEBUG
#define print(format, ...) printf(format "\r\n", ##__VA_ARGS__)

#ifdef __UART_DEBUG

#define uart_info(format, ...) printf("[uart.c] info:  " format "\r\n", ##__VA_ARGS__)
#define uart_debug(format, ...) printf("[uart.c] debug: " format "\r\n", ##__VA_ARGS__)
#define uart_error(format, ...) printf("[uart.c] error: " format "\r\n", ##__VA_ARGS__)
#else

#define uart_info(format, ...)
#define uart_debug(format, ...)
#define uart_error(format, ...)
#endif

int fputc(int ch, FILE *f);
int fgetc(FILE *f);

#endif /* __UART_H__ */

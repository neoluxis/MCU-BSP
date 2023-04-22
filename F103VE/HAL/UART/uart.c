#include "uart.h"

// 重定向c库函数printf到串口DEBUG_USART，重定向后可使用printf函数
int fputc(int ch, FILE *f)
{
    uint8_t buf[1] = {ch};
    /* 发送一个字节数据到串口DEBUG_USART */
    HAL_UART_Transmit(&huart1, buf, 1, 2);
    return (ch);
}

// 重定向c库函数scanf到串口DEBUG_USART，重写向后可使用scanf、getchar等函数
int fgetc(FILE *f)
{
    int ch;
    HAL_UART_Receive(&huart1, (uint8_t *)&ch, 1, 1000);
    return (ch);
}

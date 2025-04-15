#ifndef UART_H
#define UART_H
#include "stm32f407xx.h"
void uart_init(void);
void uart_transmit_string(const char* str);
void transmit_tim_cnt(void);

#endif

#ifndef RNG.H
#define RNG.H

#include "stm32f407xx.h"

void rng_init();
uint32_t rng_get_random(void);
uint32_t generate_random(void);

#endif
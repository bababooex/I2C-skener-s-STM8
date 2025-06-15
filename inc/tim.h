#include "delay.h"
uint16_t i;
void delay_mss(uint16_t ms) {
			for (i = 0; i < ms; i++) {
        _delay_us(1000);
    }
}

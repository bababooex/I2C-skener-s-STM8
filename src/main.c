#include "stm8s.h"
#include "stm8_hd44780.h"
#include "sw_i2c.h"
#include "stdio.h"
#include "delay.h"
char buffer[16];
int addr;
uint8_t i2c_device_exists(uint8_t address);

uint8_t i2c_device_exists(uint8_t address) {
    SW_I2C_start();
    SW_I2C_write((address << 1));
    if (SW_I2C_wait_ACK() == 0) {
        SW_I2C_stop();
        return 1;
    }
    SW_I2C_stop();
    return 0;
}

void main(void) {
    lcd_init();
    SW_I2C_init();

    lcd_clear();
    lcd_gotoxy(0, 0);
    lcd_puts("Skenuji I2C...");
    for (addr = 1; addr < 127; addr++) {
        if (i2c_device_exists(addr)) {
						lcd_clear();
						lcd_gotoxy(0, 0);
						sprintf(buffer, "I2C Adresa: 0x%02X", addr);
						lcd_puts(buffer);
						while (1);
				}
    }
    lcd_clear();
    lcd_gotoxy(0, 0);
    lcd_puts("Slave nenalezen");
    while (1);
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


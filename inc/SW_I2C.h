#include "stm8s.h"
#include "delay.h"
//piny jsou nastaveny podle potřeby, ne všechny porty jsou ale vhodné pro účely této knihovny!
#define SW_I2C_port              GPIOA
#define SDA_pin                  GPIO_PIN_1
#define SCL_pin                  GPIO_PIN_2
//Pull-UP rezistor pouze na SDA_pin!
#define SW_I2C_OUT()             do{GPIO_DeInit(SW_I2C_port); GPIO_Init(SW_I2C_port, SDA_pin, GPIO_MODE_OUT_PP_LOW_FAST); GPIO_Init(SW_I2C_port, SCL_pin, GPIO_MODE_OUT_PP_LOW_FAST);}while(0)
#define SW_I2C_IN()              do{GPIO_DeInit(SW_I2C_port); GPIO_Init(SW_I2C_port, SDA_pin, GPIO_MODE_IN_FL_NO_IT); GPIO_Init(SW_I2C_port, SCL_pin, GPIO_MODE_OUT_PP_LOW_FAST);}while(0)
#define SDA_HIGH()               GPIO_WriteHigh(SW_I2C_port, SDA_pin)
#define SDA_LOW()                GPIO_WriteLow(SW_I2C_port, SDA_pin)
#define SCL_HIGH()               GPIO_WriteHigh(SW_I2C_port, SCL_pin)
#define SCL_LOW()                GPIO_WriteLow(SW_I2C_port, SCL_pin)
#define SDA_IN()                 GPIO_ReadInputPin(SW_I2C_port, SDA_pin)
#define I2C_ACK                  0xFF
#define I2C_NACK                 0x00
#define I2C_timeout              1000
//sekvence pro I2C, tzn. start. stop, zápis, čtení, acknowledgement a negative acknowledgement
void SW_I2C_init(void);
void SW_I2C_start(void);
void SW_I2C_stop(void);
unsigned char SW_I2C_read(unsigned char ack);
void SW_I2C_write(unsigned char value);
void SW_I2C_ACK_NACK(unsigned char mode);
unsigned char SW_I2C_wait_ACK(void);

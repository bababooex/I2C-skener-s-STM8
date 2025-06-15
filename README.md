# I2C-skener-s-STM8
Jednoduchý I2C skener určen pro detekci I2C slave zařízení. Namísto originální knihovny od ST využívá pro jednoduchost bit-bang knihovnu SW_I2C. Tato knihovna je odtud: https://embedded-lab.com/blog/stm8-microcontrollers-final-chapters/. Pro testování jsem využil RF modulátor s čipem MC44BS373CA od NXP. Jeho úplná I2C adresa je v základu 0xCA.

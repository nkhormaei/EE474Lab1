#ifndef __HEADER1_H__ 
#define __HEADER1_H__ 
 
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIOAMSEL_C (*((volatile uint32_t *)0x4005A528))
#define GPIODIR_C (*((volatile uint32_t *)0x4005A400))
#define GPIODEN_C (*((volatile uint32_t *)0x4005A51C))
#define GPIOAFSEL_C (*((volatile uint32_t *)0x4005A420))
#define GPIODATA_C (*((volatile uint32_t *)0x4005A3FC))



#endif //__HEADER1_H__ 
#ifndef __HEADER1_H__ 
#define __HEADER1_H__ 
 
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIOAMSEL_L (*((volatile uint32_t *) 0x40062528))
#define GPIODIR_L (*((volatile uint32_t *)0x40062400))
#define GPIODEN_L (*((volatile uint32_t *)0x4006251C))
#define GPIOAFSEL_L (*((volatile uint32_t *)0x40062420))
#define GPIODATA_L (*((volatile uint32_t *)0x400623FC))



#endif //__HEADER1_H__ 
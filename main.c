#include <stdint.h>
#include "lab1b.h"


int main(void)
{
 volatile unsigned short delay = 0;
 RCGCGPIO |= 0xFFF; // Enable PortF GPIO
 delay++; // Delay 2 more cycles before access Timer registers
 delay++; // Refer to Page. 756 of Datasheet for info
 
 
 
 
 while (1) {}
 
 
 return 0;
}
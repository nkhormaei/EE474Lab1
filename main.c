#include <stdint.h>
#include "lab1b.h"

enum TL_States { TL_init, TL_stop, TL_warn, TL_go } TL_State;

// turn on LED connected to PL2
void Red_on(void) 
{ 
    GPIODATA_L |= 0x4; 
} 
 
// turn off LED connected to PL2 
void Red_off(void) 
{ 
    GPIODATA_L &= ~0x4; 
} 

// turn on LED connected to PL3
void Yellow_on(void) 
{ 
    GPIODATA_L |= 0x8; 
} 
 
// turn off LED connected to PL3 
void Yellow_off(void) 
{ 
    GPIODATA_L &= ~0x8; 
} 

// turn on LED connected to PL4
void Green_on(void) 
{ 
    GPIODATA_L |= 0x10; 
} 
 
// turn off LED connected to PL4 
void Green_off(void) 
{ 
    GPIODATA_L &= ~0x10; 
} 

unsigned long pedestrian_input(void) 
{ 
  return (GPIODATA_L & 0x2); // 0x2 (pressed) or 0 (not pressed) 
} 

unsigned long system_input(void) 
{ 
  return (GPIODATA_L & 0x1); // 0x1 (pressed) or 0 (not pressed) 
} 

void Traffic_Light_System()
{
  switch(TL_State) {   // Transitions
     case TL_init:  // Initial transition
       if (system_input()) {
         TL_State = TL_go;
       }
       break;
     case TL_go:
        if (system_input()) {
           TL_State = TL_init;
        }
        else if (pedestrian_input()) {
           TL_State = TL_warn;
        } else {
          TL_State = TL_stop;
        }
        break;
     case TL_warn:
        if (system_input()) {
          TL_State = TL_init;
        }
        else {
          TL_State = TL_stop;
        }
        break;
     case TL_stop:
        if (system_input()) {
           TL_State = TL_init;
        }
        else if (!pedestrian_input()) {
           TL_State = TL_go;
        } else {
          TL_State = TL_stop;
        }
        break;
     default:
        TL_State = TL_init;
        break;
  } // Transitions

  switch(TL_State) {   // State actions
     case TL_go:
        Green_on();
        Red_off();
        Yellow_off();
        break;

     case TL_warn:
        Yellow_on();
        Green_off();
        Red_off();
        break;
     
     case TL_stop:
        Red_on();
        Green_off();
        Yellow_off();
        break;
     default:
        Red_off();
        Yellow_off();
        Green_off();
        break;
   } // State actions
  
  for (int j = 0; j < 1000000; j++) {}  
}
            
int main(void)
{
  volatile unsigned short delay = 0;
  RCGCGPIO |= 0x400; // Enable PortL GPIO
  delay++; // Delay 2 more cycles before access Timer registers
  delay++; // Refer to Page. 756 of Datasheet for info

  GPIOAMSEL_L &= ~0x1F;          // disable analog function of PL0/1/2/3/4
  GPIODIR_L |= 0x1C;             // set PL2/3/4 to output 
  GPIODIR_L &= ~0x3;             // set PL0/1 to input
  GPIOAFSEL_L &= ~0x1F;          // set PL0/1/2/3/4 regular port function 
  GPIODEN_L |= 0x1F;             // enable digital output on PL0/1/2/3/4

  Green_off();
  Yellow_off();
  Red_off();
  TL_State = TL_init;
  while(1) {
    Traffic_Light_System();
  }

  return 0;
}
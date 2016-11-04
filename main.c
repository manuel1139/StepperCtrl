/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>


#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#define _XTAL_FREQ 1000000

//gpio5 D
//gpio4 C
//gpio2 B
//gpio1 A

//gpio0 //pot input (stepper speed)


/*
uint8_t halfstep_18f252[] = {
    0b1000,
    0b1100,
    0b0100,
    0b0110,
    0b0010,
    0b0011,
    0b0001,
    0b1001
};
*/

// bit 765 4 3      2 1 0
//gpio   D C Blink  B A Analog

uint8_t halfstep[] = {
    0b0010000, //D
    0b0011000, //DC
    0b0001000, //C
    0b0001010, //CB
    0b0000010, //B
    0b0000011, //BA
    0b0000001, //A
    0b0010001 //AD
};

void main(void) {

    TRISIO = 0b11001000;
    ANSEL &= 0xF0;
    
    uint8_t mask;
    static uint8_t i = 0;
    while (1) {
       
        GPIObits.GP0 = ~GPIObits.GP0; //blink alive
        
        mask = 0b1100110;
        mask |= halfstep[i];
        GPIO = mask;
        GPIO = 0xFF;
        if (i < 7) i++; 
            else (i = 0);
        
        __delay_ms(250);

    }
}

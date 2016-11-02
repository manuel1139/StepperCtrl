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

uint8_t halfstep[] = {
    0b1000,
    0b1100,
    0b0100,
    0b0110,
    0b0010,
    0b0011,
    0b0001,
    0b1001
};

void main(void) {
/*
    TRISB &= 0xF0;     //PB0-PB3  output
    TRISCbits.TRISC2 = 0;
    uint8_t mask;
    static uint8_t i = 0;
    while (1) {
        PORTCbits.RC2 = ~PORTCbits.RC2; //blink alive
        
        
        mask = 0b11110000;
        mask |= halfstep[i];
        PORTB = mask;
        if (i < 7) i++; 
            else (i = 0);
        
        /*mask |= 1 << i;
        PORTB = mask;
        if (i < 3) i++;
        else (i = 0);

        __delay_ms(50);

    }
*/
        __delay_ms(50);

}

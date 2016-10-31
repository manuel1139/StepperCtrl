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

void main(void) {

    TRISB &= 0xF0;     //PB0-PB3  output
    TRISCbits.TRISC2 = 0;
    uint8_t mask;
    static uint8_t i = 0;
    while (1) {
        PORTCbits.RC2 = ~PORTCbits.RC2;
        mask = 0b11110000;
        mask |= 1 << i;
        PORTB = mask;
        if (i < 3) i++;
        else (i = 0);

        __delay_ms(500);

    }
}

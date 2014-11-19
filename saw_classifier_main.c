/* 
 * File:   saw_classifier_main.c
 * Author: alex-mc
 *
 * Created on November 17, 2014, 10:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <timers.h>
#include <adc.h>
#include <delays.h>
#include "fft.h"
#include "classifier.h"

#pragma config OSC = INTIO67
#pragma config MCLRE = ON
#pragma config WDT = OFF
#pragma config LVP = OFF

short ISRflag;

void setup(void);
void high_priority_interrupt(void);

void main(void) {
    const short m = 31;
    volatile short fr[31];
    overlay volatile short fi[31];
    struct Classification classification;
    setup(); // setup
    LATCbits.LATC2 = 1;
    while(1) {
        ISRflag = 0;
        LATCbits.LATC0 = 0;
        // fill fr and/or fi from ADC (details to come)
        fix_fft(fr, fi, m);
        classification = *classify(fr, fi);
        // if something set vibrate pin
        // print classification(s) to LCD
        while(1) {
            Delay10TCYx(1);
            LATCbits.LATC1 = 1;
            if(ISRflag) {
                break;
            }
            LATCbits.LATC1 = 0;
        }
    }
}

void setup(void) {
    /* Initialize Timer0 */
    OpenTimer0(TIMER_INT_ON     &
               T0_8BIT          &
               T0_SOURCE_INT    &
               T0_PS_1_256);

    TRISC = 0x00;
    LATC = 0x00;
}

void high_priority_interrupt(void) {
    if(INTCONbits.TMR0IF) {
        ISRflag = 1;
        LATCbits.LATC0 = 1;
    }
    INTCONbits.TMR0IF = 0;
}
/* 
 * File:   saw_classifier_main.c
 * Author: alex-mc
 *
 * Created on November 17, 2014, 10:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "fft.h"

/*
 * 
 */
void main(void) {
    const short m = 31;
    overlay volatile short fr[31];
    overlay volatile short fi[31];
    // initialize timer, ISR, and I/O pins
    while(1) {
        fix_fft(fr, fi, m);
        // classify as something or nothing
        // if something set vibrate pin
        // classify specifically
        // print classification(s) to LCD
        while(1) {
            // wait for timer ISR
        }
    }
}


/* 
 * File:   saw_classifier_main.c
 * Author: alex-mc
 *
 * Created on November 17, 2014, 10:59 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "fft.h"
#include "classifier.h"

/*
 * 
 */
void main(void) {
    const short m = 31;
    volatile short fr[31];
    overlay volatile short fi[31];
    struct Classification classification;
    // initialize timer, ISR, and I/O pins
    while(1) {
        // fill fr and/or fi from ADC (details to come)
        fix_fft(fr, fi, m);
        classification = *classify(fr, fi);
        // if something set vibrate pin
        // print classification(s) to LCD
        while(1);
    }
}
/* 
 * File:   fft.h
 * Author: alexmc
 *
 * Created on November 19, 2014, 10:34 AM
 */

#ifndef FFT_H
#define	FFT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define N_WAVE          1024
#define LOG2_N_WAVE     10

void fix_fft(volatile short fr[], volatile short fi[], short m);

#ifdef	__cplusplus
}
#endif

#endif	/* FFT_H */
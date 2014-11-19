/* 
 * File:   classifier.h
 * Author: alexmc
 *
 * Created on November 19, 2014, 12:54 PM
 */

#ifndef CLASSIFIER_H
#define	CLASSIFIER_H

#ifdef	__cplusplus
extern "C" {
#endif

    struct Prob {
        int probability;
        char classification[];
    };

    struct Classification {
        struct Prob p1;
        struct Prob p2;
    };

    struct Classification *classify(volatile short fr[], volatile short fi[]);

#ifdef	__cplusplus
}
#endif

#endif	/* CLASSIFIER_H */
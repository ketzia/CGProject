//
//  vectors.h
//  
//
//  Created by ErnestoPM on 10/19/17.
//
#include <cmath>
#ifndef vectors_h
#define vectors_h
#define vecMagnitude(vector) sqrt(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2])


struct vector3 {
    float x;
    float y;
    float z;
};

void unitVector(float *);

#endif /* vectors_h */

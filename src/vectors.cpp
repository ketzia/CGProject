//
//  vectors.cpp
//  FinalProject
//
//  Created by ErnestoPM on 11/14/17.
//  Copyright © 2017 ErnestoPM. All rights reserved.
//

#include "vectors.h"

void unitVector(float *vector){
    float absVal = vecMagnitude(vector);
    if(absVal > 0){
        vector[0] /= absVal;
        vector[1] /= absVal;
        vector[2] /= absVal;
    }
}

#include "vectors.h"

void unitVector(float *vector){
    float absVal = vecMagnitude(vector);
    if(absVal > 0){
        vector[0] /= absVal;
        vector[1] /= absVal;
        vector[2] /= absVal;
    }
}

#pragma once
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#else
#include "freeglut.h"
#include <stdio.h>
#include <math.h>
#endif

#include "color.h"
#include "vectors.h"
#include "rectangle.h"
#include "glm.h"

class PlayerNPC {
    
public:
    PlayerNPC(float *rotationY, float *speed, Color color, float initalXPosition);
    ~PlayerNPC();
    
    float *rotationY;
    float *speed;
    
    Color color;
    
    vector3 position;
    vector3 initialDirection;
    
    float** rotationMatrix;
    
    void draw();
    void recalculateRotationMatrix(float angle);
    vector3 calculateDirection();
    
    GLMmodel* model;
};


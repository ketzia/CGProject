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

class PlayerNPC {
    
public:
    PlayerNPC(float height, float width, float *rotationY, float *speed, Color color);
    ~PlayerNPC();
    
    Rectangle* player;
    float *rotationY;
    float *speed;
    
    float height,width;
    Color color;
    
    vector3 position;
    vector3 initialDirection;
    
    float** rotationMatrix;
    
    void draw();
    void recalculateRotationMatrix(float angle);
    vector3 calculateDirection();
};


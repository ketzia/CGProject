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
    PlayerNPC(float height, float width, vector3 * position, float *rotationY, Color color);
    ~PlayerNPC();
    
    Rectangle* player;
    float *rotationY;
    float height,width;
    vector3 * position;
    vector3 initialDirection;
    Color color;
    float** rotationMatrix;
    
    void draw();
    void recalculateRotationMatrix(float angle);
    vector3 calculateDirection();
};


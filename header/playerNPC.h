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
    PlayerNPC(float height, float width, vector3 * position, float *rotation, Color color);
    ~PlayerNPC();
    
    Rectangle* player;
    float *rotation;
    float height,width;
    vector3 * position;
    Color color;
    void draw();
};


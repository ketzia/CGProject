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

class SoccerBall {
    
public:
    SoccerBall(float radius, vector3 * position, Color color);
    ~SoccerBall();
    
    float radius;
    vector3 * position;
    Color color;
    void draw();
    
};


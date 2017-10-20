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

class Rectangle {
public:
    
    Rectangle(float height, float width, float depth);
    ~Rectangle();
    
    void draw();
    float height, width, depth;
    
};

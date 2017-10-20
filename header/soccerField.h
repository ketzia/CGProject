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

#include "rectangle.h"
#include "color.h"

class SoccerField {

public:
    
    float posY;
    Rectangle* field;
    Color color;
    
    SoccerField(float width, float depth, float posY, Color color);
    ~SoccerField();
    
    void draw();
    

    
    
    
    
};

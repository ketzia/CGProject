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

#include "goal.h"
#include "rectangle.h"
#include "color.h"
#include "vectors.h"

class SoccerField {

public:
    
    float posY;
    Rectangle* field;
    Color color;
    
    SoccerField(float width, float depth, float posY, Color color);
    ~SoccerField();
    
    void draw();
    
private:
    
    // Goals are just part of this class
    Goal* goalOne;
    Goal* goalTwo;
    
    vector3 topLeft_b, topRight_b, lowLeft_b, lowRight_b;
    GLfloat* mat_specular;
    GLfloat* mat_diffuse;
    GLfloat* mat_shininess;
    
    
};

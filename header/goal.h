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

#include "glm.h"

class Goal {
    
public:
    Goal(float positionX, float positionY, float positionZ, float rotationY);
    ~Goal();
    void draw();
    GLMmodel* model;
    float positionX, positionY, positionZ, rotationY;
    
private:
    GLfloat* mat_specular;
    GLfloat* mat_diffuse;
    GLfloat* mat_shininess;
    
};


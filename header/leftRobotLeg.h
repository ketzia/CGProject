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

class LeftRobotLeg {
    
public:
    LeftRobotLeg(float positionX, float positionY, float positionZ, float rotationY);
    ~LeftRobotLeg();
    void draw();
    void animate();
    GLMmodel* lowerLeg;
    GLMmodel* upperLeg;
    float positionX, positionY, positionZ, rotationY;
    
private:
    GLfloat* mat_specular;
    GLfloat* mat_diffuse;
    GLfloat* mat_shininess;
    
};



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

class RobotHead {
    
public:
    
    RobotHead();
    ~RobotHead();
    void draw();
    GLMmodel* head;
    
private:
    
    GLfloat* head_mat_specular;
    GLfloat* head_mat_diffuse;
    GLfloat* head_mat_shininess;
    
};



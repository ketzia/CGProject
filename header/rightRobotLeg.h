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

class RightRobotLeg {
    
public:
    RightRobotLeg(float positionX, float positionY, float positionZ, float rotationY);
    ~RightRobotLeg();
    void draw();
    void animate();
    GLMmodel* lowerLeg;
    GLMmodel* upperLeg;
    float positionX, positionY, positionZ, rotationY;
    
private:
    
    GLfloat* lowerLeg_mat_specular;
    GLfloat* lowerLeg_mat_diffuse;
    GLfloat* lowerLeg_mat_shininess;
    
    GLfloat* upperLeg_mat_specular;
    GLfloat* upperLeg_mat_diffuse;
    GLfloat* upperLeg_mat_shininess;
    
    // LowerLeg aniamtion values
    float lowerLegHeight;
    bool lowerLegBounce;
    
    // UpperLeg animation values
    float upperLegAngle;
    bool upperLegBounce;
    
};


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

class LeftRobotArm {
    
public:
    LeftRobotArm();
    ~LeftRobotArm();
    void draw();
    void animate();
    GLMmodel* lowerArm;
    GLMmodel* upperArm;
    
private:
    
    GLfloat* upperArm_mat_specular;
    GLfloat* upperArm_mat_diffuse;
    GLfloat* upperArm_mat_shininess;
    
    GLfloat* lowerArm_mat_specular;
    GLfloat* lowerArm_mat_diffuse;
    GLfloat* lowerArm_mat_shininess;
    
    // LowerLeg animation values
    float lowerArmAngle;
    bool lowerArmBounce;
    
    // UpperLeg animation values
    float upperArmAngle;
    bool upperArmBounce;
    
};



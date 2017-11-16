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
#include "color.h"

class RightRobotLeg {
    
public:
    RightRobotLeg(Color mainColor);
    ~RightRobotLeg();
    void draw();
    void animate();
    GLMmodel* lowerLeg;
    GLMmodel* upperLeg;
    
private:
        
    // This color is mainColor
    GLfloat* lowerLeg_mat_specular;
    GLfloat* lowerLeg_mat_diffuse;
    GLfloat* lowerLeg_mat_shininess;
    
    // This is always black
    GLfloat* upperLeg_mat_specular;
    GLfloat* upperLeg_mat_diffuse;
    GLfloat* upperLeg_mat_shininess;
    
    // LowerLeg animation values
    float lowerLegAngle;
    bool lowerLegBounce;
    
    // UpperLeg animation values
    float upperLegAngle;
    bool upperLegBounce;
    
};


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

class RobotBody {
    
public:
    RobotBody();
    ~RobotBody();
    void draw();
    void animate();
    GLMmodel* torso;
    
private:
    
    GLfloat* torso_mat_specular;
    GLfloat* torso_mat_diffuse;
    GLfloat* torso_mat_shininess;
    
    // LowerLeg aniamtion values
    float lowerLegHeight;
    bool lowerLegBounce;
    
    // UpperLeg animation values
    float upperLegAngle;
    bool upperLegBounce;
};




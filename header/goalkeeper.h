#ifndef goalkeeper_h
#define goalkeeper_h

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
#include "vectors.h"

class SoccerBall; // Forward declaration

class Goalkeeper {

public:
    Goalkeeper(Color mainColor, float initalX, float initialZ);
    ~Goalkeeper();
    GLMmodel* model;
    
    // Variables
    vector3 position;
    float speed;
    float ballXPosition;
    float radius;
    
    // Methods
    void draw();
    void followBall(SoccerBall* ball);

private:
    
    // Material variables
    GLfloat* goalkeeper_mat_specular;
    GLfloat* goalkeeper_mat_diffuse;
    GLfloat* goalkeeper_mat_shininess;
    
};

#endif

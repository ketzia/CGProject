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

#include "vectors.h"
#include "glm.h"

class Goal {
    
public:
    Goal(float radius, float x, float z);
    ~Goal();
    vector3 position;
    float radius;
    void draw();
    
};


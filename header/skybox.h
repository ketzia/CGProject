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
#include "cTexture.h"

class Skybox {
public:
    
    Skybox(float size);
    ~Skybox();
    
    void draw();
    
private:
    float size;
    Texture targas[6];
    
};

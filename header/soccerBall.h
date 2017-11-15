#pragma once
#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
    #include <math.h>
    #include <random>
#else
    #include "freeglut.h"

    #include <math.h>
#endif

#include <stdio.h>
#include <cmath>
#include "color.h"
#include "vectors.h"
#include "playerNPC.h"

class SoccerBall {
    
public:
    SoccerBall(float * speed);
    ~SoccerBall();
    vector3 position;
    vector3 directionVector;
    
    float * speed;
    void draw();
    float radius;
    bool isMoving;
    PlayerNPC* attachedPlayer;
    
    bool inCollisionWithPlayer(PlayerNPC* player);
    void setPosition(float x, float z);
    void setDirectionVector();
};


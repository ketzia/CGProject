#ifndef soccerball_h
#define soccerball_h

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
#include "goal.h"

class Goalkeeper; // Forward declaration

class SoccerBall {
    
public:
    SoccerBall(float * speed);
    ~SoccerBall();
    vector3 position;
    vector3 directionVector;
    
    float * speed;
    
    float radius;
    bool isMoving;
    PlayerNPC* attachedPlayer;
    
    void draw();
    
    // Checks if the position of this object is past the boundaries of the soccerfield
    void checkFieldBoundaries();
    
    // Methods to check collisions with objects
    bool inCollisionWithPlayer(PlayerNPC* player);
    bool inCollisionWithGoal(Goal* goal);
    bool inCollisionWithGoalkeeper(Goalkeeper* goalkeeper);
    
    void setPosition(float x, float z);
    void setDirectionVector();
};

#endif

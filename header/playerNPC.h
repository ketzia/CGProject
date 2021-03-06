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

#include "color.h"
#include "vectors.h"
#include "rectangle.h"
#include "glm.h"

#include "rightRobotLeg.h"
#include "leftRobotLeg.h"
#include "robotBody.h"
#include "rightRobotArm.h"
#include "leftRobotArm.h"
#include "robotHead.h"

class PlayerNPC {
    
public:
    PlayerNPC(float *rotationY, float *speed, Color mainColor, float initalXPosition);
    ~PlayerNPC();
    
    float *rotationY;
    float *speed;
    
    Color mainColor;
    
    vector3 position;
    vector3 initialDirection;
    vector3 directionVector;
    
    float** rotationMatrix;
    
    // Draw each component separately
    void draw();
    
    // Checks if the position of this object is past the boundaries of the soccerfield
    void checkFieldBoundaries();
    
    // Recalculates the rotation matrix given an angle
    void recalculateRotationMatrix(float angle);
    
    // calls the animate method of each body part
    void animate();
    
    // Recalculates direction the model is facing
    vector3 calculateDirection();
    
    // Collision radius to calcualte collisions with ball
    float collisionRadius;
    
    // Reference to all body parts
    RightRobotLeg* rightLeg;
    LeftRobotLeg* leftLeg;
    RobotBody* robotBody;
    RightRobotArm* rightArm;
    LeftRobotArm* leftArm;
    RobotHead* head;

};


/*
     We used the method of moving the player ourselves by implementing the rotation matrix to store the players direction, which
 is going to be used later for the game logic.
 */

#include "playerNPC.h"
#include "rectangle.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>

PlayerNPC::PlayerNPC(float *rotationY, float *speed, Color color) {
    // Player properties
    this->color = color;
    
    // Movement properties
    this->position.x =0;this->position.y =0;this->position.z =0;
    this->rotationY = rotationY;
    this->speed = speed;
    this->initialDirection.x = 1;this->initialDirection.y=0;this->initialDirection.z = 0; // Direction is (1,0,0)
    
    // Create rotation matrix
    this->rotationMatrix = new float*[3];
    for(int i = 0; i < 3; ++i) {
        this->rotationMatrix[i] = new float[3];
    }
}

void PlayerNPC::draw() {
    glPushMatrix();{
        
        glColor3f(color.r, color.g, color.b);
        recalculateRotationMatrix(*rotationY);
        vector3 directionVector = calculateDirection();
        position.x += directionVector.x * (*(float*)speed);
        position.y += directionVector.y * (*(float*)speed);
        position.z += directionVector.z * (*(float*)speed);
        
        glTranslatef(position.x, position.y, position.z);
        glRotatef(*rotationY, 0, 1, 0);
        glutWireTeapot(0.3);
    
    }glPopMatrix();
    glColor3f(1, 1, 1);
    
}

void PlayerNPC::recalculateRotationMatrix(float angle) {
    rotationMatrix[0][0] = cos(toRadians(angle));
    rotationMatrix[0][1] = 0;
    rotationMatrix[0][2] = sin(toRadians(angle));
    
    rotationMatrix[1][0] = 0;
    rotationMatrix[1][1] = 1;
    rotationMatrix[1][2] = 0;
    
    rotationMatrix[2][0] = sin(toRadians(angle)) * -1;
    rotationMatrix[2][1] = 0;
    rotationMatrix[2][2] = cos(toRadians(angle));
}

vector3 PlayerNPC::calculateDirection() {
    vector3 newDirection;
    
    float x = (rotationMatrix[0][0] * initialDirection.x) + (rotationMatrix[0][1] * initialDirection.y) + (rotationMatrix[0][2] * initialDirection.z);
    float y = (rotationMatrix[1][0] * initialDirection.x) + (rotationMatrix[1][1] * initialDirection.y) + (rotationMatrix[1][2] * initialDirection.z);
    float z = (rotationMatrix[2][0] * initialDirection.x) + (rotationMatrix[2][1] * initialDirection.y) + (rotationMatrix[2][2] * initialDirection.z);
    newDirection.x = x;
    newDirection.y = y;
    newDirection.z = z;
    
    return newDirection;
}


#include "soccerBall.h"

SoccerBall::SoccerBall(float* speed) {
    this->speed = speed;
    position.x = 0.0f;position.y = -0.8f;position.z = 5.0f;
    directionVector.x = 0.0f;directionVector.y = 0.0f;directionVector.z = 0.0f;
    radius = 0.2f;
    isMoving = false;
}

void SoccerBall::draw() {
    
    if(isMoving) {
        position.x += directionVector.x * (*speed);
        position.z += directionVector.z * (*speed);
        //position.x += attachedPlayer->directionVector.x * (*speed);
        //position.z += attachedPlayer->directionVector.z * (*speed);
    }
    glPushMatrix();{
        glTranslatef(position.x, position.y , position.z);
        glColor3f(1, 1, 1);
        glutSolidSphere(radius, 20, 20);
    }glPopMatrix();
    //glColor3f(1, 1, 1);
}

void SoccerBall::setPosition(float x, float z){
    position.x = x;
    position.z = z;
}

void SoccerBall::setDirectionVector() {
    if(attachedPlayer != NULL) {
        directionVector.x = attachedPlayer->directionVector.x;
        directionVector.z = attachedPlayer->directionVector.z;
    }
}

bool SoccerBall::inCollisionWithPlayer(PlayerNPC* player) {
    float sum = radius + player->collisionRadius;
    
    float xComponent = pow(player->position.x - position.x,2);
    float yComponent = 0; //pow(player->position.y - position.y,2);
    float zComponent = pow(player->position.z - position.z,2);
    
    float distance = sqrt(xComponent + yComponent + zComponent);
    
    if(distance < sum) {
        attachedPlayer = player;
        return true;
    } else {
        //dettachPlayer();
        return false;
    }
}

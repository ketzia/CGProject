#include "soccerBall.h"
#include "goalkeeper.h" // forward declaration https://stackoverflow.com/questions/4964482/how-to-create-two-classes-in-c-which-use-each-other-as-data

SoccerBall::SoccerBall(float* speed) {
    this->speed = speed;
    
    // Start ball at random position every time
    srand(time(NULL));
    int maxRandomPosition = 5;
    int minRandomPosition = -5;
    position.x = rand() % (maxRandomPosition-minRandomPosition + 1) + minRandomPosition;
    position.y = -0.8f;
    position.z = rand() % (maxRandomPosition-minRandomPosition + 1) + minRandomPosition;
    
    //position.x = 0.0f;position.y = -0.8f;position.z = 5.0f;
    directionVector.x = 0.0f;directionVector.y = 0.0f;directionVector.z = 0.0f;
    radius = 0.2f;
    isMoving = false;
}

void SoccerBall::checkFieldBoundaries() {
    if(position.x > 12) {
        position.x = 12;
    }
    
    if(position.x < -12) {
        position.x = -12;
    }
    
    if(position.z > 24) {
        position.z = 24;
    }
    
    if(position.z < -24) {
        position.z = -24;
    }
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
        checkFieldBoundaries();
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
        return false;
    }
}

bool SoccerBall::inCollisionWithGoal(Goal* goal) {
    float sum = radius + goal->radius;
    float xComponent = pow(goal->position.x - position.x,2);
    float yComponent = 0;
    float zComponent = pow(goal->position.z - position.z,2);
    
    float distance = sqrt(xComponent + yComponent + zComponent);
    
    if(distance < sum) {
        return true;
    } else {
        return false;
    }
}


bool SoccerBall::inCollisionWithGoalkeeper(Goalkeeper* goalkeeper) {
    float sum = radius + goalkeeper->radius;
    float xComponent = pow(goalkeeper->position.x - position.x, 2);
    float yComponent = 0;
    float zComponent = pow(goalkeeper->position.z - position.z,2);
    
    float distance = sqrt(xComponent + yComponent + zComponent);
    
    if(distance<sum) {
        return true;
    } else {
        return false;
    }
}



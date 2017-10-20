#include "soccerBall.h"
#include <stdio.h>

SoccerBall::SoccerBall(float radius, vector3 * position, Color color) {
    this->radius = radius;
    this->position = position;
    this->color = color;
}

void SoccerBall::draw() {
    //printf("X-ball: %f\n",position->x);
    glPushMatrix();{
        glTranslatef(position->x, position->y, position->z);
        glColor3f(color.r, color.g, color.b);
        glutWireSphere(radius, 30, 30);
    }glPopMatrix();
    glColor3f(1, 1, 1);
}


#include "playerNPC.h"
#include "rectangle.h"
#include <stdio.h>

PlayerNPC::PlayerNPC(float height, float width, vector3 * position, float *rotation, Color color) {
    this->height = height;
    this->width = width;
    this->color = color;
    this->position = position;
    this->rotation = rotation;
    player = new Rectangle(height, width, 1);
}

void PlayerNPC::draw() {
    glPushMatrix();{
        glTranslatef(position->x, position->y, position->z);
        glRotatef(*rotation,0 , 1, 0);
        glColor3f(color.r, color.g, color.b);
        player->draw();
    }glPopMatrix();
    glColor3f(1, 1, 1);
}


// (1,0,0) -->
// (0,0,-1)

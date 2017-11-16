#include "goal.h"
#include "glm.h"

Goal::Goal(float radius, float x, float z) {
    this->radius = radius;
    position.x = x;
    position.y = 0;
    position.z = z;
}

void Goal::draw() {
    glPushMatrix();{
        glTranslatef(position.x, 0, position.z);
        glutWireSphere(radius, 20, 20);
    }glPopMatrix();
}


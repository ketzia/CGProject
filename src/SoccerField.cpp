#include "soccerField.h"

SoccerField::SoccerField(float width, float depth, float posY, Color color) {
    this->posY = posY;
    this->color = color;
    field = new Rectangle(0.1,width,depth);
    
    topLeft_b.x = -width;topLeft_b.y = posY;topLeft_b.z = -depth;
    lowLeft_b.x = -width;lowLeft_b.y = posY;lowLeft_b.z = depth;
}

void SoccerField::draw() {
    // Draw soccer field
    glPushMatrix();{
        glTranslatef(0, posY, 0);
        glColor3f(color.r, color.g, color.b);
        field->draw();
    }glPopMatrix();
    glColor3f(1, 1, 1);
    
}

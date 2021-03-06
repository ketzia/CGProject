#include "rectangle.h"

Rectangle::Rectangle(float h, float w, float d) {
    height = h;
    width = w;
    depth = d;
}

Rectangle::~Rectangle(){
}

void Rectangle::draw() {
    glPushMatrix();{
        
        // Lower Square
        glBegin(GL_QUADS);
            glNormal3f(0, 1, 0);
            glVertex3f(-width/2, 0, depth/2);
            glNormal3f(0, 1, 0);
            glVertex3f(width/2, 0, depth/2);
            glNormal3f(0, 1, 0);
            glVertex3f(width/2, 0, -depth/2);
            glNormal3f(0, 1, 0);
            glVertex3f(-width/2, 0, -depth/2);
        glEnd();
        /*
        glBegin(GL_QUADS);
            glVertex3f(-width,0, -depth);
            glVertex3f(width,0, -depth);
            glVertex3f(width,0,0);
            glVertex3f(width,0,0);
        glEnd();
        
        // Upper Square
        glBegin(GL_QUADS);
            glVertex3f(-width,height, -depth);
            glVertex3f(width,height, -depth);
            glVertex3f(width,height,0);
            glVertex3f(-width,height,0);
        glEnd();
        
        // Front Square
        glBegin(GL_QUADS);
            glVertex3f(-width,0,0);
            glVertex3f(width,0,0);
            glVertex3f(width,height,0);
            glVertex3f(-width,height,0);
        glEnd();
        
        // Back Square
        glBegin(GL_QUADS);
            glVertex3f(-width,0,-depth);
            glVertex3f(width,0,-depth);
            glVertex3f(width,height,-depth);
            glVertex3f(-width,height,-depth);
        glEnd();
        
        // Left Square
        glBegin(GL_QUADS);
            glVertex3f(-width,0,0);
            glVertex3f(-width,0,-depth);
            glVertex3f(-width,height,-depth);
            glVertex3f(-width,height,0);
        glEnd();
        
        // Right Square
        glBegin(GL_QUADS);
            glVertex3f(width,0,0);
            glVertex3f(width,0,-depth);
            glVertex3f(width,height,-depth);
            glVertex3f(width,height,0);
        glEnd();
     */
        
    }glPopMatrix();
}

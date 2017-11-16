#include "ambientProps.h"

AmbientProps::AmbientProps() {
    sunRotation   = 0;
    moonRotation  = 0;
    earthRotation = 0;
    venusRotation = 0;
}


void AmbientProps::draw() {
    glPushMatrix(); {
        //glDisable(GL_LIGHTING);
        glTranslatef(0, 8, 0);
        
        // Sun
        glPushMatrix();{
            glRotatef(sunRotation, 0,1,0);
            glColor3f(1, 0, 0);
            glutWireSphere(4, 80, 80);
        }glPopMatrix();
        
        // Mercury
        glPushMatrix();{
            glRotatef(venusRotation, 0, 1, 0);
            glTranslatef(9, 0, 0);
            glScalef(0.3, 0.3, 0.3);
            glColor3f(0, 1, 0);
            glutWireSphere(4, 40, 40);
        }glPopMatrix();
        
        // Earth
        glPushMatrix(); {
            glRotatef(earthRotation, 0, 1, 0);
            glTranslatef(12, 0, 0);
            glScalef(0.2, 0.2, 0.2);
            glEnable(GL_COLOR_MATERIAL);{
                glColor3f(0, 0, 1);
                glutWireSphere(4, 20, 20);
            }glDisable(GL_COLOR_MATERIAL);
        }glPopMatrix();
        //glEnable(GL_LIGHTING);
    }glPopMatrix();
}

void AmbientProps::animate() {
    sunRotation += 0.5f;
    venusRotation  += 0.7f;
    earthRotation += 0.5f;
}

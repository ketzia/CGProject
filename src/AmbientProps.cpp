#include "ambientProps.h"

AmbientProps::AmbientProps() {
    sunRotation   = 0;
    moonRotation  = 0;
    earthRotation = 0;
    venusRotation = 0;
}


void AmbientProps::draw() {
    glPushMatrix(); {
        glDisable(GL_LIGHTING);
        glTranslatef(0, 13, 0);
        glPushMatrix();{
            glColor3f(1,0.68,0);
            glRotatef(sunRotation, 0, 1, 0);
            glTranslatef(35, 0, 0);
            glRotatef(sunRotation, 0, 1, 0);
            //glutWireSphere(8, 80, 80);
            glutSolidSphere(8, 80, 80);
            {
                glRotatef(moonRotation, 0, 1, 1);
                glTranslatef(12, 0, 0);
                glColor3f(0, 0.49, 1);
                glScalef(0.2, 0.2, 0.2);
                //glutWireSphere(8, 80, 80);
                glutSolidSphere(8, 80, 80);
            }
        }glPopMatrix();
        
        
        /*
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
         */
        glEnable(GL_LIGHTING);
    }glPopMatrix();
}

void AmbientProps::animate() {
    sunRotation += 0.3f;
    moonRotation += 0.7f;
    venusRotation  += 0.7f;
    earthRotation += 0.5f;
}

#include "rightRobotLeg.h"
#include "glm.h"

RightRobotLeg::RightRobotLeg(float positionX, float positionY, float positionZ, float rotationY) {
    lowerLeg = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/pie_L/pie_L.obj");
    upperLeg = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/upperLeg_L/upperLeg_L.obj");
    
    glmVertexNormals(lowerLeg, 45.0f, false);
    glmVertexNormals(upperLeg, 45.0f, false);
    
    glmFacetNormals(lowerLeg);
    glmFacetNormals(upperLeg);
    
    glmScale(lowerLeg, 0.01);
    glmScale(upperLeg, 0.01);

    this->positionX = positionX;
    this->positionY = positionY;
    this->positionZ = positionZ;
    this->rotationY = rotationY;
    
    upperLegAngle = 0;
    upperLegBounce = true;
}

void RightRobotLeg::draw() {
    
    glPushMatrix();{
        glTranslatef(0, 0, 0);
        glRotatef(-90, 0, 1, 0);
        glmDraw(lowerLeg, GLM_SMOOTH);
    }glPopMatrix();
    
    
    // Uper Leg
    glPushMatrix();{
        // Position Object
        glTranslatef(0, 0.50, 0.1);
        glRotatef(-90, 0, 1, 0);
        
        // Animation
        glPushMatrix(); {
            glRotatef(upperLegAngle, 1, 0, 0);
            glmDraw(upperLeg, GLM_SMOOTH);
        }glPopMatrix();
    }glPopMatrix();
    
}

void RightRobotLeg::animate() {
    upperLegAngle += upperLegBounce ? 3 : -3;
    
    if(upperLegAngle >= 90 || upperLegAngle <= 0) {
        upperLegBounce = !upperLegBounce;
    }
}


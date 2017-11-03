#include "leftRobotLeg.h"
#include "glm.h"

LeftRobotLeg::LeftRobotLeg(float positionX, float positionY, float positionZ, float rotationY) {
    lowerLeg = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/pie_R/pie_R.obj");
    upperLeg = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/upperLeg_R/upperLeg_R.obj");
    
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
    
    /*
     mat_specular       = new GLfloat[4]; //<------------------------Asignar memoria
     mat_specular[0]    = 1.0f; //<----------------------------------S0r
     mat_specular[1]    = 1.0f; //<----------------------------------S0g
     mat_specular[2]    = 1.0f; //<----------------------------------S0b
     mat_specular[3]    = 1.0f; //<----------------------------------S0a
     
     mat_diffuse        = new GLfloat[4]; //<------------------------Asignar memoria
     mat_diffuse[0]     = 1.0f; //<----------------------------------D0r
     mat_diffuse[1]     = 1.0f; //<----------------------------------D0g
     mat_diffuse[2]     = 1.0f; //<----------------------------------D0b
     mat_diffuse[3]     = 1.0f; //<----------------------------------D0a
     
     mat_shininess      = new GLfloat[1]; //<------------------------Asignar memoria
     mat_shininess[0]   = 60.0f; //<---------------------------------Exponente especular del material 0
     */
}

void LeftRobotLeg::draw() {
    
    glPushMatrix();{
        glTranslatef(0, 0, 0);
        glRotatef(-90, 0, 1, 0);
        glmDraw(lowerLeg, GLM_SMOOTH);
    }glPopMatrix();
    
    glPushMatrix();{
        glTranslatef(0, 0.55, -0.1);
        glRotatef(-90, 0, 1, 0);
        glmDraw(upperLeg, GLM_SMOOTH);
    }glPopMatrix();
    
    
    
}

void LeftRobotLeg::animate() {
    
}



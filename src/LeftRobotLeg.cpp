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
    
    upperLegAngle = 0;
    upperLegBounce = true;
    
    lowerLegHeight = 0.3;
    lowerLegBounce = false;
    
    /** Lower Leg Materials  **/
    lowerLeg_mat_specular       = new GLfloat[4]; //<------------------------Asignar memoria
    lowerLeg_mat_specular[0]    = 1.0f; //<----------------------------------S0r
    lowerLeg_mat_specular[1]    = 1.0f; //<----------------------------------S0g
    lowerLeg_mat_specular[2]    = 1.0f; //<----------------------------------S0b
    lowerLeg_mat_specular[3]    = 1.0f; //<----------------------------------S0a
    
    lowerLeg_mat_diffuse        = new GLfloat[4]; //<------------------------Asignar memoria
    lowerLeg_mat_diffuse[0]     = 0.0f; //<----------------------------------D0r
    lowerLeg_mat_diffuse[1]     = 0.0f; //<----------------------------------D0g
    lowerLeg_mat_diffuse[2]     = 0.0f; //<----------------------------------D0b
    lowerLeg_mat_diffuse[3]     = 1.0f; //<----------------------------------D0a
    
    lowerLeg_mat_shininess      = new GLfloat[1]; //<------------------------Asignar memoria
    lowerLeg_mat_shininess[0]   = 60.0f; //<---------------------------------Exponente especular del material 0
    
    /** Upper Leg Materials  **/
    upperLeg_mat_specular       = new GLfloat[4]; //<------------------------Asignar memoria
    upperLeg_mat_specular[0]    = 1.0f; //<----------------------------------S0r
    upperLeg_mat_specular[1]    = 1.0f; //<----------------------------------S0g
    upperLeg_mat_specular[2]    = 1.0f; //<----------------------------------S0b
    upperLeg_mat_specular[3]    = 1.0f; //<----------------------------------S0a
    
    upperLeg_mat_diffuse        = new GLfloat[4]; //<------------------------Asignar memoria
    upperLeg_mat_diffuse[0]     = 0.83f; //<----------------------------------D0r
    upperLeg_mat_diffuse[1]     = 0.69f; //<----------------------------------D0g
    upperLeg_mat_diffuse[2]     = 0.22f; //<----------------------------------D0b
    upperLeg_mat_diffuse[3]     = 1.0f; //<----------------------------------D0a
    
    upperLeg_mat_shininess     = new GLfloat[1]; //<------------------------Asignar memoria
    upperLeg_mat_shininess[0]   = 60.0f; //<---------------------------------Exponente especular del material 0
}

void LeftRobotLeg::draw() {
    
    glPushMatrix(); {
        // Locate Object
        glTranslatef(0, 0, 0);
        glRotatef(-90, 0, 1, 0);
        
        // Lower Leg
        glPushMatrix();{
            glTranslatef(0, lowerLegHeight, 0);
            glMaterialfv( GL_FRONT,     GL_DIFFUSE,   lowerLeg_mat_diffuse        );
            glMaterialfv( GL_FRONT,  GL_SPECULAR,  lowerLeg_mat_specular    );
            glMaterialfv( GL_FRONT,  GL_SHININESS, lowerLeg_mat_shininess    );
            glmDraw(lowerLeg, GLM_SMOOTH);
        }glPopMatrix();
        
        
        // Uper Leg
        glPushMatrix();{
            // Position Object
            glTranslatef(-0.1, lowerLegHeight + 0.50, 0);
            // Animation
            glPushMatrix(); {
                glRotatef(upperLegAngle, 1, 0, 0);
                glMaterialfv( GL_FRONT,     GL_DIFFUSE,   upperLeg_mat_diffuse        );
                glMaterialfv( GL_FRONT,  GL_SPECULAR,  upperLeg_mat_specular    );
                glMaterialfv( GL_FRONT,  GL_SHININESS, upperLeg_mat_shininess    );
                glmDraw(upperLeg, GLM_SMOOTH);
            }glPopMatrix();
        }glPopMatrix();
    }glPopMatrix();
    
    
    
}

void LeftRobotLeg::animate() {
    upperLegAngle += upperLegBounce ? 3.1 : -3.1;
    lowerLegHeight += lowerLegBounce ? 0.01 : -0.01;
    
    if(upperLegAngle >= 90 || upperLegAngle <= 0) {
        upperLegBounce = !upperLegBounce;
    }
    
    if(lowerLegHeight >= 0.3 || lowerLegHeight <= 0) {
        lowerLegBounce = !lowerLegBounce;
    }
}



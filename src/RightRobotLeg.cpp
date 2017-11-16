#include "rightRobotLeg.h"
#include "glm.h"

RightRobotLeg::RightRobotLeg(Color mainColor) {
    lowerLeg = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/pie_L/pie_L.obj");
    upperLeg = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/upperLeg_L/upperLeg_L.obj");
    
    glmVertexNormals(lowerLeg, 45.0f, false);
    glmVertexNormals(upperLeg, 45.0f, false);
    
    glmFacetNormals(lowerLeg);
    glmFacetNormals(upperLeg);
    
    glmScale(lowerLeg, 0.01);
    glmScale(upperLeg, 0.01);

    upperLegAngle = 0;
    upperLegBounce = true;
    
    lowerLegAngle = -60;
    lowerLegBounce = true;
    
    
    /** Lower Leg Material is MainColor  **/
    lowerLeg_mat_specular       = new GLfloat[4];
    lowerLeg_mat_specular[0]    = 1.0f;
    lowerLeg_mat_specular[1]    = 1.0f;
    lowerLeg_mat_specular[2]    = 1.0f;
    lowerLeg_mat_specular[3]    = 1.0f;
    
    lowerLeg_mat_diffuse        = new GLfloat[4];
    lowerLeg_mat_diffuse[0]     = mainColor.r;
    lowerLeg_mat_diffuse[1]     = mainColor.g;
    lowerLeg_mat_diffuse[2]     = mainColor.b;
    lowerLeg_mat_diffuse[3]     = 1.0f;
    
    lowerLeg_mat_shininess      = new GLfloat[1];
    lowerLeg_mat_shininess[0]   = 60.0f;
    
    /** Upper Leg Material is always dark black (without specular values) **/
    upperLeg_mat_specular       = new GLfloat[4];
    upperLeg_mat_specular[0]    = 0.0f;
    upperLeg_mat_specular[1]    = 0.0f;
    upperLeg_mat_specular[2]    = 0.0f;
    upperLeg_mat_specular[3]    = 1.0f;
    
    upperLeg_mat_diffuse        = new GLfloat[4];
    upperLeg_mat_diffuse[0]     = 0.0;
    upperLeg_mat_diffuse[1]     = 0.0;
    upperLeg_mat_diffuse[2]     = 0.0;
    upperLeg_mat_diffuse[3]     = 1.0f;
    
    upperLeg_mat_shininess     = new GLfloat[1];
    upperLeg_mat_shininess[0]   = 60.0f;
}

void RightRobotLeg::draw() {
    
    
    glPushMatrix();{
        glTranslatef(0, 0, 0);
        glRotatef(-90, 0, 1, 0);
        
        glPushMatrix(); {
            // First translate the leg
            glTranslatef(0.1, 0.50, 0);
            
            glTranslatef(0.1, 0.50, 0);
            glRotatef(upperLegAngle, 1, 0, 0);
            glTranslatef(-0.1, -0.50, 0);
            glMaterialfv( GL_FRONT,     GL_DIFFUSE,   upperLeg_mat_diffuse        );
            glMaterialfv( GL_FRONT,  GL_SPECULAR,  upperLeg_mat_specular    );
            glMaterialfv( GL_FRONT,  GL_SHININESS, upperLeg_mat_shininess    );
            glmDraw(upperLeg, GLM_SMOOTH);
            
            // Lower Leg
            glPushMatrix(); {
                glRotatef(lowerLegAngle, 1, 0, 0);
                glTranslatef(-0.1, -0.50, 0);
               
                glMaterialfv( GL_FRONT,     GL_DIFFUSE,lowerLeg_mat_diffuse        );
                glMaterialfv( GL_FRONT,  GL_SPECULAR,  lowerLeg_mat_specular    );
                glMaterialfv( GL_FRONT,  GL_SHININESS, lowerLeg_mat_shininess    );
                glmDraw(lowerLeg, GLM_SMOOTH);
            }glPopMatrix();
        }glPopMatrix();
        
    }glPopMatrix();
    /*
    glPushMatrix(); {
        // Locate Object
        glTranslatef(0, 0, 0);
        glRotatef(-90, 0, 1, 0);
        
        // Lower Leg
        glPushMatrix();{
            glTranslatef(0, lowerLegHeight, 0);
            glMaterialfv( GL_FRONT,     GL_DIFFUSE,   upperLeg_mat_diffuse        );
            glMaterialfv( GL_FRONT,  GL_SPECULAR,  upperLeg_mat_specular    );
            glMaterialfv( GL_FRONT,  GL_SHININESS, upperLeg_mat_shininess    );
            glmDraw(lowerLeg, GLM_SMOOTH);
        }glPopMatrix();
        
        
        // Uper Leg
        glPushMatrix();{
            // Position Object
            glTranslatef(0.1, lowerLegHeight + 0.50, 0);
            // Animation
            glPushMatrix(); {
                glRotatef(upperLegAngle, 1, 0, 0);
                glMaterialfv( GL_FRONT,     GL_DIFFUSE,   lowerLeg_mat_diffuse        );
                glMaterialfv( GL_FRONT,  GL_SPECULAR,  lowerLeg_mat_specular    );
                glMaterialfv( GL_FRONT,  GL_SHININESS, lowerLeg_mat_shininess    );
                glmDraw(upperLeg, GLM_SMOOTH);
            }glPopMatrix();
        }glPopMatrix();
    }glPopMatrix();
     */
    
   
}

void RightRobotLeg::animate() {
    upperLegAngle += upperLegBounce ? 3 : -3;
    lowerLegAngle += lowerLegBounce ? 3 : -3;
    
    if(upperLegAngle >= 50 || upperLegAngle <= 0) {
        upperLegBounce = !upperLegBounce;
    }
    
    if(lowerLegAngle >= 0 || lowerLegAngle <= -60) {
        lowerLegBounce = !lowerLegBounce;
    }
}


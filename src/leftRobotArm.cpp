#include "leftRobotArm.h"
#include "glm.h"

LeftRobotArm::LeftRobotArm() {
    lowerArm = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/antebrazo_R/antebrazo_derecho.obj");
    upperArm = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/hombro_R/hombro_R.obj");
    
    glmVertexNormals(lowerArm, 45.0f, false);
    glmVertexNormals(upperArm, 45.0f, false);
    
    glmFacetNormals(lowerArm);
    glmFacetNormals(upperArm);
    
    glmScale(lowerArm, 0.01);
    glmScale(upperArm, 0.01);
    
    upperArmAngle = 40;
    upperArmBounce = false;
    
    lowerArmAngle = -60;
    lowerArmBounce = true;
    
    /** Lower Leg Materials  **/
    upperArm_mat_specular       = new GLfloat[4]; //<------------------------Asignar memoria
    upperArm_mat_specular[0]    = 1.0f; //<----------------------------------S0r
    upperArm_mat_specular[1]    = 1.0f; //<----------------------------------S0g
    upperArm_mat_specular[2]    = 1.0f; //<----------------------------------S0b
    upperArm_mat_specular[3]    = 1.0f; //<----------------------------------S0a
    
    upperArm_mat_diffuse        = new GLfloat[4]; //<------------------------Asignar memoria
    upperArm_mat_diffuse[0]     = 0.0f; //<----------------------------------D0r
    upperArm_mat_diffuse[1]     = 0.0f; //<----------------------------------D0g
    upperArm_mat_diffuse[2]     = 0.0f; //<----------------------------------D0b
    upperArm_mat_diffuse[3]     = 1.0f; //<----------------------------------D0a
    
    upperArm_mat_shininess      = new GLfloat[1]; //<------------------------Asignar memoria
    upperArm_mat_shininess[0]   = 60.0f; //<---------------------------------Exponente especular del material 0
    
    /** Upper Leg Materials  **/
    lowerArm_mat_specular       = new GLfloat[4]; //<------------------------Asignar memoria
    lowerArm_mat_specular[0]    = 1.0f; //<----------------------------------S0r
    lowerArm_mat_specular[1]    = 1.0f; //<----------------------------------S0g
    lowerArm_mat_specular[2]    = 1.0f; //<----------------------------------S0b
    lowerArm_mat_specular[3]    = 1.0f; //<----------------------------------S0a
    
    lowerArm_mat_diffuse        = new GLfloat[4]; //<------------------------Asignar memoria
    lowerArm_mat_diffuse[0]     = 0.83f; //<----------------------------------D0r
    lowerArm_mat_diffuse[1]     = 0.69f; //<----------------------------------D0g
    lowerArm_mat_diffuse[2]     = 0.22f; //<----------------------------------D0b
    lowerArm_mat_diffuse[3]     = 1.0f; //<----------------------------------D0a
    
    lowerArm_mat_shininess     = new GLfloat[1]; //<------------------------Asignar memoria
    lowerArm_mat_shininess[0]   = 60.0f; //<---------------------------------Exponente especular del material 0
}

void LeftRobotArm::draw() {
    
    glPushMatrix();{
        glTranslatef(0, 0, 0);
        glRotatef(-90, 0, 1, 0);
        
        glPushMatrix(); {
            glTranslatef(-0.3, 1.1, 0);
            
            glTranslatef(0, 0.2, 0);
            glRotatef(upperArmAngle, 1, 0, 0);
            glTranslatef(0, -0.2, 0);
            
            glMaterialfv( GL_FRONT,     GL_DIFFUSE,   upperArm_mat_diffuse        );
            glMaterialfv( GL_FRONT,  GL_SPECULAR,  upperArm_mat_specular    );
            glMaterialfv( GL_FRONT,  GL_SHININESS, upperArm_mat_shininess    );
            glmDraw(upperArm, GLM_SMOOTH);
            
            glPushMatrix(); {
                glTranslatef(-0.15, -0.3, 0);
                //glRotatef(120, 1, 0, 0);
                
                glMaterialfv( GL_FRONT,     GL_DIFFUSE,   lowerArm_mat_diffuse        );
                glMaterialfv( GL_FRONT,  GL_SPECULAR,  lowerArm_mat_specular    );
                glMaterialfv( GL_FRONT,  GL_SHININESS, lowerArm_mat_shininess    );
                glmDraw(lowerArm, GLM_SMOOTH);
            }glPopMatrix();
        }glPopMatrix();
        /*
        glTranslatef(0, 1.1, -0.3);
        glRotatef(-90, 0, 1, 0);
        glMaterialfv( GL_FRONT,     GL_DIFFUSE,   upperArm_mat_diffuse        );
        glMaterialfv( GL_FRONT,  GL_SPECULAR,  upperArm_mat_specular    );
        glMaterialfv( GL_FRONT,  GL_SHININESS, upperArm_mat_shininess    );
        glmDraw(upperArm, GLM_SMOOTH);
        
        glTranslatef(-0.2, -0.3, 0);
        glMaterialfv( GL_FRONT,     GL_DIFFUSE,   lowerArm_mat_diffuse        );
        glMaterialfv( GL_FRONT,  GL_SPECULAR,  lowerArm_mat_specular    );
        glMaterialfv( GL_FRONT,  GL_SHININESS, lowerArm_mat_shininess    );
        glmDraw(lowerArm, GLM_SMOOTH);
         */
    }glPopMatrix();
    
}

void LeftRobotArm::animate() {
    upperArmAngle += upperArmBounce ? 3 : -3;
    lowerArmAngle += lowerArmBounce ? 3 : -3;
    
    if(upperArmAngle >= 40 || upperArmAngle <= -20) {
        upperArmBounce = !upperArmBounce;
    }
    
    if(lowerArmAngle >= 0 || lowerArmAngle <= -60) {
        lowerArmBounce = !lowerArmBounce;
    }
}



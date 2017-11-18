
#include "rightRobotArm.h"
#include "glm.h"
#include <stdio.h>

RightRobotArm::RightRobotArm(Color mainColor) {
    lowerArm = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/antebrazo_L.obj");
    upperArm = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/hombro_L.obj");
    
    glmVertexNormals(lowerArm, 45.0f, false);
    glmVertexNormals(upperArm, 45.0f, false);
    
    glmFacetNormals(lowerArm);
    glmFacetNormals(upperArm);
    
    glmScale(lowerArm, 0.01);
    glmScale(upperArm, 0.01);
    
    upperArmAngle = -20;
    upperArmBounce = true;
    
    lowerArmAngle = -60;
    lowerArmBounce = true;
    
    /** Upper Arm Material is always dark black  **/
    upperArm_mat_specular       = new GLfloat[4];
    upperArm_mat_specular[0]    = 0.0f;
    upperArm_mat_specular[1]    = 0.0f;
    upperArm_mat_specular[2]    = 0.0f;
    upperArm_mat_specular[3]    = 1.0f;
    
    upperArm_mat_diffuse        = new GLfloat[4];
    upperArm_mat_diffuse[0]     = 0.0f;
    upperArm_mat_diffuse[1]     = 0.0f;
    upperArm_mat_diffuse[2]     = 0.0f;
    upperArm_mat_diffuse[3]     = 1.0f;
    
    upperArm_mat_shininess      = new GLfloat[1];
    upperArm_mat_shininess[0]   = 60.0f;
    
    /** Lower Arm Material is main color  **/
    lowerArm_mat_specular       = new GLfloat[4];
    lowerArm_mat_specular[0]    = 1.0f;
    lowerArm_mat_specular[1]    = 1.0f;
    lowerArm_mat_specular[2]    = 1.0f;
    lowerArm_mat_specular[3]    = 1.0f;
    
    lowerArm_mat_diffuse        = new GLfloat[4];
    lowerArm_mat_diffuse[0]     = mainColor.r;
    lowerArm_mat_diffuse[1]     = mainColor.g;
    lowerArm_mat_diffuse[2]     = mainColor.b;
    lowerArm_mat_diffuse[3]     = 1.0f;
    
    lowerArm_mat_shininess     = new GLfloat[1];
    lowerArm_mat_shininess[0]   = 60.0f;
}

void RightRobotArm::draw() {
    
    glPushMatrix();{
        
        glTranslatef(0, 0, 0);
        glRotatef(-90, 0, 1, 0);
        
        glPushMatrix(); {
            glTranslatef(0.3, 1.1, 0);
            
            glTranslatef(0, 0.2, 0);
            glRotatef(upperArmAngle, 1, 0, 0);
            glTranslatef(0, -0.2, 0);
            
            glMaterialfv( GL_FRONT,     GL_DIFFUSE,   upperArm_mat_diffuse        );
            glMaterialfv( GL_FRONT,  GL_SPECULAR,  upperArm_mat_specular    );
            glMaterialfv( GL_FRONT,  GL_SHININESS, upperArm_mat_shininess    );
            glmDraw(upperArm, GLM_SMOOTH);
            
            glPushMatrix(); {
                glTranslatef(0.15, -0.3, 0);
                //glRotatef(120, 1, 0, 0);
                
                glMaterialfv( GL_FRONT,     GL_DIFFUSE,   lowerArm_mat_diffuse        );
                glMaterialfv( GL_FRONT,  GL_SPECULAR,  lowerArm_mat_specular    );
                glMaterialfv( GL_FRONT,  GL_SHININESS, lowerArm_mat_shininess    );
                glmDraw(lowerArm, GLM_SMOOTH);
            }glPopMatrix();
        }glPopMatrix();
        
    }glPopMatrix();
    
    
}

void RightRobotArm::animate() {
    upperArmAngle += upperArmBounce ? 3 : -3;
    lowerArmAngle += lowerArmBounce ? 3 : -3;
    
    if(upperArmAngle >= 40 || upperArmAngle <= -20) {
        upperArmBounce = !upperArmBounce;
    }
    
    if(lowerArmAngle >= 0 || lowerArmAngle <= -60) {
        lowerArmBounce = !lowerArmBounce;
    }
}


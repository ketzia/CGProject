#include "robotBody.h"
#include "glm.h"

RobotBody::RobotBody(Color mainColor) {
    torso = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/torso/torso.obj");
    
    glmVertexNormals(torso, 45.0f, false);
    glmFacetNormals(torso);
    glmScale(torso, 0.01);
    
    upperLegAngle = 0;
    upperLegBounce = true;
    
    lowerLegHeight = 0;
    lowerLegBounce = true;
    
    /** Torso Material **/
    torso_mat_specular       = new GLfloat[4];
    torso_mat_specular[0]    = 1.0f; //r
    torso_mat_specular[1]    = 1.0f; //g
    torso_mat_specular[2]    = 1.0f; //b
    torso_mat_specular[3]    = 1.0f; //a
    
    torso_mat_diffuse        = new GLfloat[4];
    torso_mat_diffuse[0]     = mainColor.r; //r
    torso_mat_diffuse[1]     = mainColor.g; //g
    torso_mat_diffuse[2]     = mainColor.b; //b
    torso_mat_diffuse[3]     = 1.0f;  //a
    
    torso_mat_shininess     = new GLfloat[1];
    torso_mat_shininess[0]   = 60.0f; // Amount of shininess
}

void RobotBody::draw() {
    
    glPushMatrix(); {
        glTranslatef(0, 0.8, 0);
        glRotatef(-90, 0, 1, 0);
        glMaterialfv(GL_FRONT,GL_DIFFUSE,torso_mat_diffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,torso_mat_specular);
        glMaterialfv(GL_FRONT,GL_SHININESS,torso_mat_shininess);
        glmDraw(torso, GLM_SMOOTH);
    }glPopMatrix();
    
    
}

void RobotBody::animate() {
    upperLegAngle += upperLegBounce ? 3.1 : -3.1;
    lowerLegHeight += lowerLegBounce ? 0.01 : -0.01;
    
    if(upperLegAngle >= 90 || upperLegAngle <= 0) {
        upperLegBounce = !upperLegBounce;
    }
    
    if(lowerLegHeight >= 0.3 || lowerLegHeight <= 0) {
        lowerLegBounce = !lowerLegBounce;
    }
}


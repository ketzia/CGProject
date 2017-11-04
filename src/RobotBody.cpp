#include "robotBody.h"
#include "glm.h"

RobotBody::RobotBody() {
    torso = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/torso/torso.obj");
    
    glmVertexNormals(torso, 45.0f, false);
    glmFacetNormals(torso);
    glmScale(torso, 0.01);
    
    upperLegAngle = 0;
    upperLegBounce = true;
    
    lowerLegHeight = 0;
    lowerLegBounce = true;
    
    /** Upper Leg Materials  **/
    torso_mat_specular       = new GLfloat[4]; //<------------------------Asignar memoria
    torso_mat_specular[0]    = 1.0f; //<----------------------------------S0r
    torso_mat_specular[1]    = 1.0f; //<----------------------------------S0g
    torso_mat_specular[2]    = 1.0f; //<----------------------------------S0b
    torso_mat_specular[3]    = 1.0f; //<----------------------------------S0a
    
    torso_mat_diffuse        = new GLfloat[4]; //<------------------------Asignar memoria
    torso_mat_diffuse[0]     = 0.83f; //<----------------------------------D0r
    torso_mat_diffuse[1]     = 0.69f; //<----------------------------------D0g
    torso_mat_diffuse[2]     = 0.22f; //<----------------------------------D0b
    torso_mat_diffuse[3]     = 1.0f; //<----------------------------------D0a
    
    torso_mat_shininess     = new GLfloat[1]; //<------------------------Asignar memoria
    torso_mat_shininess[0]   = 60.0f; //<---------------------------------Exponente especular del material 0
}

void RobotBody::draw() {
    
    glPushMatrix(); {
        glTranslatef(0, 0.8, 0);
        glRotatef(-90, 0, 1, 0);
        glMaterialfv( GL_FRONT,     GL_DIFFUSE,   torso_mat_diffuse        );
        glMaterialfv( GL_FRONT,  GL_SPECULAR,  torso_mat_specular    );
        glMaterialfv( GL_FRONT,  GL_SHININESS, torso_mat_shininess    );
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


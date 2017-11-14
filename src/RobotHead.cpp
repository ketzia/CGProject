#include "robotHead.h"
#include "glm.h"

RobotHead::RobotHead() {
    head = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/SoldierCut/Head/head.obj");
    
    glmVertexNormals(head, 45.0f, false);
    glmFacetNormals(head);
    
    glmScale(head, 0.01);
   
    /** Lower Leg Materials  **/
    head_mat_specular       = new GLfloat[4]; //<------------------------Asignar memoria
    head_mat_specular[0]    = 1.0f; //<----------------------------------S0r
    head_mat_specular[1]    = 1.0f; //<----------------------------------S0g
    head_mat_specular[2]    = 1.0f; //<----------------------------------S0b
    head_mat_specular[3]    = 1.0f; //<----------------------------------S0a
    
    head_mat_diffuse        = new GLfloat[4]; //<------------------------Asignar memoria
    head_mat_diffuse[0]     = 0.0f; //<----------------------------------D0r
    head_mat_diffuse[1]     = 0.0f; //<----------------------------------D0g
    head_mat_diffuse[2]     = 0.0f; //<----------------------------------D0b
    head_mat_diffuse[3]     = 1.0f; //<----------------------------------D0a
    
    head_mat_shininess      = new GLfloat[1]; //<------------------------Asignar memoria
    head_mat_shininess[0]   = 60.0f; //<---------------------------------Exponente especular del material 0
}

void RobotHead::draw() {
    
    glPushMatrix();{
        glTranslatef(0, 1.5, 0);
        glRotatef(-90, 0, 1, 0);
        //glMaterialfv( GL_FRONT,     GL_DIFFUSE,   head_mat_diffuse        );
        //glMaterialfv( GL_FRONT,  GL_SPECULAR,  head_mat_specular    );
        //glMaterialfv( GL_FRONT,  GL_SHININESS, head_mat_shininess    );
        glmDraw(head, GLM_SMOOTH );
    }glPopMatrix();
    
}

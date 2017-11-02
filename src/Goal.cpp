#include "goal.h"
#include "glm.h"

Goal::Goal(float positionX, float positionY, float positionZ, float rotationY) {
    model = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/goal.obj");
    //glmVertexNormals(model, 45.0f, false);
    //glmFacetNormals(model);
    //glmScale(model, 2.0f);
    this->positionX = positionX;
    this->positionY = positionY;
    this->positionZ = positionZ;
    this->rotationY = rotationY;
    
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
}

void Goal::draw() {
    //
    // Indicar propiedades del material con el que vamos a dibujar:
    glPushMatrix();{
        glMaterialfv( GL_FRONT,     GL_DIFFUSE,   mat_diffuse        );
        glMaterialfv( GL_FRONT,  GL_SPECULAR,  mat_specular    );
        glMaterialfv( GL_FRONT,  GL_SHININESS, mat_shininess    );
        glTranslatef(0, 0.1, positionZ);
        glRotatef(rotationY, 0, 1, 0);
        glmDraw(model, GLM_SMOOTH);
    }glPopMatrix();
    
}


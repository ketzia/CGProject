#include "soccerField.h"

SoccerField::SoccerField(float width, float depth, float posY, Color color) {
    this->posY = posY;
    this->color = color;
    field = new Rectangle(0.1,width,depth);
    
    soccerField = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/field2.obj");
    //soccerField = glmReadOBJ("/Users/ernesto/Desktop/field.obj");
    //glmVertexNormals(soccerField, 180, false);
    //glmFacetNormals(soccerField);
    glmScale(soccerField, 0.8);
    
    topLeft_b.x = -width;topLeft_b.y = posY;topLeft_b.z = -depth;
    lowLeft_b.x = -width;lowLeft_b.y = posY;lowLeft_b.z = depth;
    //goalOne = new Goal(-width/2, posY, -depth/2+1, -90);
    //goalTwo = new Goal(width/2, posY, depth/2-1, 90);
    skybox = new Skybox(60);
    
    mat_specular       = new GLfloat[4]; //<------------------------Asignar memoria
    mat_specular[0]    = 1.0f; //<----------------------------------S0r
    mat_specular[1]    = 1.0f; //<----------------------------------S0g
    mat_specular[2]    = 1.0f; //<----------------------------------S0b
    mat_specular[3]    = 1.0f; //<----------------------------------S0a
    
    mat_diffuse        = new GLfloat[4]; //<------------------------Asignar memoria
    mat_diffuse[0]     = 0.27f; //<----------------------------------D0r
    mat_diffuse[1]     = 0.47f; //<----------------------------------D0g
    mat_diffuse[2]     = 0.24f; //<----------------------------------D0b
    mat_diffuse[3]     = 1.0f; //<----------------------------------D0a
    
    mat_shininess      = new GLfloat[1]; //<------------------------Asignar memoria
    mat_shininess[0]   = 60.0f; //<---------------------------------Exponente especular del material 0
}

void SoccerField::draw() {
    
    // Draw soccer field
    glPushMatrix();{
        //glMaterialfv( GL_FRONT,     GL_DIFFUSE,   mat_diffuse        );
        //glMaterialfv( GL_FRONT,  GL_SPECULAR,  mat_specular    );
        //glMaterialfv( GL_FRONT,  GL_SHININESS, mat_shininess    );
        glTranslatef(0, posY, 0);
        //field->draw();
        glmDraw(soccerField,GLM_SMOOTH|GLM_TEXTURE|GLM_MATERIAL);
    }glPopMatrix();
   
    glPushMatrix(); {
        skybox->draw();
    }glPopMatrix();
    
    
}

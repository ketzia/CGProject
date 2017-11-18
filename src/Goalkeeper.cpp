#include "goalkeeper.h"
#include "soccerBall.h" // forward declaration https://stackoverflow.com/questions/4964482/how-to-create-two-classes-in-c-which-use-each-other-as-data

Goalkeeper::Goalkeeper(Color mainColor, float initialX, float initialZ) {
    model = glmReadOBJ("/Users/ernesto/Code/Graficas Computacionales/Models/Goalkeeper.obj");
    glmVertexNormals(model, 45.0f, false);
    glmFacetNormals(model);
    
    position.x = initialX;
    position.y = -1;
    position.z = initialZ;
    
    ballXPosition = 0;
    speed = 0.04;
    radius = 0.7f;
    
    // Goalkeeper material, color must be the same as the player
    goalkeeper_mat_specular       = new GLfloat[4];
    goalkeeper_mat_specular[0]    = 1.0f; //r
    goalkeeper_mat_specular[1]    = 1.0f; //g
    goalkeeper_mat_specular[2]    = 1.0f; //b
    goalkeeper_mat_specular[3]    = 1.0f; //a
    
    goalkeeper_mat_diffuse        = new GLfloat[4];
    goalkeeper_mat_diffuse[0]     = mainColor.r; //r
    goalkeeper_mat_diffuse[1]     = mainColor.g; //g
    goalkeeper_mat_diffuse[2]     = mainColor.b; //b
    goalkeeper_mat_diffuse[3]     = 1.0f;        //a
    
    goalkeeper_mat_shininess       = new GLfloat[1];
    goalkeeper_mat_shininess[0]   = 60.0f; // Amount of shininess
    
}

void Goalkeeper::draw() {
    glPushMatrix(); {
        //position.x += ballXPosition * speed;
        glTranslatef(position.x, position.y, position.z);
        glMaterialfv(GL_FRONT,GL_DIFFUSE,goalkeeper_mat_diffuse);
        glMaterialfv(GL_FRONT,GL_SPECULAR,goalkeeper_mat_specular);
        glMaterialfv(GL_FRONT,GL_SHININESS,goalkeeper_mat_shininess);
        glmDraw(model, GLM_SMOOTH);
        //glutWireSphere(radius, 20, 20);
    }glPopMatrix();
}

void Goalkeeper::followBall(SoccerBall* ball) {
    if(position.x < ball->position.x) {
        position.x += speed;
    }
    
    if(position.x > ball->position.x) {
        position.x -= speed;
    }
    
}


#include "skybox.h"

Skybox::Skybox(float size) {
    this->size = size;
    
    for( int t = 0; t < 6; t++ ) {
        glGenTextures(1, &targas[t].texID);
        glBindTexture(GL_TEXTURE_2D, targas[t].texID);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);    // default: GL_MODULATE
        
        // Use mipmaps
        glTexParameteri    (    GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST    );
        
        glTexParameteri    (    GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR    );
        glTexParameteri    (    GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
        glTexParameteri    (    GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT    );
        
        switch (t) {
            case 0: LoadTGA(&targas[t], "/Users/ernesto/Desktop/Skybox/front.tga");    break;
            case 1: LoadTGA(&targas[t], "/Users/ernesto/Desktop/Skybox/back.tga");    break;
            case 2: LoadTGA(&targas[t], "/Users/ernesto/Desktop/Skybox/left.tga");    break;
            case 3: LoadTGA(&targas[t], "/Users/ernesto/Desktop/Skybox/right.tga");    break;
            case 4: LoadTGA(&targas[t], "/Users/ernesto/Desktop/Skybox/right.tga");        break;
            case 5: LoadTGA(&targas[t], "/Users/ernesto/Desktop/Skybox/right.tga");    break;
        }
        
      
        gluBuild2DMipmaps(    GL_TEXTURE_2D,
                              3,
                              targas[t].width,
                              targas[t].height,
                              GL_RGB,
                              GL_UNSIGNED_BYTE,
                              targas[t].imageData            );
        
        glBindTexture    (    GL_TEXTURE_2D, 0   );
    }
}

Skybox::~Skybox(){
    glDeleteTextures( 1, &targas[0].texID );
    glDeleteTextures( 1, &targas[1].texID );
    glDeleteTextures( 1, &targas[2].texID );
    glDeleteTextures( 1, &targas[3].texID );
    glDeleteTextures( 1, &targas[4].texID );
    glDeleteTextures( 1, &targas[5].texID );
}


void Skybox::draw() {
    glPushMatrix();{
        
        glScalef(size, size, size);
        
        glBindTexture( GL_TEXTURE_2D, targas[0].texID );
        glBegin( GL_QUADS ); // FRONT
            //
            glNormal3f    (  0.0f,   0.0f,  1.0f   );
            glTexCoord2f(  0.0f,   0.0f             );
            glVertex3f    ( -1  , -1, 1  );
        
            glNormal3f    (  0.0f,   0.0f,  1.0f   );
            glTexCoord2f(  1.0f,   0.0f             );
            glVertex3f    (  1, -1, 1  );
        
            glNormal3f    (  0.0f,   0.0f,  1.0f   );
            glTexCoord2f(  1.0f,   1.0f             );
            glVertex3f    (  1,  1, 1  );
        
            glNormal3f    (  0.0f,   0.0f,  1.0f   );
            glTexCoord2f(  0.0f,   1.0f             );
            glVertex3f    ( -1,  1, 1  );
        glEnd();
        glBindTexture(GL_TEXTURE_2D, NULL);
        
        glBindTexture( GL_TEXTURE_2D, targas[2].texID );
        glBegin( GL_QUADS ); // RIGHT
            glNormal3f    (  1.0f,   0.0f,   0.0f  );
            glTexCoord2f(  0.0f,   0.0f             );
            glVertex3f    (  1, -1,  1 );
        
            glNormal3f    (  1.0f,   0.0f,   0.0f  );
            glTexCoord2f(  1.0f,   0.0f             );
            glVertex3f    (  1, -1, -1 );
        
            glNormal3f    (  1.0f,   0.0f,   0.0f  );
            glTexCoord2f(  1.0f,   1.0f             );
            glVertex3f    (  1,  1, -1 );
        
            glNormal3f    (  1.0f,   0.0f,   0.0f  );
            glTexCoord2f(  0.0f,   1.0f             );
            glVertex3f    (  1,  1,  1 );
        glEnd();
        glBindTexture(GL_TEXTURE_2D, NULL);
        
        glBindTexture( GL_TEXTURE_2D, targas[1].texID );
        glBegin( GL_QUADS ); // BACK
            glNormal3f    (  0.0f,   0.0f,  -1.0f  );
            glTexCoord2f(  0.0f,   0.0f             );
            glVertex3f    (  1, -1, -1 );
        
            glNormal3f    (  0.0f,   0.0f,  -1.0f  );
            glTexCoord2f(  1.0f,   0.0f             );
            glVertex3f    ( -1, -1, -1 );
        
            glNormal3f    (  0.0f,   0.0f,  -1.0f  );
            glTexCoord2f(  1.0f,   1.0f             );
            glVertex3f    ( -1,  1, -1 );
        
            glNormal3f    (  0.0f,   0.0f,  -1.0f  );
            glTexCoord2f(  0.0f,   1.0f             );
            glVertex3f    (  1,  1, -1 );
        glEnd();
        glBindTexture(GL_TEXTURE_2D, NULL);
        
        glBindTexture( GL_TEXTURE_2D, targas[3].texID );
        glBegin( GL_QUADS ); // LEFT
            glNormal3f    ( -1.0f,   0.0f,   0.0f  );
            glTexCoord2f(  0.0f,   0.0f             );
            glVertex3f    ( -1, -1, -1 );
        
            glNormal3f    ( -1.0f,   0.0f,   0.0f  );
            glTexCoord2f(  1.0f,   0.0f             );
            glVertex3f    ( -1, -1,  1 );
        
            glNormal3f    ( -1.0f,   0.0f,   0.0f  );
            glTexCoord2f(  1.0f,   1.0f             );
            glVertex3f    ( -1,  1,  1 );
        
            glNormal3f    ( -1.0f,   0.0f,   0.0f  );
            glTexCoord2f(  0.0f,   1.0f             );
            glVertex3f    ( -1,  1, -1 );
        glEnd();
        glBindTexture(GL_TEXTURE_2D, NULL);
        
        
    }glPopMatrix();
}

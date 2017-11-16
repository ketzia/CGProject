//
//  ambientProps.h
//  FinalProject
//
//  Created by ErnestoPM on 11/15/17.
//  Copyright © 2017 ErnestoPM. All rights reserved.
//

#ifndef ambientProps_h
#define ambientProps_h
#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <GLUT/glut.h>
    #include <math.h>
    #include <random>
#else
    #include "freeglut.h"
    #include <math.h>
#endif
#include <stdio.h>

class AmbientProps {
    
public:
    AmbientProps();
    ~AmbientProps();
    void draw();
    void animate();
    
private:
    float sunRotation;
    float moonRotation;
    float earthRotation;
    float venusRotation;
};



#endif /* ambientProps_h */

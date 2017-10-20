/*
* Ketzia Lizette Dante-Hidalgo Bouchot A01336592
* Ernesto Perez Martinez A01214919
*/

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
	#include <GLUT/glut.h>
	#include <math.h>
#else
	#include "freeglut.h"
	#include <stdio.h>
	#include <math.h>
#endif

#include "rectangle.h"
#include "vectors.h"
#include "soccerField.h"
#include "soccerBall.h"
#include "color.h"
#include <stdio.h>

SoccerField* soccerField;
Rectangle* rectangle;
SoccerBall* ball;

vector3 ballPosition;

float angle = 0.0f;
float lx=0.0f,lz=-1.0f;
float x=0.0f, z=5.0f;

float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

void computePos(float deltaMove) {
    x += deltaMove * lx * 0.1f;
    z += deltaMove * lz * 0.1f;
}

void OnMouseDown(int button, int state, int x, int y) {
    // only start motion if the left button is pressed
    if (button == GLUT_RIGHT_BUTTON) {
        
        // when the button is released
        if (state == GLUT_UP) {
            angle += deltaAngle;
            xOrigin = -1;
        }
        else  {// state = GLUT_DOWN
            xOrigin = x;
        }
    }
}

void OnMouseMove(int x, int y) {
    // this will only be true when the left button is down
    if (xOrigin >= 0) {
        
        // update deltaAngle
        deltaAngle = (x - xOrigin) * 0.001f;
        
        // update camera's direction
        lx = sin(angle + deltaAngle);
        lz = -cos(angle + deltaAngle);
    }
}

void init() {
    Color GRASS_GREEN;GRASS_GREEN.r = 0.27;GRASS_GREEN.g = 0.47;GRASS_GREEN.b = 0.24;
    Color RED;RED.r = 1.0;RED.g = 0.0;RED.b=0.0;
    ballPosition.x = 0.0;ballPosition.y = 0;ballPosition.z =0;

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
    soccerField = new SoccerField(14, 14, -1, GRASS_GREEN);
    ball = new SoccerBall(0.1,&(ballPosition),RED);

}

void display() {
    if (deltaMove)
        computePos(deltaMove);
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(x, 1.0, z,
              x+lx, 1.0, z+lz,
              0.0, 1.0, 0.0);
    soccerField->draw();
    ball->draw();
    //rectangle->draw();

	glutSwapBuffers();
}

void idle() {
	glutPostRedisplay();
    ballPosition.x += 0.01;
    ballPosition.z += 0.01;
    //printf("X-ball: %f\n",ballPosition.x);
}

void reshape(int x, int y) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
	gluLookAt(0.0, 3.0, 10.0,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
	display();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow(argv[0]);

	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
    
    glutMouseFunc(OnMouseDown);
    glutMotionFunc(OnMouseMove);

	glutMainLoop();
	return 0;
}

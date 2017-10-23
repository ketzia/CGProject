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
#include "playerNPC.h"

SoccerField* soccerField;
Rectangle* rectangle;
SoccerBall* ball;
PlayerNPC* player_one;
//PlayerNPC* player_two;

vector3 ballPosition, posPlayerOne, posPlayerTwo;

float angle = 0.0f;
float lx=0.0f,lz=-1.0f;
float x=0.0f, z=5.0f;
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

float speedPlayerOne, speedPlayerTwo, rotationPlayerOne, rotationPlayerTwo;

bool* pressedKeys;

void keyPressed(unsigned char key, int x, int y) {
    pressedKeys[key] = true;
    
    if(pressedKeys['w']) {
        speedPlayerOne = 0.05f;
    }
    
    if(pressedKeys['s']) {
        speedPlayerOne = -0.05f;
    }
    
    if(pressedKeys['a']) {
        rotationPlayerOne += 18;
    }
    
    if(pressedKeys['d']) {
        rotationPlayerOne -= 18;
    }
}

void keyUp(unsigned char key, int x, int y){
    pressedKeys[key] = false;
    
    if(key == 'w' || key == 's') {
        speedPlayerOne = 0.0f;
    }
    
}

void computePos(float deltaMove) {
    x += deltaMove * lx * 0.1f;
    z += deltaMove * lz * 0.1f;
}

void OnMouseDown(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_UP) {
            angle += deltaAngle;
            xOrigin = -1;
        } else  {
            xOrigin = x;
        }
    }
}
void OnMouseMove(int x, int y) {
    if (xOrigin >= 0) {
        deltaAngle = (x - xOrigin) * 0.001f;
        lx = sin(angle + deltaAngle);
        lz = -cos(angle + deltaAngle);
    }
}

void init() {
    // Array to store all keys
    pressedKeys = new bool[256];
    
    // Color constants
    Color GRASS_GREEN;GRASS_GREEN.r = 0.27;GRASS_GREEN.g = 0.47;GRASS_GREEN.b = 0.24;
    Color RED;RED.r = 1.0;RED.g = 0.0;RED.b=0.0;
    Color DEEPSKYBLUE;DEEPSKYBLUE.r = 0.0;DEEPSKYBLUE.g = 0.75; DEEPSKYBLUE.b = 1.0;
    Color MONZA;MONZA.r = 0.81;MONZA.g = 0.0;MONZA.b = 0.06;
    
    // Character positions
    ballPosition.x = 0.0;ballPosition.y = 0;ballPosition.z =0;
    posPlayerOne.x = -1.0;posPlayerOne.y = 0;posPlayerOne.z =0;
    posPlayerTwo.x = 1.0;posPlayerTwo.y = 0;posPlayerTwo.z =0;
    
    // Character rotations
    rotationPlayerOne = 0.0f;
    rotationPlayerTwo = 0.0f;
    
    // Character speeds
    speedPlayerOne = 0;
    speedPlayerTwo = 0;
    
    // OpenGL Code
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    
    // Instantiate all Characters
    soccerField = new SoccerField(14, 14, -1, GRASS_GREEN);
    ball = new SoccerBall(0.1,&(ballPosition),RED);
    player_one = new PlayerNPC(0.2, 0.2, &(rotationPlayerOne), &(speedPlayerOne), DEEPSKYBLUE);
    //player_two = new PlayerNPC(0.7, 0.1, &(rotationPlayerTwo), MONZA);

}

void display() {
    
    if (deltaMove) {
        computePos(deltaMove);
    }
    
    if(rotationPlayerOne > 360) {
        rotationPlayerOne = rotationPlayerOne - 360;
    }
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(x, 1.0, z,
              x+lx, 1.0, z+lz,
              0.0, 1.0, 0.0);
    
    // Draw objects
    soccerField->draw();
    ball->draw();
    player_one->draw();
    //player_two->draw();

	glutSwapBuffers();
}

void idle() {
	glutPostRedisplay();
}

void reshape(int x, int y) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
	gluLookAt(0.0, 3.0, 10.0,0.0, 0.0, 0.0,0.0, 1.0, 0.0);
	display();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow(argv[0]);

	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyUp);
    glutMouseFunc(OnMouseDown);
    glutMotionFunc(OnMouseMove);

	glutMainLoop();
	return 0;
}

/*
* Ketzia Lizette Dante-Hidalgo Bouchot A01336592
* Ernesto Perez Martinez A01214919
*
 * Disclaimer: Some times both players share the same rotations and positions, we havent found the cause for this issue but we are
 working on it, if it happens just restart the app until all characters can move independently
 
 Keys for player one: WASD
 Keys for player two: IJKL
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
#include "utils.h"

// Objects
SoccerField* soccerField;
Rectangle* rectangle;
SoccerBall* ball;
PlayerNPC* player_one;
PlayerNPC* player_two;

// Position of the ball to be used later
vector3 ballPosition;

// Definitions for Player
float speedPlayerOne;
float speedPlayerTwo;
float rotationPlayerOne;
float rotationPlayerTwo;

// Definitions for the camera
float radius;
float worldRotation;
float deltaMov;
int isCameraMoving;

// Array to store all pressed keys
bool* pressedKeys;

void init() {
    // Array to store all keys pressed so far
    pressedKeys = new bool[256];
    
    // Set up initial values for the camera, it is going to be turned in a radius of 9.0
    deltaMov = 0.0f;
    isCameraMoving = -1;
    worldRotation = 0.0f;
    radius = 5.0f;
    
    // Color constants
    Color GRASS_GREEN;GRASS_GREEN.r = 0.27;GRASS_GREEN.g = 0.47;GRASS_GREEN.b = 0.24;
    Color RED;RED.r = 1.0;RED.g = 0.0;RED.b=0.0;
    Color DEEPSKYBLUE;DEEPSKYBLUE.r = 0.0;DEEPSKYBLUE.g = 0.75; DEEPSKYBLUE.b = 1.0;
    Color MONZA;MONZA.r = 0.81;MONZA.g = 0.0;MONZA.b = 0.06;
    
    // Positions
    ballPosition.x = 0.0;ballPosition.y = 0;ballPosition.z =0;
    
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
    
    // Instantiate all Characters, this is going to be changed for models in the future
    soccerField = new SoccerField(14, 28, -1, GRASS_GREEN);
    ball = new SoccerBall(0.1,&(ballPosition),RED);
    player_one = new PlayerNPC(&(rotationPlayerOne), &(speedPlayerOne), DEEPSKYBLUE);
    player_two = new PlayerNPC(&(rotationPlayerTwo), &(speedPlayerTwo), MONZA);
    
}



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
    
    if(pressedKeys['i']) {
        speedPlayerTwo = 0.05f;
    }
    if(pressedKeys['k']) {
        speedPlayerTwo = -0.05f;
    }
    if(pressedKeys['j']) {
        rotationPlayerTwo += 18;
    }
    if(pressedKeys['l']) {
        rotationPlayerTwo -= 18;
    }
    
}

void keyUp(unsigned char key, int x, int y){
    pressedKeys[key] = false;
    
    if(key == 'w' || key == 's') {
        speedPlayerOne = 0.0f;
    }
    
    if(key == 'i' || key == 'k') {
        speedPlayerTwo = 0.0f;
    }
    
}



void OnMouseDown(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_UP) {
            //angle += deltaAngle;
            isCameraMoving = -1;
            //worldRotation += 5.0f;
            //printf("moving something lol /n");
        } else  {
            isCameraMoving = x;
        }
    }
}
void OnMouseMove(int x, int y) {
    if (isCameraMoving >= 0) {
        deltaMov = (x - isCameraMoving) * 0.01f;
        worldRotation += deltaMov;
    }
}

void display() {
    
  

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //gluLookAt(x, 1.0, z,
      //        x+lx, 1.0, z+lz,
        //      0.0, 1.0, 0.0);
    
    //gluLookAt(<#GLdouble eyeX#>, <#GLdouble eyeY#>, <#GLdouble eyeZ#>, <#GLdouble centerX#>, <#GLdouble centerY#>, <#GLdouble centerZ#>, <#GLdouble upX#>, <#GLdouble upY#>, <#GLdouble upZ#>)
    gluLookAt(radius * cos(toRadians(worldRotation)), 3 ,radius * sin(toRadians(worldRotation)),
              0, 0.2, 0,
              0.0, 1.0, 0.0);
    
    // Draw objects
    glPushMatrix();{
        soccerField->draw();
        ball->draw();
        player_one->draw();
        player_two->draw();
    }glPopMatrix();
   

	glutSwapBuffers();
}

void idle() {
	glutPostRedisplay();
    //worldRotation += 0.1f;
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

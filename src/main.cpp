/*
* Ketzia Lizette Dante-Hidalgo Bouchot A01336592
* Ernesto Perez Martinez A01214919
*
 * Disclaimer: Bug fixed! it was the array of booleans that was checking the pressed keys -.-
 
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

// Lights
GLfloat*    light0_position; //<-------------------------------------Light 0 - location
GLfloat*    light0_diffuse; //<--------------------------------------Light 0 - diffuse
GLfloat*    light0_specular; //<-------------------------------------Light 0 - specular
GLfloat*    light0_ambient; //<--------------------------------------Light 0 - ambient

GLfloat*    light1_position; //<-------------------------------------Light 1 - location
GLfloat*    light1_diffuse; //<--------------------------------------Light 1 - diffuse
GLfloat*    light1_specular; //<-------------------------------------Light 1 - specular
GLfloat*    light1_ambient; //<--------------------------------------Light 1 - ambient//<--------------------------------------Ambiente global

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
float ballSpeed;

// Definitions for the camera
float radius;
float worldRotation;
float deltaMov;
int isCameraMoving;

// Array to store all pressed keys
bool* pressedKeys;

bool playerOneHasBall;
bool playerTwoHasBall;

void setupLighting() {
    //->LIGHT 0 begins
    light0_position        = new GLfloat[4]; //<------------------------Reserve memory
    light0_position[0]    = 5.0f; //<----------------------------------L0x
    light0_position[1]    = 1.0f; //<----------------------------------L0y
    light0_position[2]    = 1.0f; //<----------------------------------L0z
    light0_position[3]    = 0.0f; //<----------------------------------L0w
    
    light0_specular        = new GLfloat[4]; //<------------------------Reserve memory
    light0_specular[0]    = 1.0f; //<----------------------------------L0Sr
    light0_specular[1]    = 1.0f; //<----------------------------------L0Sg
    light0_specular[2]    = 1.0f; //<----------------------------------L0Sb
    light0_specular[3]    = 1.0f; //<----------------------------------L0Sa
    
    light0_diffuse        = new GLfloat[4]; //<------------------------Reserve memory
    light0_diffuse[0]    = 0.16f; //<----------------------------------L0Dr
    light0_diffuse[1]    = 0.5f; //<----------------------------------L0Dg
    light0_diffuse[2]    = 0.73f; //<----------------------------------L0Db
    light0_diffuse[3]    = 1.0f; //<----------------------------------L0Da
    
    light0_ambient        = new GLfloat[4]; //<------------------------Reserve memory
    light0_ambient[0]    = 0.1f; //<----------------------------------L0Ar
    light0_ambient[1]    = 0.1f; //<----------------------------------L0Ag
    light0_ambient[2]    = 0.1f; //<----------------------------------L0Ab
    light0_ambient[3]    = 0.5f; //<----------------------------------L0Aa
    //<-LIGHT 0 ends
    
    //->LIGHT 1 begins
    light1_position        = new GLfloat[4]; //<------------------------Reserve memory
    light1_position[0]    = -5.0f; //<---------------------------------L1x
    light1_position[1]    =  1.0f; //<---------------------------------L1y
    light1_position[2]    =  1.0f; //<---------------------------------L1z
    light1_position[3]    =  0.0f; //<---------------------------------L1w
    
    light1_specular        = new GLfloat[4]; //<------------------------Reserve memory
    light1_specular[0]    = 1.0f; //<----------------------------------L1Sr
    light1_specular[1]    = 1.0f; //<----------------------------------L1Sg
    light1_specular[2]    = 1.0f; //<----------------------------------L1Sb
    light1_specular[3]    = 1.0f; //<----------------------------------L1Sa
    
    light1_diffuse        = new GLfloat[4]; //<------------------------Reserve memory
    light1_diffuse[0]    = 0.61f; //<----------------------------------L1Dr
    light1_diffuse[1]    = 0.35f; //<----------------------------------L1Dg
    light1_diffuse[2]    = 0.71f; //<----------------------------------L1Db
    light1_diffuse[3]    = 1.0f; //<----------------------------------L1Da
    
    light1_ambient        = new GLfloat[4]; //<------------------------Reserve memory
    light1_ambient[0]    = 0.1f; //<----------------------------------L1Ar
    light1_ambient[1]    = 0.1f; //<----------------------------------L1Ag
    light1_ambient[2]    = 0.1f; //<----------------------------------L1Ab
    light1_ambient[3]    = 0.5f; //<----------------------------------L1Aa
    //<-LIGHT 1 ends
    
    // Configure LIGHT 0:
    glLightfv( GL_LIGHT0, GL_POSITION,  light0_position );
    glLightfv( GL_LIGHT0, GL_AMBIENT,   light0_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE,   light0_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR,  light0_specular);
    // Configure LIGHT 1:
    glLightfv( GL_LIGHT1, GL_POSITION,  light1_position );
    glLightfv( GL_LIGHT1, GL_AMBIENT,   light1_ambient);
    glLightfv( GL_LIGHT1, GL_DIFFUSE,   light1_diffuse);
    glLightfv( GL_LIGHT1, GL_SPECULAR,  light1_specular);
    // Enable LIGHT 0:
    glEnable( GL_LIGHT0 );
    // Enable LIGHT 1:
    glEnable( GL_LIGHT1 );
    // Enable lighting:
    glEnable( GL_LIGHTING );
}


void init() {
    glClearColor(0.2, 0.2, 0.2, 1.0);
    glShadeModel(GL_SMOOTH);
    setupLighting();
    // Light setup
    //glEnable(GL_NORMALIZE);
    
    // Array to store all keys pressed so far
    pressedKeys = new bool[256]();
    
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
    ballPosition.x = 0.0;ballPosition.y = -0.8;ballPosition.z =0;
    
    // Character rotations
    rotationPlayerOne = 45;
    rotationPlayerTwo = -45;
    
    // Character speeds
    speedPlayerOne = 0;
    speedPlayerTwo = 0;
    ballSpeed = 0.0f;
    
    // Helper flags for ball logic
    playerOneHasBall = false;
    playerTwoHasBall = false;
    
    
    // OpenGL Code
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Instantiate all Characters, this is going to be changed for models in the future
    soccerField = new SoccerField(14, 28, -1, GRASS_GREEN);
    player_one = new PlayerNPC(&(rotationPlayerOne), &(speedPlayerOne), DEEPSKYBLUE, 1);
    player_two = new PlayerNPC(&(rotationPlayerTwo), &(speedPlayerTwo), MONZA, -1);
    
    ball = new SoccerBall(&(ballSpeed));
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
    
    if(pressedKeys['q']) {
        if(playerOneHasBall){
            // Do logic to send ball flying forward
            //ball->setDirectionVector();
            //ball->dettachPlayer();
            ball->setDirectionVector();
            ball->isMoving = true;
            ballSpeed = 0.2f;
        }
    }
    
    if(pressedKeys['u']) {
        if(playerTwoHasBall){
            //ball->dettachPlayer();
            ball->setDirectionVector();
            ball->isMoving = true;
            ballSpeed = 0.2f;
            // Do logic to send ball flying forward too
        }
    }
    
}

void keyUp(unsigned char key, int x, int y){
    
    
    if(key == 'w' || key == 's') {
        speedPlayerOne = 0.0f;
    }
    
    if(key == 'i' || key == 'k') {
        speedPlayerTwo = 0.0f;
    }
    
    pressedKeys[key] = false;
    
}



void OnMouseDown(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_UP) {
            isCameraMoving = -1;
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

void checkCollisions() {
    if(ball->inCollisionWithPlayer(player_one) && !ball->isMoving) {
        ball->setPosition(player_one->position.x, player_one->position.z);
        playerOneHasBall = true;
        playerTwoHasBall = false;
    }
    
    if(ball->inCollisionWithPlayer(player_two) && !ball->isMoving){
        ball->setPosition(player_two->position.x, player_two->position.z);
        playerTwoHasBall = true;
        playerOneHasBall = false;
    }
}

void display() {
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(radius * cos(toRadians(worldRotation)), 3 ,radius * sin(toRadians(worldRotation)),
              0, 2, 0,
              0.0, 1.0, 0.0);
    
    // Draw objects
    glPushMatrix();{
        soccerField->draw();
        ball->draw();
    }glPopMatrix();
    
    glPushMatrix(); {
        player_one->draw();
    }glPopMatrix();
   
    glPushMatrix(); {
        player_two->draw();
    }glPopMatrix();

    checkCollisions();
	glutSwapBuffers();
}


void idle() {
	glutPostRedisplay();
    
    if(speedPlayerOne != 0) {
        player_one->animate();
    }
    
    if(speedPlayerTwo != 0)  {
        player_two->animate();
    }
    
    if(ballSpeed < 0) {
        ballSpeed = 0;
    }else if(ballSpeed == 0) {
        ball->isMoving=false;
    }else if(ballSpeed > 0){
        ballSpeed -= 0.001f;
    }
    
    //if(ballSpeed < 0) {
        //ballSpeed = 0;
    //}
    
    //if(ballSpeed > 0) {
        //ballSpeed -= 0.1f;
    //}
    
    //glEnable(GL_NORMALIZE);
    //worldRotation += 0.1f;
    //printf("Speed player one: %f \n", speedPlayerOne);
    //printf("Speed player two: %f \n", speedPlayerTwo);
}

void reshape(int x, int y) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80.0, (GLdouble)x / (GLdouble)y, 0.5, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);
	gluLookAt(0.0, 3.0, 10.0,0.0, 0.0, 0.0,0.0, 1.0, 0.0);
	display();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutInitWindowSize(1200, 800);
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

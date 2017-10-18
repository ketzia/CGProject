#pragma once
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

#include "cWheel.h"

class Car
{
public:
	Car();
	~Car();

	void draw();

	// Instance these in the constructor:
	Wheel* first;
	Wheel* second;
	Wheel* third;
	Wheel* fourth;
	float zRot;
};


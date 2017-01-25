#ifndef OPENGL_TEST_MAIN_H
#define OPENGL_TEST_MAIN_H

#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(__APPLE__)
#include <GLUT/GLUT.h>
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>
#else
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#include <windows.h>
#endif
#include <GL/glew.h>		// must be downloaded
#include <GL/freeglut.h>	// must be downloaded unless you have an Apple
#endif

#include "source.h"
#include "vec4.h"
#include "FullScreenTexturedQuad.h"

const unsigned int windowWidth = 600, windowHeight = 600;

// OpenGL major and minor versions
int majorVersion = 3, minorVersion = 0;

unsigned int shaderProgram;

int main(int argc, char * argv[]);
void getErrorInfo(unsigned int handle);
void checkShader(unsigned int shader, char * message);
void checkLinking(unsigned int program);
void onInitialization();
void onExit();
void onDisplay();
void onKeyboard(unsigned char key, int pX, int pY);
void onKeyboardUp(unsigned char key, int pX, int pY);
void onMouse(int button, int state, int pX, int pY);
void onMouseMotion(int pX, int pY);
void onIdle();

#endif //OPENGL_TEST_MAIN_H

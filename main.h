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

#include "vec4.h"
#include "FullScreenTexturedQuad.h"

const unsigned int windowWidth = 600, windowHeight = 600;

// OpenGL major and minor versions
int majorVersion = 3, minorVersion = 0;

unsigned int shaderProgram;

// vertex shader in GLSL
const char *vertexSource = R"(
	#version 130
    precision highp float;

	in vec2 vertexPosition;		// variable input from Attrib Array selected by glBindAttribLocation
	out vec2 texcoord;			// output attribute: texture coordinate

	void main() {
		texcoord = (vertexPosition + vec2(1, 1))/2;							// -1,1 to 0,1
		gl_Position = vec4(vertexPosition.x, vertexPosition.y, 0, 1); 		// transform to clipping space
	}
)";

// fragment shader in GLSL
const char *fragmentSource = R"(
	#version 130
    precision highp float;

	uniform sampler2D textureUnit;
	in  vec2 texcoord;			// interpolated texture coordinates
	out vec4 fragmentColor;		// output that goes to the raster memory as told by glBindFragDataLocation

	void main() {
		fragmentColor = texture(textureUnit, texcoord);
	}
)";

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

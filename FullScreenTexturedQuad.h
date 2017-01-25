#ifndef OPENGL_TEST_FULLSCREENTEXTUREDQUAD_H
#define OPENGL_TEST_FULLSCREENTEXTUREDQUAD_H

#include <GL/glew.h>

#include "vec4.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

class FullScreenTexturedQuad {
    unsigned int vao, textureId;	// vertex array object id and texture id
    unsigned int shaderProgram;
public:
    void Create(vec4 image[WINDOW_WIDTH * WINDOW_HEIGHT]);
    void Draw();
};


#endif //OPENGL_TEST_FULLSCREENTEXTUREDQUAD_H

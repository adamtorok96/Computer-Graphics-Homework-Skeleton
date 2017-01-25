#ifndef OPENGL_TEST_LINESTRIP_H
#define OPENGL_TEST_LINESTRIP_H

#include <cstdio>

#include <GL/glew.h>

#include "vec4.h"
#include "Camera.h"

class LineStrip {
    GLuint vao, vbo;        // vertex array object, vertex buffer object
    float  vertexData[100]; // interleaved data of coordinates and colors
    int    nVertices;       // number of vertices
public:
    LineStrip() {
        nVertices = 0;
    }

    void Create();
    void AddPoint(Camera &camera, float cX, float cY);
    void Draw(Camera &camera, unsigned int shaderProgram);


};


#endif //OPENGL_TEST_LINESTRIP_H

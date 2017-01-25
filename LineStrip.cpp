#include "LineStrip.h"

void LineStrip::Create() {
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo); // Generate 1 vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // Enable the vertex attribute arrays
    glEnableVertexAttribArray(0);  // attribute array 0
    glEnableVertexAttribArray(1);  // attribute array 1
    // Map attribute array 0 to the vertex data of the interleaved vbo
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), reinterpret_cast<void*>(0)); // attribute array, components/attribute, component type, normalize?, stride, offset
    // Map attribute array 1 to the color data of the interleaved vbo
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), reinterpret_cast<void*>(2 * sizeof(float)));
}

void LineStrip::AddPoint(Camera &camera, float cX, float cY) {
    if (nVertices >= 20) return;

    vec4 wVertex = vec4(cX, cY, 0, 1) * camera.Pinv() * camera.Vinv();
    // fill interleaved data
    vertexData[5 * nVertices] = wVertex.v[0];
    vertexData[5 * nVertices + 1] = wVertex.v[1];
    vertexData[5 * nVertices + 2] = 1; // red
    vertexData[5 * nVertices + 3] = 1; // green
    vertexData[5 * nVertices + 4] = 0; // blue
    nVertices++;
    // copy data to the GPU
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, nVertices * 5 * sizeof(float), vertexData, GL_DYNAMIC_DRAW);
}

void LineStrip::Draw(Camera &camera, unsigned int shaderProgram) {
    if (nVertices > 0) {
        mat4 VPTransform = camera.V() * camera.P();

        int location = glGetUniformLocation(shaderProgram, "MVP");

        if (location >= 0)
            glUniformMatrix4fv(location, 1, GL_TRUE, VPTransform);
        else
            printf("uniform MVP cannot be set\n");

        glBindVertexArray(vao);
        glDrawArrays(GL_LINE_STRIP, 0, nVertices);
    }
}
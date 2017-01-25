#include "Triangle.h"

void Triangle::Create() {
    glGenVertexArrays(1, &vao);	// create 1 vertex array object
    glBindVertexArray(vao);		// make it active

    unsigned int vbo[2];		// vertex buffer objects
    glGenBuffers(2, &vbo[0]);	// Generate 2 vertex buffer objects

    // vertex coordinates: vbo[0] -> Attrib Array 0 -> vertexPosition of the vertex shader
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); // make it active, it is an array
    static float vertexCoords[] = { -8, -8, -6, 10, 8, -2 };	// vertex data on the CPU
    glBufferData(GL_ARRAY_BUFFER,      // copy to the GPU
                 sizeof(vertexCoords),  // number of the vbo in bytes
                 vertexCoords,		   // address of the data array on the CPU
                 GL_STATIC_DRAW);	   // copy to that part of the memory which is not modified
    // Map Attribute Array 0 to the current bound vertex buffer (vbo[0])
    glEnableVertexAttribArray(0);
    // Data organization of Attribute Array 0
    glVertexAttribPointer(0,			// Attribute Array 0
                          2, GL_FLOAT,  // components/attribute, component type
                          GL_FALSE,		// not in fixed point format, do not normalized
                          0, NULL);     // stride and offset: it is tightly packed

    // vertex colors: vbo[1] -> Attrib Array 1 -> vertexColor of the vertex shader
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]); // make it active, it is an array
    static float vertexColors[] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };	// vertex data on the CPU
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColors), vertexColors, GL_STATIC_DRAW);	// copy to the GPU

    // Map Attribute Array 1 to the current bound vertex buffer (vbo[1])
    glEnableVertexAttribArray(1);  // Vertex position
    // Data organization of Attribute Array 1
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL); // Attribute Array 1, components/attribute, component type, normalize?, tightly packed
}

void Triangle::Animate(float t) {
    sx = 1; // *sinf(t);
    sy = 1; // *cosf(t);
    wTx = 0; // 4 * cosf(t / 2);
    wTy = 0; // 4 * sinf(t / 2);
}

void Triangle::Draw(Camera &camera, unsigned int shaderProgram) {
    mat4 M(sx, 0, 0, 0,
           0, sy, 0, 0,
           0, 0, 0, 0,
           wTx, wTy, 0, 1); // model matrix

    mat4 MVPTransform = M * camera.V() * camera.P();

    // set GPU uniform matrix variable MVP with the content of CPU variable MVPTransform
    int location = glGetUniformLocation(shaderProgram, "MVP");
    if (location >= 0) glUniformMatrix4fv(location, 1, GL_TRUE, MVPTransform); // set uniform variable MVP to the MVPTransform
    else printf("uniform MVP cannot be set\n");

    glBindVertexArray(vao);	// make the vao and its vbos active playing the role of the data source
    glDrawArrays(GL_TRIANGLES, 0, 3);	// draw a single triangle with vertices defined in vao
}
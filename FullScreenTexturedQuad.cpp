#include "FullScreenTexturedQuad.h"

void FullScreenTexturedQuad::Create(vec4 image[WINDOW_WIDTH * WINDOW_HEIGHT]) {
    glGenVertexArrays(1, &vao);	// create 1 vertex array object
    glBindVertexArray(vao);		// make it active

    unsigned int vbo;		// vertex buffer objects
    glGenBuffers(1, &vbo);	// Generate 1 vertex buffer objects

    // vertex coordinates: vbo[0] -> Attrib Array 0 -> vertexPosition of the vertex shader
    glBindBuffer(GL_ARRAY_BUFFER, vbo); // make it active, it is an array
    static float vertexCoords[] = { -1, -1,   1, -1,  -1, 1,
                                    1, -1,   1,  1,  -1, 1 };	// two triangles forming a quad
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexCoords), vertexCoords, GL_STATIC_DRAW);	   // copy to that part of the memory which is not modified

    // Map Attribute Array 0 to the current bound vertex buffer (vbo[0])
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE,	0, NULL);     // stride and offset: it is tightly packed

    // Create objects by setting up their vertex data on the GPU
    glGenTextures(1, &textureId);  				// id generation
    glBindTexture(GL_TEXTURE_2D, textureId);    // binding

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, WINDOW_WIDTH, WINDOW_HEIGHT, 0, GL_RGBA, GL_FLOAT, image); // To GPU
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); // sampling
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void FullScreenTexturedQuad::Draw() {
    glBindVertexArray(vao);	// make the vao and its vbos active playing the role of the data source

    int location = glGetUniformLocation(shaderProgram, "textureUnit");

    if (location >= 0) {
        glUniform1i(location, 0);		// texture sampling unit is TEXTURE0
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureId);	// connect the texture to the sampler
    }

    glDrawArrays(GL_TRIANGLES, 0, 6);	// draw two triangles forming a quad
}
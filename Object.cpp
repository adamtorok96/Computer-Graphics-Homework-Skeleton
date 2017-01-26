#include "Object.h"

Object::Object() {
    scaleX = 1;
    scaleY = 1;

    translationX = 0;
    translationY = 0;
}

void Object::create() {
    glGenVertexArrays(1, &vao);
}

void Object::transform(Camera &camera, unsigned int shaderProgram) {
    mat4 M(scaleX, 0, 0, 0,
           0, scaleY, 0, 0,
           0, 0, 0, 0,
           translationX, translationY, 0, 1);

    mat4 MVPTransform = M * camera.V() * camera.P();

    int location = glGetUniformLocation(shaderProgram, "MVP");

    if ( location >= 0 )
        glUniformMatrix4fv(location, 1, GL_TRUE, MVPTransform);
}

void Object::scale(float x, float y) {
    scaleX = x;
    scaleY = y;
}

void Object::translate(float x, float y) {
    translationX = x;
    translationY = y;
}

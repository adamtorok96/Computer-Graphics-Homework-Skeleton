#include "Triangle.h"

Triangle::Triangle(vec3 a, vec3 b, vec3 c, vec3 color) {
    this->a = a;
    this->b = b;
    this->c = c;
    this->color = color;
}

void Triangle::create() {
    Object::create();

    glBindVertexArray(vao);		// make it active

    unsigned int vbo[2];		// vertex buffer objects
    glGenBuffers(2, &vbo[0]);	// Generate 2 vertex buffer objects

    // vertex coordinates: vbo[0] -> Attrib Array 0 -> vertexPosition of the vertex shader
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]); // make it active, it is an array

    float vertexCoords[] = {
            a.x, a.y, a.z,
            b.x, b.y, b.z,
            c.x, c.y, c.z
    };

    glBufferData(GL_ARRAY_BUFFER,      // copy to the GPU
                 sizeof(vertexCoords),  // number of the vbo in bytes
                 vertexCoords,		   // address of the data array on the CPU
                 GL_STATIC_DRAW);	   // copy to that part of the memory which is not modified

    // Map Attribute Array 0 to the current bound vertex buffer (vbo[0])
    glEnableVertexAttribArray(0);
    // Data organization of Attribute Array 0
    glVertexAttribPointer(0,			// Attribute Array 0
                          3, GL_FLOAT,  // components/attribute, component type
                          GL_FALSE,		// not in fixed point format, do not normalized
                          0, NULL);     // stride and offset: it is tightly packed

    // vertex colors: vbo[1] -> Attrib Array 1 -> vertexColor of the vertex shader
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]); // make it active, it is an array
    //static float vertexColors[] = { 1, 1, 1, 0, 1, 1, 1, 0, 1 };	// vertex data on the CPU
    float vertexColors[] = {
            color.x, color.y, color.z,
            color.x, color.y, color.z,
            color.x, color.y, color.z
    };
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColors), vertexColors, GL_STATIC_DRAW);	// copy to the GPU

    // Map Attribute Array 1 to the current bound vertex buffer (vbo[1])
    glEnableVertexAttribArray(1);  // Vertex position
    // Data organization of Attribute Array 1
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL); // Attribute Array 1, components/attribute, component type, normalize?, tightly packed
}

void Triangle::draw(Camera &camera, unsigned int shaderProgram) {
    transform(camera, shaderProgram);

    glBindVertexArray(vao);	// make the vao and its vbos active playing the role of the data source
    glDrawArrays(GL_TRIANGLES, 0, 3);	// draw a single triangle with vertices defined in vao
}

void Triangle::animate(float t) {
    //sx = 1; // *sinf(t);
    //sy = 1; // *cosf(t);
    //wTx = 0; // 4 * cosf(t / 2);
    //wTy = 0; // 4 * sinf(t / 2);
}

void Triangle::control() {

}

Hit Triangle::intersect(const Ray &ray) {
    Hit hit(-1);

    //Find vectors for two edges sharing V1
    vec3 e1 = b - a;
    vec3 e2 = c - a;

    //Begin calculating determinant - also used to calculate u parameter
    vec3 P = ray.dir.cross(e2);

    //if determinant is near zero, ray lies in plane of triangle or ray is parallel to plane of triangle
    float det = e1.dot(P);

    //NOT CULLING
    if(det > -EPSILON && det < EPSILON)
        return hit;

    float inv_det = 1.f / det;

    //calculate distance from V1 to ray origin
    vec3 T = ray.start.cross(a);

    //Calculate u parameter and test bound
    float u = T.dot(P) * inv_det;

    //The intersection lies outside of the triangle
    if(u < 0.f || u > 1.f)
        return hit;

    //Prepare to test v parameter
    vec3 Q = T.cross(e1);

    //Calculate V parameter and test bound
    float v = ray.dir.dot(Q) * inv_det;

    //The intersection lies outside of the triangle
    if(v < 0.f || u + v  > 1.f)
        return hit;

    float t = e2.dot(Q) * inv_det;

    if(t > EPSILON) { //ray intersection
        hit.t = t;
        hit.position = ray.start + ray.dir * t;
        hit.normal = ray.dir * (-1);
    }

    // No hit, no win
    return hit;
}

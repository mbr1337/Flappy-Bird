#include "Mesh.h"

Mesh::Mesh(float* vertices, size_t sizeOfVertices, int* indices, size_t sizeOfIndices, int indicesLen)
{
    verticesCount = indicesLen;
    vao = vbo = ebo = 0;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeOfVertices, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfIndices, indices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void Mesh::bind()
{
    glBindVertexArray(vao);
}

void Mesh::unbind()
{
    glBindVertexArray(0);
}

void Mesh::draw()
{
    glDrawElements(GL_TRIANGLES, verticesCount, GL_UNSIGNED_INT, 0);
}

void Mesh::render()
{
    bind();
    draw();
}
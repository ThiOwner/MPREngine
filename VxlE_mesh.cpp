#include "VxlE_mesh.hpp"

#include "glad/glad.h"

namespace VxlE {

    VxlE_mesh::VxlE_mesh(std::vector<float> &vertices) {
        vertexCount = vertices.size() / 3;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    VxlE_mesh::~VxlE_mesh() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }

    void VxlE_mesh::bind() const {
        glBindVertexArray(VAO);
    }

    void VxlE_mesh::unbind() const {
        glBindVertexArray(0);
    }

    void VxlE_mesh::draw() const {
        bind();
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
        unbind();
    }

}

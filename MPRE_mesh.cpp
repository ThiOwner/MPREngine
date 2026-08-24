#include "MPRE_mesh.hpp"

#include "glad/glad.h"

namespace MPRE {

    MPRE_mesh::MPRE_mesh(std::vector<float> &vertices) {
        vertexCount = vertices.size() / 6;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    MPRE_mesh::~MPRE_mesh() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }

    void MPRE_mesh::bind() const {
        glBindVertexArray(VAO);
    }

    void MPRE_mesh::unbind() const {
        glBindVertexArray(0);
    }

    void MPRE_mesh::draw() const {
        bind();
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
        unbind();
    }

}

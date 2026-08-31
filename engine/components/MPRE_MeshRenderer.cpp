#include "MPRE_MeshRenderer.hpp"

namespace MPRE {

    MPRE_MeshRenderer::MPRE_MeshRenderer(MPRE_MESH_TYPE type) {
        this->type = type;

        if (meshCache.find(type) == meshCache.end()) {
            std::vector<float> vertices = {};
            std::vector<unsigned int> indices = {};

            switch (type) {
                case MPRE_MESH_TYPE::CUBE:
                    vertices = {
                        -0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,
                         0.5f, -0.5f,  0.5f,    0.0f,  0.0f,  1.0f,
                         0.5f,  0.5f,  0.5f,    0.0f,  0.0f,  1.0f,
                        -0.5f,  0.5f,  0.5f,    0.0f,  0.0f,  1.0f,
                         0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,
                        -0.5f, -0.5f, -0.5f,    0.0f,  0.0f, -1.0f,
                        -0.5f,  0.5f, -0.5f,    0.0f,  0.0f, -1.0f,
                         0.5f,  0.5f, -0.5f,    0.0f,  0.0f, -1.0f,
                        -0.5f, -0.5f, -0.5f,   -1.0f,  0.0f,  0.0f,
                        -0.5f, -0.5f,  0.5f,   -1.0f,  0.0f,  0.0f,
                        -0.5f,  0.5f,  0.5f,   -1.0f,  0.0f,  0.0f,
                        -0.5f,  0.5f, -0.5f,   -1.0f,  0.0f,  0.0f,
                         0.5f, -0.5f,  0.5f,    1.0f,  0.0f,  0.0f,
                         0.5f, -0.5f, -0.5f,    1.0f,  0.0f,  0.0f,
                         0.5f,  0.5f, -0.5f,    1.0f,  0.0f,  0.0f,
                         0.5f,  0.5f,  0.5f,    1.0f,  0.0f,  0.0f,
                        -0.5f,  0.5f,  0.5f,    0.0f,  1.0f,  0.0f,
                         0.5f,  0.5f,  0.5f,    0.0f,  1.0f,  0.0f,
                         0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,
                        -0.5f,  0.5f, -0.5f,    0.0f,  1.0f,  0.0f,
                        -0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,
                         0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,
                         0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f,
                        -0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f
                    };
                    indices = {
                        0, 1, 2,   2, 3, 0,
                        4, 5, 6,   6, 7, 4,
                        8, 9, 10,  10, 11, 8,
                        12, 13, 14, 14, 15, 12,
                        16, 17, 18, 18, 19, 16,
                        20, 21, 22, 22, 23, 20
                    };
                    break;

                case MPRE_MESH_TYPE::PYRAMID:
                    vertices = {
                        -0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,
                         0.5f, -0.5f, -0.5f,    0.0f, -1.0f,  0.0f,
                         0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f,
                        -0.5f, -0.5f,  0.5f,    0.0f, -1.0f,  0.0f,
                        -0.5f, -0.5f,  0.5f,    0.0f, 0.447f, 0.894f,
                         0.5f, -0.5f,  0.5f,    0.0f, 0.447f, 0.894f,
                         0.0f,  0.5f,  0.0f,    0.0f, 0.447f, 0.894f,
                         0.5f, -0.5f,  0.5f,    0.894f, 0.447f, 0.0f,
                         0.5f, -0.5f, -0.5f,    0.894f, 0.447f, 0.0f,
                         0.0f,  0.5f,  0.0f,    0.894f, 0.447f, 0.0f,
                         0.5f, -0.5f, -0.5f,    0.0f, 0.447f, -0.894f,
                        -0.5f, -0.5f, -0.5f,    0.0f, 0.447f, -0.894f,
                         0.0f,  0.5f,  0.0f,    0.0f, 0.447f, -0.894f,
                        -0.5f, -0.5f, -0.5f,   -0.894f, 0.447f, 0.0f,
                        -0.5f, -0.5f,  0.5f,   -0.894f, 0.447f, 0.0f,
                         0.0f,  0.5f,  0.0f,   -0.894f, 0.447f, 0.0f
                    };
                    indices = {
                        0, 1, 2,   2, 3, 0,
                        4, 5, 6,
                        7, 8, 9,
                        10, 11, 12,
                        13, 14, 15
                    };
                    break;

                case MPRE_MESH_TYPE::PLANE:
                    vertices = {
                        -0.5f, 0.0f,  0.5f,     0.0f, 1.0f, 0.0f,
                         0.5f, 0.0f,  0.5f,     0.0f, 1.0f, 0.0f,
                         0.5f, 0.0f, -0.5f,     0.0f, 1.0f, 0.0f,
                        -0.5f, 0.0f, -0.5f,     0.0f, 1.0f, 0.0f
                    };
                    indices = {
                        0, 1, 2,
                        2, 3, 0
                    };
                    break;
            }

            meshCache[type] = std::make_shared<MPRE_mesh>(vertices, indices);
        }

        this->mesh = meshCache[type];
    }

    void MPRE_MeshRenderer::draw(const MPRE_shaders& shaders, const MPRE_Transform& transform) {
        glm::mat4 modelMatrix = transform.getModelMatrix();
        shaders.setMat4("modelMatrix", modelMatrix);
        shaders.setVec3("baseColor", baseColor);
        this->mesh->draw();
    }


}
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
                        -0.5f, -0.5f,  0.5f,
                        0.5f, -0.5f,  0.5f,
                        0.5f,  0.5f,  0.5f,
                        -0.5f,  0.5f,  0.5f,
                        -0.5f, -0.5f, -0.5f,
                        0.5f, -0.5f, -0.5f,
                        0.5f,  0.5f, -0.5f,
                        -0.5f,  0.5f, -0.5f
                    };

                    indices = {
                        0, 1, 2,  2, 3, 0,
                        1, 5, 6,  6, 2, 1,
                        5, 4, 7,  7, 6, 5,
                        4, 0, 3,  3, 7, 4,
                        3, 2, 6,  6, 7, 3,
                        4, 5, 1,  1, 0, 4
                    };
                    break;

                case MPRE_MESH_TYPE::PYRAMID:
                    vertices = {
                        0.0f,  0.5f,  0.0f,
                        -0.5f, -0.5f,  0.5f,
                        0.5f, -0.5f,  0.5f,
                        0.5f, -0.5f, -0.5f,
                        -0.5f, -0.5f, -0.5f
                    };

                    indices = {
                        1, 2, 0,
                        2, 3, 0,
                        3, 4, 0,
                        4, 1, 0,
                        1, 4, 3,
                        1, 3, 2
                    };
                    break;

                case MPRE_MESH_TYPE::PLANE:
                    vertices = {
                    -0.5f, 0.0f,  0.5f,
                     0.5f, 0.0f,  0.5f,
                     0.5f, 0.0f, -0.5f,
                    -0.5f, 0.0f, -0.5f
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
#include "MPRE_3DPrimitive.hpp"

namespace MPRE {

    MPRE_3DPrimitive::MPRE_3DPrimitive(MPRE_PRIMITIVE_3D_TYPE type) {
        this->type = type;

        if (meshCache.find(type) == meshCache.end()) {
            std::vector<float> vertices = {};
            std::vector<unsigned int> indices = {};

            switch (type) {
                case MPRE_PRIMITIVE_3D_TYPE::CUBE:
                    vertices = {
                        -0.5f, -0.5f,  0.5f,     1.0f, 0.0f, 0.0f,
                        0.5f, -0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
                        0.5f,  0.5f,  0.5f,     0.0f, 0.0f, 1.0f,
                        -0.5f,  0.5f,  0.5f,     1.0f, 1.0f, 0.0f,
                        -0.5f, -0.5f, -0.5f,     1.0f, 0.0f, 1.0f,
                        0.5f, -0.5f, -0.5f,     0.0f, 1.0f, 1.0f,
                        0.5f,  0.5f, -0.5f,     1.0f, 1.0f, 1.0f,
                        -0.5f,  0.5f, -0.5f,     0.0f, 0.0f, 0.0f
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

                case MPRE_PRIMITIVE_3D_TYPE::PYRAMID:
                    vertices = {
                        0.0f,  0.5f,  0.0f,        1.0f, 1.0f, 1.0f,
                        -0.5f, -0.5f,  0.5f,        1.0f, 0.0f, 0.0f,
                        0.5f, -0.5f,  0.5f,        0.0f, 1.0f, 0.0f,
                        0.5f, -0.5f, -0.5f,        0.0f, 0.0f, 1.0f,
                        -0.5f, -0.5f, -0.5f,        1.0f, 1.0f, 0.0f
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
            }

            meshCache[type] = std::make_shared<MPRE_mesh>(vertices, indices);
        }

        this->mesh = meshCache[type];
    }

    MPRE_3DPrimitive::~MPRE_3DPrimitive() = default;

}
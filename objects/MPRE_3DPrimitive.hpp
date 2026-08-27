#pragma once

#include "../core/MPRE_mesh.hpp"
#include "../core/MPRE_shaders.hpp"
#include "../components/MPRE_Transform.hpp"

#include <memory>

enum MPRE_PRIMITIVE_3D_TYPE {CUBE, PYRAMID};

namespace MPRE {

    // Only one mesh for each type of meshes
    static std::unordered_map<MPRE_PRIMITIVE_3D_TYPE, std::shared_ptr<MPRE_mesh>> meshCache;

    class MPRE_3DPrimitive {

        public:
            MPRE_3DPrimitive(MPRE_PRIMITIVE_3D_TYPE type);
            ~MPRE_3DPrimitive();

            void draw(const MPRE_shaders& shaders) const {
                glm::mat4 modelMatrix = transform->getModelMatrix();
                shaders.setMat4("modelMatrix", modelMatrix);
                this->mesh->draw();
            }

            MPRE_PRIMITIVE_3D_TYPE type;

            std::unique_ptr<MPRE_Transform> transform = std::make_unique<MPRE_Transform>();

        private:
            std::shared_ptr<MPRE_mesh> mesh;


    };

}
#pragma once

#include "../core/MPRE_shaders.hpp"
#include "MPRE_component.hpp"

#include "glm/ext/matrix_transform.hpp"
#include "glm/vec3.hpp"

namespace MPRE {

    class MPRE_Transform : public MPRE_component {
        public:
            MPRE_Transform() {
                scale = glm::vec3(1.0f, 1.0f, 1.0f);
                position = glm::vec3(0.0f, 0.0f, 0.0f);
                rotation = glm::vec3(0.0f, 0.0f, 0.0f);
            }

            glm::mat4 getModelMatrix();

        private:
            glm::vec3 scale;
            glm::vec3 position;
            glm::vec3 rotation;
    };

}

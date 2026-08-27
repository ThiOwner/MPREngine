#pragma once

#include "MPRE_component.hpp"

#include "glm/ext/matrix_transform.hpp"
#include "glm/vec3.hpp"

namespace MPRE {

    class MPRE_Transform {
        public:
            MPRE_Transform() {
                scale = glm::vec3(1.0f, 1.0f, 1.0f);
                position = glm::vec3(0.0f, 0.0f, 0.0f);
                rotation = glm::vec3(0.0f, 0.0f, 0.0f);
                computeModelMatrix();
            }

            void setPosition(const glm::vec3& p) {
                position = p;
                computeModelMatrix();
            }
            void setRotation(const glm::vec3& r) {
                rotation = r;
                computeModelMatrix();
            }
            void setScale(const glm::vec3& s) {
                scale = s;
                computeModelMatrix();
            }

            glm::vec3 getPosition(){ return position; };
            glm::vec3 getRotation(){ return rotation; };
            glm::vec3 getScale(){ return scale; };

            glm::mat4 getModelMatrix() const {return modelMatrix;}

        private:
            glm::vec3 scale;
            glm::vec3 position;
            glm::vec3 rotation;

            glm::mat4 modelMatrix;

            void computeModelMatrix();
    };

}

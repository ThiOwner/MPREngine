#pragma once

#include "MPRE_ImportComponents.hpp"

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

            glm::vec3 getPosition() const { return position; };
            glm::vec3 getRotation() const { return rotation; };
            glm::vec3 getScale() const { return scale; };

            glm::mat4 getModelMatrix() const {return modelMatrix;}

            glm::vec3 getRightVector() const {
                glm::mat4 model = getModelMatrix();
                return glm::normalize(glm::vec3(model[0][0], model[0][1], model[0][2]));
            }
            glm::vec3 getUpVector() const {
                glm::mat4 model = getModelMatrix();
                return glm::normalize(glm::vec3(model[1][0], model[1][1], model[1][2]));
            }
            glm::vec3 getForwardVector() const {
                glm::mat4 model = getModelMatrix();
                return glm::normalize(glm::vec3(-model[2][0], -model[2][1], -model[2][2]));
            }

        private:
            glm::vec3 scale;
            glm::vec3 position;
            glm::vec3 rotation;

            glm::mat4 modelMatrix;

            void computeModelMatrix();
    };

}

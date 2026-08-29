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

            glm::vec3 getForwardVector() const {
                    glm::vec3 forward;
                    forward.x = sin(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));
                    forward.y = sin(glm::radians(rotation.x));
                    forward.z = -cos(glm::radians(rotation.y)) * cos(glm::radians(rotation.x));

                    return glm::normalize(forward);
                }
            glm::vec3 getRightVector() const {
                    return glm::normalize(glm::cross(getForwardVector(), glm::vec3(0.0f, 1.0f, 0.0f)));
                }
            glm::vec3 getUpVector() const {
                    return glm::normalize(glm::cross(getRightVector(), getForwardVector()));
                }

        private:
            glm::vec3 scale;
            glm::vec3 position;
            glm::vec3 rotation;

            glm::mat4 modelMatrix;

            void computeModelMatrix();
    };

}

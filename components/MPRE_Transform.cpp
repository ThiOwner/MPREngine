#include "MPRE_Transform.hpp"

namespace MPRE {

    glm::mat4 MPRE_Transform::getModelMatrix() {
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, position);

        transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

        transform = glm::scale(transform, scale);

        return transform;
    }

}

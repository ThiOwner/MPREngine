#include "MPRE_Camera.hpp"

namespace MPRE {

    MPRE_Camera::MPRE_Camera(float aspectRatio) {
        projectionMatrix = glm::perspective(glm::radians(90.0f), aspectRatio, 0.1f, 100.0f);
    }

    void MPRE_Camera::update(double deltaTime) {}

    void MPRE_Camera::draw(const MPRE_shaders& shaders, const MPRE_Transform& transform) {
        glm::mat4 viewMatrix = glm::inverse(transform.getModelMatrix());
        shaders.setMat4("viewMatrix",viewMatrix);
        shaders.setMat4("projectionMatrix", projectionMatrix);
    }

    void MPRE_Camera::setAspectRatio(float aspectRatio) {
        projectionMatrix = glm::perspective(glm::radians(90.0f), aspectRatio, 0.1f, 100.0f);
    }

}
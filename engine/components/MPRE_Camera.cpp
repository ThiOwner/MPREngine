#include "MPRE_Camera.hpp"

namespace MPRE {

    MPRE_Camera::MPRE_Camera(MPRE_window* window) {
        attachedWindow = window;

        int height = 0, width = 0;
        window->getWindowSize(width, height);
        float aspectRatio = static_cast<float>(width) / static_cast<float>(height);

        projectionMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
    }

    void MPRE_Camera::update(double deltaTime) {
        checkingWindowResize();
    }

    void MPRE_Camera::draw(const MPRE_shaders& shaders, const MPRE_Transform& transform) {
        glm::vec3 position = transform.getPosition();
        glm::vec3 forward = transform.getForwardVector();
        glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::mat4 viewMatrix = glm::lookAt(position, position + forward, worldUp);

        shaders.setMat4("viewMatrix",viewMatrix);
        shaders.setMat4("projectionMatrix", projectionMatrix);
    }

    void MPRE_Camera::setAspectRatio(float aspectRatio) {
        projectionMatrix = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);
    }

    void MPRE_Camera::checkingWindowResize() {
        int height = 0, width = 0;
        attachedWindow->getWindowSize(width, height);
        if (height > 0) {
            setAspectRatio(static_cast<float>(width) / static_cast<float>(height));
        }
    }

}
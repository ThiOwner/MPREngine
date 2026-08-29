#include "../../engine/components/MPRE_ImportComponents.hpp"
#include "../../engine/utils/MPRE_InputManager.hpp"

namespace MPRE {

    class freeCamera : public MPRE_Component{
    public:
        freeCamera(MPRE_Transform* gOTransform) {
            gameObjectTransform = gOTransform;
        }

        void update(double deltaTime) {
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_W)) {
                gameObjectTransform->setPosition(gameObjectTransform->getPosition() + glm::vec3(0.0f, 0.0f, -cameraVelocity * deltaTime));
            }
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_S)) {
                gameObjectTransform->setPosition(gameObjectTransform->getPosition() + glm::vec3(0.0f, 0.0f, cameraVelocity * deltaTime));
            }
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_A)) {
                gameObjectTransform->setPosition(gameObjectTransform->getPosition() + glm::vec3(-cameraVelocity * deltaTime, 0.0f, 0.0f));
            }
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_D)) {
                gameObjectTransform->setPosition(gameObjectTransform->getPosition() + glm::vec3(cameraVelocity * deltaTime, 0.0f, 0.0f));
            }
        }

    private:
        float cameraVelocity = 2.5f;
        MPRE_Transform* gameObjectTransform = nullptr;
    };

}

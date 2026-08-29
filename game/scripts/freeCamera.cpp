#include "../../engine/components/MPRE_ImportComponents.hpp"
#include "../../engine/utils/MPRE_InputManager.hpp"

namespace MPRE {

    class freeCamera : public MPRE_Component{
    public:
        freeCamera(MPRE_Transform* gOTransform) {
            gameObjectTransform = gOTransform;
        }

        void start() override {
            MPRE_InputManager::setMouseGrabbed(true);
        }

        void update(double deltaTime) override {
            glm::vec2 mousePos = MPRE_InputManager::getMousePosition();

            if (firstMouse) {
                lastMousePos = mousePos;
                firstMouse = false;
            }

            float xOffset = mousePos.x - lastMousePos.x;
            float yOffset = lastMousePos.y - mousePos.y;
            lastMousePos = mousePos;

            glm::vec3 currentRot = gameObjectTransform->getRotation();
            currentRot.y += xOffset * cameraSensibility;
            currentRot.x += yOffset * cameraSensibility;

            gameObjectTransform->setRotation(currentRot);

            glm::vec3 pos = gameObjectTransform->getPosition();
            glm::vec3 forward = gameObjectTransform->getForwardVector();
            glm::vec3 right = gameObjectTransform->getRightVector();

            float velocity = cameraVelocity * deltaTime;
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_W)) pos += forward * velocity;
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_S)) pos -= forward * velocity;
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_A)) pos -= right * velocity;
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_D)) pos += right * velocity;

            gameObjectTransform->setPosition(pos);

            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_ESCAPE)) {
                MPRE_InputManager::setMouseGrabbed(false);
            }
        }

    private:
        float cameraVelocity = 2.5f;
        float cameraSensibility = 0.05f;
        MPRE_Transform* gameObjectTransform = nullptr;

        glm::vec2 lastMousePos = glm::vec2(0.0f);
        bool firstMouse = true;
    };

}

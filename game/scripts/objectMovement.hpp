#pragma once

#include "../../engine/components/MPRE_ImportComponents.hpp"

namespace MPRE {

    class objectMovement : public MPRE_Component {
        public:
            objectMovement(MPRE_Transform* gOTransform, glm::vec3 bPosition) {
                gameObjectTransform = gOTransform;
                basePosition = bPosition;
            }

            void update(double deltaTime) override {
                totalTime += deltaTime;
                gameObjectTransform->setPosition(basePosition + glm::vec3(0.0f,sin(totalTime),0.0f));
                gameObjectTransform->setRotation(glm::vec3(gameObjectTransform->getRotation() + glm::vec3(50.0f*deltaTime)));
            }

        private:
            double totalTime = 0.0f;
            glm::vec3 basePosition;
            MPRE_Transform* gameObjectTransform = nullptr;
    };

}
#pragma once

#include "../core/MPRE_shaders.hpp"
#include "MPRE_GameObject.hpp"


namespace MPRE {

    struct sceneDirectionalLight {
        glm::vec3 direction = glm::vec3(-0.2f, -1.0f, -0.3f);
        glm::vec3 color = glm::vec3(0.8f, 0.8f, 0.8f);
        float intensity = 1.0f;
    };

    class MPRE_Scene {
        public:
            MPRE_GameObject* addGameObject(std::unique_ptr<MPRE_GameObject> gameObject){
                MPRE_GameObject* ref = gameObject.get();
                gameObjects.push_back(std::move(gameObject));
                return ref;
            }

            void start(MPRE_shaders* shaders) {
                shaders->setVec3("lightDir", directionalLight.direction);
                shaders->setVec3("lightColor", directionalLight.color * directionalLight.intensity);
                for (auto& obj : gameObjects) {
                    obj->start();
                }
            }
            void run(double deltaTime, MPRE_shaders* shaders) {
                for (auto& obj : gameObjects) {
                    obj->update(deltaTime);
                }
                for (auto& obj : gameObjects) {
                    obj->draw(*shaders);
                }
            }

        private:
            sceneDirectionalLight directionalLight;
            std::vector<std::unique_ptr<MPRE_GameObject>> gameObjects;
    };

}
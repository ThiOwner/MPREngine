#pragma once

#include "../core/MPRE_shaders.hpp"
#include "MPRE_GameObject.hpp"


namespace MPRE {
    class MPRE_Scene {
        public:
            MPRE_GameObject* addGameObject(std::unique_ptr<MPRE_GameObject> gameObject){
                MPRE_GameObject* ref = gameObject.get();
                gameObjects.push_back(std::move(gameObject));
                return ref;
            }

            void start() {
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
            std::vector<std::unique_ptr<MPRE_GameObject>> gameObjects;
    };

}
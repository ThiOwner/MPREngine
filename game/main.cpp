#include "../engine/core/MPRE_app.hpp"
#include "../engine/scene/MPRE_GameObject.hpp"

#include "../engine/components/MPRE_ImportComponents.hpp"
#include "scripts/objectMovement.hpp"
#include "scripts/freeCamera.hpp"

#include <cstdlib>
#include <iostream>
#include <ostream>

int main() {
        std::unique_ptr<MPRE::MPRE_app> app = std::make_unique<MPRE::MPRE_app>();

        try {
                app->init();

                auto camera = std::make_unique<MPRE::MPRE_GameObject>();
                camera->addComponent<MPRE::MPRE_Camera>(app->window.get());
                camera->addComponent<MPRE::freeCamera>(&camera->transform);
                app->addGameObject(std::move(camera));

                auto floor = std::make_unique<MPRE::MPRE_GameObject>();
                auto& meshComp1 = floor->addComponent<MPRE::MPRE_MeshRenderer>(MPRE_MESH_TYPE::PLANE);
                meshComp1.setColor(glm::vec3(0.5f, 0.5f, 0.5f));
                floor->transform.setPosition(glm::vec3(0.0f, -2.0f, 0.0f));
                floor->transform.setScale(glm::vec3(15.0f));
                app->addGameObject(std::move(floor));

                auto cube = std::make_unique<MPRE::MPRE_GameObject>();
                auto& meshComp2 = cube->addComponent<MPRE::MPRE_MeshRenderer>(MPRE_MESH_TYPE::CUBE);
                meshComp2.setColor(glm::vec3(0.0f, 0.3f, 0.3f));
                cube->addComponent<MPRE::objectMovement>(&cube->transform, glm::vec3(1.0f, 0.0f, 0.0f));
                app->addGameObject(std::move(cube));

                auto pyramid = std::make_unique<MPRE::MPRE_GameObject>();
                auto& meshComp3 = pyramid->addComponent<MPRE::MPRE_MeshRenderer>(MPRE_MESH_TYPE::PYRAMID);
                meshComp3.setColor(glm::vec3(0.5f, 0.0f, 0.0f));
                pyramid->addComponent<MPRE::objectMovement>(&pyramid->transform, glm::vec3(-1.0f,0.0f,0.0f));
                app->addGameObject(std::move(pyramid));

                app->run();
        }
        catch (const std::exception& e) {
                std::cerr << "[FATAL ERROR] " << e.what() << std::endl;
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}


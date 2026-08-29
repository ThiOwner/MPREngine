#include "../engine/core/MPRE_app.hpp"
#include "../engine/scene/MPRE_GameObject.hpp"

#include "../engine/components/MPRE_ImportComponents.hpp"
#include "scripts/freeCamera.cpp"

#include <cstdlib>
#include <iostream>
#include <ostream>

int main() {
        std::unique_ptr<MPRE::MPRE_app> app = std::make_unique<MPRE::MPRE_app>();

        try {
                app->init();

                MPRE::MPRE_GameObject camera;
                camera.addComponent<MPRE::MPRE_Camera>(app->window.get());
                camera.addComponent<MPRE::freeCamera>(&camera.transform);

                MPRE::MPRE_GameObject cube;
                cube.addComponent<MPRE::MPRE_MeshRenderer>(MPRE_MESH_TYPE::CUBE);

                app->addGameObject(&camera);
                app->addGameObject(&cube);

                app->run();
        }
        catch (const std::exception& e) {
                std::cerr << "[FATAL ERROR] " << e.what() << std::endl;
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}


#include "MPRE_app.hpp"

namespace MPRE {

    MPRE_app::MPRE_app() = default;
    MPRE_app::~MPRE_app() = default;

    void MPRE_app::run() {
        // Initialize en creating the window
        window->initializeWindow();

        // Compile shaders
        defaultShaders->compileShaders();

        // Creating 3D primitive
        MPRE_3DPrimitive cube(MPRE_PRIMITIVE_3D_TYPE::CUBE);
        cube.transform->setScale(glm::vec3(0.25f));

        MPRE_3DPrimitive pyramid(MPRE_PRIMITIVE_3D_TYPE::PYRAMID);
        pyramid.transform->setScale(glm::vec3(0.25f,0.25f,0.25f));

        MPRE_3DPrimitive cubebis(MPRE_PRIMITIVE_3D_TYPE::CUBE);
        cubebis.transform->setScale(glm::vec3(0.25f));

        // Enable depth calculations
        glEnable(GL_DEPTH_TEST);

        // Render loop
        double totalTime = 0.0f;
        while (!window->shouldClose()) {
            window->pollEvents();

            // Computing deltaTime
            computeDeltaTime();

            // Global time
            totalTime += deltaTime;

            // Wireframe mode on "Z" input
            if (window->isKeyPressed(GLFW_KEY_Z)) {
                handleWireframe();
            } else {
                wireframeKeyPressed = false;
            }

            // glClear
            clearBuffers();

            defaultShaders->bindShaderProgram();

            cube.transform->setRotation(cube.transform->getRotation() + glm::vec3(15.0f * deltaTime));
            cube.transform->setPosition(glm::vec3(0.5f, sin(totalTime)/3, 0.0f));

            pyramid.transform->setRotation( pyramid.transform->getRotation() + glm::vec3(30.0f * deltaTime) );

            cubebis.transform->setRotation(cubebis.transform->getRotation() + glm::vec3(-15.0f * deltaTime));
            cubebis.transform->setPosition( glm::vec3(-0.5f, -sin(totalTime)/3, 0.0f));

            cube.draw(*defaultShaders);
            pyramid.draw(*defaultShaders);
            cubebis.draw(*defaultShaders);

            window->swapBuffers();
        }

    }

}

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
        cube.transform->setScale(glm::vec3(0.5f));

        // Enable depth calculations
        glEnable(GL_DEPTH_TEST);

        // Render loop
        while (!window->shouldClose()) {
            window->pollEvents();

            // Computing deltaTime
            computeDeltaTime();

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
            cube.draw(*defaultShaders);

            window->swapBuffers();
        }

    }

}

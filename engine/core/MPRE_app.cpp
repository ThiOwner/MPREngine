#include "MPRE_app.hpp"

namespace MPRE {

    MPRE_app::MPRE_app() = default;
    MPRE_app::~MPRE_app() = default;

    void MPRE_app::init() {
        // Initialize en creating the window
        window->initializeWindow();

        // Compile shaders
        defaultShaders->compileShaders();
    }

    void MPRE_app::run() {

        // Render loop
        while (!window->shouldClose()) {
            window->pollEvents();

            // Computing deltaTime
            computeDeltaTime();
            totalTime += deltaTime;

            // Wireframe mode on "Z" input
            if (MPRE_Input_Manager::isKeyHeld(GLFW_KEY_Z)) {
                handleWireframe();
            } else {
                wireframeKeyPressed = false;
            }

            // glClear
            clearBuffers();

            // Draw a frame
            defaultShaders->bindShaderProgram();

            // TODO : draw all the GameObject.

            window->swapBuffers();
        }

    }

}

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
        defaultShaders->bindShaderProgram();

        if (currentScene != nullptr) {
            currentScene->start(defaultShaders.get());
        }

        // Render loop
        while (!window->shouldClose()) {
            window->pollEvents();

            // Computing deltaTime
            computeDeltaTime();
            totalTime += deltaTime;

            // Wireframe mode on "Z" input
            if (MPRE_InputManager::isKeyHeld(GLFW_KEY_Z)) {
                handleWireframe();
            } else {
                wireframeKeyPressed = false;
            }

            // glClear
            clearBuffers();

            // Draw a frame
            if (currentScene != nullptr) {
                currentScene->run(deltaTime, defaultShaders.get());
            }

            window->swapBuffers();
        }

    }

}

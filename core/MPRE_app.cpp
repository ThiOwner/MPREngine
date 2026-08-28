#include "MPRE_app.hpp"

namespace MPRE {

    MPRE_app::MPRE_app() = default;
    MPRE_app::~MPRE_app() = default;

    void MPRE_app::run() {
        // Initialize en creating the window
        window->initializeWindow();

        // Compile shaders
        defaultShaders->compileShaders();

        // Creating Camera
        MPRE_GameObject camera;
        auto& cameraComponent = camera.addComponent<MPRE_Camera>((float)window->WIDTH/(float)window->HEIGHT);

        // Creating GameObjects
        MPRE_GameObject obj1;
        obj1.addComponent<MPRE_MeshRenderer>(MPRE_MESH_TYPE::CUBE);
        obj1.transform.setScale(glm::vec3(0.2f));

        while (!window->shouldClose()) {
            window->pollEvents();

            // Computing deltaTime
            computeDeltaTime();
            totalTime += deltaTime;

            // Wireframe mode on "Z" input
            if (window->isKeyPressed(GLFW_KEY_Z)) {
                handleWireframe();
            } else {
                wireframeKeyPressed = false;
            }

            // glClear
            clearBuffers();

            // Keeping aspect ratio when the window is resized
            checkingWindowResize(&cameraComponent);

            // Draw a frame
            defaultShaders->bindShaderProgram();

            camera.update(deltaTime);
            camera.draw(*defaultShaders);

            obj1.transform.setPosition(glm::vec3(0.0f, sin(totalTime)/3, -0.45f));
            obj1.transform.setRotation(obj1.transform.getRotation() + glm::vec3(70.0f * deltaTime * sin(totalTime)));

            obj1.update(deltaTime);
            obj1.draw(*defaultShaders);

            window->swapBuffers();
        }

    }

}

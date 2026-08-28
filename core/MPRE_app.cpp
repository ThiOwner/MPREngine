#include "MPRE_app.hpp"
#include "../scene/MPRE_GameObject.hpp"
#include "../components/MPRE_MeshRenderer.hpp"

namespace MPRE {

    MPRE_app::MPRE_app() = default;
    MPRE_app::~MPRE_app() = default;

    void MPRE_app::run() {
        // Initialize en creating the window
        window->initializeWindow();

        // Compile shaders
        defaultShaders->compileShaders();

        // Creating GameObjects
        MPRE_GameObject obj1;
        obj1.addComponent<MPRE_MeshRenderer>(MPRE_MESH_TYPE::CUBE);
        obj1.transform.setScale(glm::vec3(0.33f));

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

            obj1.transform.setPosition(glm::vec3(0.0f, sin(totalTime)/3, 0.0f));
            obj1.transform.setRotation(obj1.transform.getRotation() + glm::vec3(20.0f * deltaTime));

            obj1.update(deltaTime);
            obj1.draw(*defaultShaders);

            window->swapBuffers();
        }

    }

}

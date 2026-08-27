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
        double lastTime = 0;
        while (!window->shouldClose()) {
            window->pollEvents();

            // Delta time
            double deltaTime = glfwGetTime()-lastTime;
            lastTime = glfwGetTime();

            // Wireframe mode on "Z" input
            if (window->isKeyPressed(GLFW_KEY_Z)) {
                if (!wireframeKeyPressed) {
                    ifWireframe = !ifWireframe;
                    if (ifWireframe) { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
                    else { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }
                    wireframeKeyPressed = true;
                }
            } else {
                wireframeKeyPressed = false;
            }

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            defaultShaders->bindShaderProgram();

            cube.transform->setRotation(cube.transform->getRotation() + glm::vec3(15.0f * deltaTime));
            cube.draw(*defaultShaders);

            window->swapBuffers();
        }

    }

}

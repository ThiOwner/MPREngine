#include "MPRE_app.hpp"

namespace MPRE {

    MPRE_app::MPRE_app() = default;
    MPRE_app::~MPRE_app() = default;

    void MPRE_app::run() {
        // Initialize en creating the window
        window->initializeWindow();

        // Compile shaders
        shaders->compileShaders();

        // Render loop
        while (!window->shouldClose()) {
            window->pollEvents();
            double timeValue = glfwGetTime();

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
            glClear(GL_COLOR_BUFFER_BIT);

            shaders->bindShaderProgram();

            window->swapBuffers();
        }

    }

}

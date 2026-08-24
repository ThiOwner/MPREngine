#include "MPRE_app.hpp"

#include <vector>

namespace MPRE {

    // Testing values
    std::vector<float> vertices = {
        0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f,   // bottom right
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
       -0.5f,  0.5f, 0.0f,  1.0f, 0.0f, 1.0f   // top left
   };
    std::vector<unsigned int> indices = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };

    MPRE_app::MPRE_app() = default;
    MPRE_app::~MPRE_app() = default;

    void MPRE_app::run() {
        // Initialize en creating the window
        window->initializeWindow();

        // Compile shaders
        shaders->compileShaders();

        // Flat square test
        MPRE_mesh flatSquare(vertices, indices);

        // Render loop
        while (!window->shouldClose()) {
            window->pollEvents();

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

            flatSquare.draw();

            window->swapBuffers();
        }

    }

}

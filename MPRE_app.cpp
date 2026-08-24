#include "MPRE_app.hpp"

#include <vector>

namespace MPRE {

    std::vector<float> triangleVertices = {
        // positions         // colors
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // bottom right
       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // bottom left
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // top
    };

    MPRE_app::MPRE_app() = default;
    MPRE_app::~MPRE_app() = default;

    void MPRE_app::run() {
        // Initialize en creating the window
        window->initializeWindow();

        // Compile shaders
        shaders->compileShaders();

        // Hello triangle
        MPRE_mesh triangle(triangleVertices);

        // Render loop
        while (!window->shouldClose()) {

            window->pollEvents();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shaders->bindShaderProgram();

            triangle.draw();

            window->swapBuffers();
        }

    }

}

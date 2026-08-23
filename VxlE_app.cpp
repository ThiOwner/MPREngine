#include "VxlE_app.hpp"

#include <vector>

namespace VxlE {

    std::vector<float> triangleVertices = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    VxlE_app::VxlE_app() = default;
    VxlE_app::~VxlE_app() = default;

    void VxlE_app::run() {
        // Initialize en creating the window
        window.initializeWindow();

        // Compile shaders
        shaders.compileShaders();

        // Hello triangle
        VxlE_mesh triangle(triangleVertices);

        // Render loop
        while (!window.shouldClose()) {

            window.pollEvents();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shaders.bindShaderProgram();

            triangle.draw();

            window.swapBuffers();
        }

    }

}

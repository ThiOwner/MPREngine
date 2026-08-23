#include "VxlE_app.hpp"
#include "VxlE_window.hpp"


namespace VxlE {

    VxlE_app::VxlE_app() = default;
    VxlE_app::~VxlE_app() = default;

    void VxlE_app::run() {
        // Initialize en creating the window
        window.initializeWindow();

        // Compile shaders
        shaders.compileShaders();

        // Render loop
        while (!window.shouldClose()) {

            window.pollEvents();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shaders.bindShaderProgram();

            window.swapBuffers();
        }

    }

}

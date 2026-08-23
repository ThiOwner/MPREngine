#include "VxlE_app.hpp"
#include "VxlE_window.hpp"


namespace VxlE {

    VxlE_app::VxlE_app() = default;
    VxlE_app::~VxlE_app() = default;

    void VxlE_app::run() {
        // Initialize en creating the window
        window.initializeWindow();
        window.runWindow();

        // Compile shaders and create shaderProgram
        shaders.compileShaders();
        shaders.bindShaderProgram();
    }

}

#include "MPRE_window.hpp"

#include <iostream>
#include <ostream>

namespace MPRE {

    MPRE_window::MPRE_window() = default;
    MPRE_window::~MPRE_window() = default;

    int MPRE_window::initializeWindow() {
        // Initialize window
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "MPRE Engine", NULL, NULL);
        if (window == NULL) {
            throw std::runtime_error("Failed to create GLFW window");
            closeWindow();
            return -1;
        }

        glfwMakeContextCurrent(window);

        // Initialize GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        glfwSetFramebufferSizeCallback(window, setFramebufferSizeCallback);
        return 0;
    }

    void MPRE_window::closeWindow() {
        glfwTerminate();
    }

    void MPRE_window::setFramebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0,0,width,height);
    }

}

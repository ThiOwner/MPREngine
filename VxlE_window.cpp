#include "VxlE_window.hpp"

#include <iostream>
#include <ostream>

namespace VxlE {

    VxlE_window::VxlE_window() = default;
    VxlE_window::~VxlE_window() = default;

    int VxlE_window::initializeWindow() {
        // Initialize window
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "VxlE Engine", NULL, NULL);
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

    void VxlE_window::closeWindow() {
        glfwTerminate();
    }

    void VxlE_window::runWindow() {
        while(!glfwWindowShouldClose(window))
        {
            glfwSwapBuffers(window);
            glfwPollEvents();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }

    void VxlE_window::setFramebufferSizeCallback(GLFWwindow* window, int width, int height) {
        glViewport(0,0,width,height);
    }

}

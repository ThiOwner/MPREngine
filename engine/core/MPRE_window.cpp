#include "MPRE_window.hpp"

namespace MPRE {

    MPRE_window::MPRE_window() = default;
    MPRE_window::~MPRE_window() { closeWindow(); }

    int MPRE_window::initializeWindow() {
        // Initialize window
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        window = glfwCreateWindow(WIDTH, HEIGHT, "MPREngine", NULL, NULL);
        if (window == NULL) {
            closeWindow();
            throw std::runtime_error("Failed to create GLFW window");
        }

        glfwMakeContextCurrent(window);

        // Initialize GLAD
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        // Linkinng the window to the MPRE_Input_Manager
        MPRE_InputManager::init(window);

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

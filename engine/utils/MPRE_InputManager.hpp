#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace MPRE {

    class MPRE_InputManager {
    public:
        static void init(GLFWwindow* w) {
            window = w;
        }

        static bool isKeyHeld(int keyCode) {
            if (window == nullptr) {
                throw std::runtime_error("window must be initialized before asking for input.");
            }
            return glfwGetKey(window, keyCode) == GLFW_PRESS;
        }

    private:
        inline static GLFWwindow* window = nullptr;
    };

}
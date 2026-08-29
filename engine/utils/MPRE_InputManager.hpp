#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

#include "glm/vec2.hpp"

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

        static glm::vec2 getMousePosition() {
            if (window == nullptr) throw std::runtime_error("window must be initialized.");
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            return glm::vec2(static_cast<float>(xpos), static_cast<float>(ypos));
        }

        static void setMouseGrabbed(bool grabbed) {
            if (window == nullptr) return;
            if (grabbed) {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            } else {
                glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            }
        }

    private:
        inline static GLFWwindow* window = nullptr;
    };

}

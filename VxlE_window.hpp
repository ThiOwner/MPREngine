#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

namespace VxlE {

    class VxlE_window {

        public:
            VxlE_window();
            ~VxlE_window();

            int initializeWindow();
            void closeWindow();
            void runWindow();

        private:
            const int HEIGHT = 600;
            const int WIDTH = 800;

            GLFWwindow* window;

            static void setFramebufferSizeCallback(GLFWwindow* window, int w, int h);

    };

}
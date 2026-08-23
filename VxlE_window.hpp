#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>

namespace VxlE {

    class VxlE_window {

        public:
            VxlE_window();
            ~VxlE_window();
            
            VxlE_window(const VxlE_window&) = delete;
            VxlE_window& operator=(const VxlE_window&) = delete;
        
            int initializeWindow();
            void closeWindow();

            [[nodiscard]] bool shouldClose() const { return glfwWindowShouldClose(window); }
            void pollEvents() const { glfwPollEvents(); }
            void swapBuffers() const { glfwSwapBuffers(window); }

        private:
            const int HEIGHT = 600;
            const int WIDTH = 800;

            GLFWwindow* window;

            static void setFramebufferSizeCallback(GLFWwindow* window, int w, int h);

    };

}
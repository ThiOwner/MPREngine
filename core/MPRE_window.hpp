#pragma once

#include "../utils/MPRE_Input_Manager.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

namespace MPRE {

    class MPRE_window {

        public:
            MPRE_window();
            ~MPRE_window();
            
            MPRE_window(const MPRE_window&) = delete;
            MPRE_window& operator=(const MPRE_window&) = delete;
        
            int initializeWindow();
            void closeWindow();

            void getWindowSize(int& w, int& h) { glfwGetFramebufferSize(window, &w, &h); }

            [[nodiscard]] bool shouldClose() const { return glfwWindowShouldClose(window); }
            void pollEvents() const { glfwPollEvents(); }
            void swapBuffers() const { glfwSwapBuffers(window); }

            const int HEIGHT = 600;
            const int WIDTH = 800;

        private:

            GLFWwindow* window;

            static void setFramebufferSizeCallback(GLFWwindow* window, int w, int h);

    };

}
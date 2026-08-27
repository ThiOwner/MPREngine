#pragma once

#include <memory>
#include "MPRE_window.hpp"
#include "MPRE_shaders.hpp"
#include "../objects/MPRE_3DPrimitive.hpp"

namespace MPRE {

    class MPRE_app {

        public:
            MPRE_app();
            ~MPRE_app();
            void run();

        private:

            std::unique_ptr<MPRE_window> window = std::make_unique<MPRE_window>();
            std::unique_ptr<MPRE_shaders> defaultShaders = std::make_unique<MPRE_shaders>("shaders/vertex.vert", "shaders/fragment.frag");

            static void clearBuffers() {
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            };

            bool ifWireframe = false;
            bool wireframeKeyPressed = false;

            void handleWireframe() {
                if (!wireframeKeyPressed) {
                    ifWireframe = !ifWireframe;
                    if (ifWireframe) { glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); }
                    else { glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); }
                    wireframeKeyPressed = true;
                }
            };

            double lastTime = 0;
            double deltaTime = glfwGetTime();

            void computeDeltaTime() {
                deltaTime = glfwGetTime()-lastTime;
                lastTime = glfwGetTime();
            };
    };

}

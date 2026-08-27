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

            bool ifWireframe = false;
            bool wireframeKeyPressed = false;

    };

}

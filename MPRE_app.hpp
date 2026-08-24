#pragma once
#include "MPRE_app.hpp"
#include "MPRE_window.hpp"
#include "MPRE_shaders.hpp"
#include "MPRE_mesh.hpp"

#include <memory>

namespace MPRE {

    class MPRE_app {

        public:
            MPRE_app();
            ~MPRE_app();
            void run();

        private:

            std::unique_ptr<MPRE_window> window = std::make_unique<MPRE_window>();
            std::unique_ptr<MPRE_shaders> shaders = std::make_unique<MPRE_shaders>("shaders/vertex.vert", "shaders/fragment.frag");

            bool ifWireframe = false;
            bool wireframeKeyPressed = false;

    };

}

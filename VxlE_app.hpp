#pragma once
#include "VxlE_window.hpp"
#include "VxlE_shaders.hpp"

namespace VxlE {

    class VxlE_app {

        public:
            VxlE_app();
            ~VxlE_app();
            void run();

        private:
            VxlE_window window;
            VxlE_shaders shaders{"shaders/vertex.vert", "shaders/fragment.frag"};

    };

}

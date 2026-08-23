#pragma once
#include "VxlE_window.hpp"

namespace VxlE {

    class VxlE_app {

        public:
            VxlE_app();
            ~VxlE_app();
            void run();

        private:
            VxlE_window window;

    };

}

#include "VxlE_app.hpp"
#include "VxlE_window.hpp"


namespace VxlE {

    VxlE_app::VxlE_app() {}
    VxlE_app::~VxlE_app(){}

    void VxlE_app::run() {

        // Initialize en creating the window.
        window.initializeWindow();
        window.runWindow();

    }

}

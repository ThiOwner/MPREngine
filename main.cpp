#include "VxlE_app.hpp"

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>

int main() {
        VxlE::VxlE_app app;

        try {
                app.run();
        }
        catch (const std::exception& e) {
                std::cerr << "[FATAL ERROR] " << e.what() << std::endl;
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}


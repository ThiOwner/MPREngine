#include "../core/MPRE_app.hpp"

#include <cstdlib>
#include <iostream>
#include <ostream>

int main() {
        std::unique_ptr<MPRE::MPRE_app> app = std::make_unique<MPRE::MPRE_app>();

        try {
                app->run();
        }
        catch (const std::exception& e) {
                std::cerr << "[FATAL ERROR] " << e.what() << std::endl;
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}


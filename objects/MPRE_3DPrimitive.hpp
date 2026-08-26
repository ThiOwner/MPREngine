#pragma once

#include <memory>
#include "../core/MPRE_mesh.hpp"

enum MPRE_PRIMITIVE_3D_TYPE {CUBE};

namespace MPRE {

    class MPRE_3DPrimitive {

        public:
            MPRE_3DPrimitive(MPRE_PRIMITIVE_3D_TYPE type);
            ~MPRE_3DPrimitive();

            void draw() const {
                this->mesh->draw();
            }

            MPRE_PRIMITIVE_3D_TYPE type;

        private:
            std::unique_ptr<MPRE_mesh> mesh;
    };

}
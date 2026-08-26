#pragma once

#include "../core/MPRE_mesh.hpp"
#include "../components/MPRE_Transform.hpp"

#include <memory>
#include <vector>

enum MPRE_PRIMITIVE_3D_TYPE {CUBE};

namespace MPRE {

    // Mesh already created are cached here.
    static std::unordered_map<MPRE_PRIMITIVE_3D_TYPE, std::shared_ptr<MPRE_mesh>> meshCache;

    class MPRE_3DPrimitive {

        public:
            MPRE_3DPrimitive(MPRE_PRIMITIVE_3D_TYPE type);
            ~MPRE_3DPrimitive();

            void draw() const {
                this->mesh->draw();
            }

            MPRE_PRIMITIVE_3D_TYPE type;

        private:
            std::shared_ptr<MPRE_mesh> mesh;
            std::unique_ptr<MPRE_Transform> transform;

    };

}
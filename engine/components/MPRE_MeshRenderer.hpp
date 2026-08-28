#pragma once

#include "MPRE_Transform.hpp"
#include "../core/MPRE_mesh.hpp"

#include <memory>
#include <unordered_map>

enum MPRE_MESH_TYPE {CUBE, PYRAMID};

namespace MPRE {

    // Only one mesh for each type of meshes
    inline std::unordered_map<MPRE_MESH_TYPE, std::shared_ptr<MPRE_mesh>> meshCache;

    class MPRE_MeshRenderer : public MPRE_Component {

        public:
            MPRE_MeshRenderer(MPRE_MESH_TYPE type);

            void update(double deltaTime) override {}
            void draw(const MPRE_shaders& shaders, const MPRE_Transform& transform) override;

            MPRE_MESH_TYPE type;

        private:
            std::shared_ptr<MPRE_mesh> mesh;


    };

}
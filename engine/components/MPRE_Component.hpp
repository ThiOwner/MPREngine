#pragma once

#include "../core/MPRE_shaders.hpp"

namespace MPRE {

    class MPRE_Transform;

    class MPRE_Component {
        public:
            virtual ~MPRE_Component() = default;

            virtual void start(){}

            virtual void update(double deltaTime) = 0;

            virtual void draw(const MPRE_shaders& shader, const MPRE_Transform& transform){}
    };

}
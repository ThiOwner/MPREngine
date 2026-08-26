#pragma once

namespace MPRE {

    class MPRE_component {
        public:
            virtual ~MPRE_component() = default;

            virtual void update(double deltaTime) = 0;
    };

}
#pragma once

#include "MPRE_Component.hpp"
#include "MPRE_Transform.hpp"

#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace MPRE {

    class MPRE_Camera : public MPRE_Component {
        public:
            MPRE_Camera(float aspectRatio);

            void update(double deltaTime) override;
            void draw(const MPRE_shaders& shaders, const MPRE_Transform& transform);

            void setAspectRatio(float aspectRatio);

        private:
            glm::mat4 projectionMatrix;
            glm::mat4 viewMatrix;
    };

}

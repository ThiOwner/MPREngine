#pragma once

#include "MPRE_Component.hpp"
#include "MPRE_Transform.hpp"

#include "../core/MPRE_window.hpp"

#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "GLFW/glfw3.h"

namespace MPRE {

    class MPRE_Camera : public MPRE_Component {
        public:
            MPRE_Camera(MPRE_window* window);

            void update(double deltaTime) override;
            void draw(const MPRE_shaders& shaders, const MPRE_Transform& transform) override;

            void setAspectRatio(float aspectRatio);
            void checkingWindowResize();

        private:
            glm::mat4 projectionMatrix;
            glm::mat4 viewMatrix = glm::mat4(1.0f);;

            MPRE_window* attachedWindow;
    };

}

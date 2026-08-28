#pragma once

#include "../components/MPRE_Transform.hpp"
#include "../core/MPRE_shaders.hpp"

#include <memory>

namespace MPRE {

    class MPRE_GameObject {
        public:
            MPRE_GameObject() = default;
            ~MPRE_GameObject() = default;

            void update(double deltaTime);
            void draw(const MPRE_shaders& shader);

            template<typename T, typename... Args>
            T& addComponent(Args&&... args) {

                auto newComponent = std::make_unique<T>(std::forward<Args>(args)...);
                T& ref = *newComponent;
                components.push_back(std::move(newComponent));

                return ref;
            }

            MPRE_Transform transform;

        private:
            std::vector<std::unique_ptr<MPRE_Component>> components;

    };

}

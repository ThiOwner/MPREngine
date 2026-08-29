#include "MPRE_GameObject.hpp"

namespace MPRE {

    void MPRE_GameObject::start() {
        for (auto& component : components) {
            if (component != nullptr) {
                component->start();
            }
        }
    }

    void MPRE_GameObject::update(double deltaTime) {
        for (auto& component : components) {
            if (component != nullptr) {
                component->update(deltaTime);
            }
        }
    }

    void MPRE_GameObject::draw(const MPRE_shaders& shader) {
        for (auto& component : components) {
            if (component != nullptr) {
                component->draw(shader, transform);
            }
        }
    }

}

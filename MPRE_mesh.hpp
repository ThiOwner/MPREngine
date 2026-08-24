#pragma once

#include <vector>

namespace MPRE {

    class MPRE_mesh {
        public:
            MPRE_mesh(std::vector<float> &vertices);
            ~MPRE_mesh();

            MPRE_mesh(const MPRE_mesh&) = delete;
            MPRE_mesh& operator=(const MPRE_mesh&) = delete;

            void bind() const;
            void unbind() const;
            void draw() const;

        private:
            unsigned int VAO{0};
            unsigned int VBO{0};
            unsigned int vertexCount{0};

    };

}
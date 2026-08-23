#pragma once

#include <vector>

namespace VxlE {

    class VxlE_mesh {
        public:
            VxlE_mesh(std::vector<float> &vertices);
            ~VxlE_mesh();

            VxlE_mesh(const VxlE_mesh&) = delete;
            VxlE_mesh& operator=(const VxlE_mesh&) = delete;

            void bind() const;
            void unbind() const;
            void draw() const;

        private:
            unsigned int VAO{0};
            unsigned int VBO{0};
            unsigned int vertexCount{0};

    };

}
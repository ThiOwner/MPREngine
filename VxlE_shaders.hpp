#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "glad/glad.h"

namespace VxlE {

    class VxlE_shaders {
        public:
            VxlE_shaders(const std::string& vertexPath, const std::string& fragmentPath);
            ~VxlE_shaders();

            VxlE_shaders(const VxlE_shaders&) = delete;
            VxlE_shaders& operator=(const VxlE_shaders&) = delete;

            void compileShaders();
            void bindShaderProgram();
            void unbindShaderProgram();

        private:
            [[nodiscard]] const char* getVertexSource() const {return vertexShaderSource.c_str();}
            [[nodiscard]] const char* getFragmentSource() const {return fragmentShaderSource.c_str();}

            std::string vertexShaderSource;
            std::string fragmentShaderSource;

            unsigned int shaderProgram{0};
    };

}

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "glad/glad.h"
#include "glm/fwd.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace MPRE {

    class MPRE_shaders {
        public:
            MPRE_shaders(const std::string& vertexPath, const std::string& fragmentPath);
            ~MPRE_shaders();

            MPRE_shaders(const MPRE_shaders&) = delete;
            MPRE_shaders& operator=(const MPRE_shaders&) = delete;

            void compileShaders();
            void bindShaderProgram();
            void unbindShaderProgram();

            void setBool(const std::string& name, const bool value) const {
                glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), static_cast<int>(value));
            }

            void setInt(const std::string &name, const int value) const {
                glUniform1i(glGetUniformLocation(shaderProgram, name.c_str()), value);
            }

            void setFloat(const std::string &name, const float value) const {
                glUniform1f(glGetUniformLocation(shaderProgram, name.c_str()), value);
            }

            void setMat4(const std::string &name, const glm::mat4 &value) const {
                glUniformMatrix4fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
            }

            void setVec3(const std::string &name, const glm::vec3 &value) const {
                glUniform3fv(glGetUniformLocation(shaderProgram, name.c_str()), 1, glm::value_ptr(value));
            }

        private:
            [[nodiscard]] const char* getVertexSource() const {return vertexShaderSource.c_str();}
            [[nodiscard]] const char* getFragmentSource() const {return fragmentShaderSource.c_str();}

            std::string vertexShaderSource;
            std::string fragmentShaderSource;

            unsigned int shaderProgram{0};
    };

}

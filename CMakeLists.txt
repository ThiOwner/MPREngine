# CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(MPREngine)

set(CMAKE_CXX_STANDARD 17)

# Automatically get GLFW
include(FetchContent)
FetchContent_Declare(glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# Automatically get GLM
include(FetchContent)
FetchContent_Declare(glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG master
)
FetchContent_MakeAvailable(glm)

# Sources files
set(SRC_FILES
        include/src/glad.c

        main/main.cpp

        utils/MPRE_Input_Manager.hpp

        core/MPRE_app.hpp
        core/MPRE_app.cpp
        core/MPRE_window.hpp
        core/MPRE_window.cpp
        core/MPRE_shaders.hpp
        core/MPRE_shaders.cpp
        core/MPRE_mesh.hpp
        core/MPRE_mesh.cpp

        components/MPRE_Component.hpp
        components/MPRE_Transform.hpp
        components/MPRE_Transform.cpp
        components/MPRE_MeshRenderer.hpp
        components/MPRE_MeshRenderer.cpp
        components/MPRE_Camera.hpp
        components/MPRE_Camera.cpp

        scene/MPRE_GameObject.hpp
        scene/MPRE_GameObject.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Where's GLAD ?
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link GLFW and GLM to the OpenGL library
target_link_libraries(${PROJECT_NAME} PRIVATE glm glfw opengl32 )

# Copy the shaders in the runtime environment.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
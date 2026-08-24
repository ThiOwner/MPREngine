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

# Sources files
set(SRC_FILES
        main.cpp
        MPRE_app.hpp
        MPRE_app.cpp
        MPRE_window.hpp
        MPRE_window.cpp
        MPRE_window.cpp
        include/src/glad.c
        MPRE_shaders.hpp
        MPRE_shaders.cpp
        MPRE_mesh.hpp
        MPRE_mesh.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Where's GLAD ?
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link GLFW to the OpenGL library
target_link_libraries(${PROJECT_NAME} PRIVATE glfw opengl32)

# Copy the shaders in the runtime environment.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/shaders
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
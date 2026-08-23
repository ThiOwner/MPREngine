# CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(VxlE_Engine)

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
        VxlE_app.hpp
        VxlE_app.cpp
        VxlE_window.hpp
        VxlE_window.cpp
        VxlE_window.cpp
        include/src/glad.c
)

# Create the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Where's GLAD ?
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link GLFW to the OpenGL library
target_link_libraries(${PROJECT_NAME} PRIVATE glfw opengl32)
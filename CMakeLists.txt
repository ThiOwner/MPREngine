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

set(GLAD_SRC "engine/include/src/glad.c")

file(GLOB_RECURSE ENGINE_SRC CONFIGURE_DEPENDS
        "engine/**/*.cpp"
        "engine/**/*.hpp"
)

file(GLOB_RECURSE GAME_SRC CONFIGURE_DEPENDS
        "game/*.cpp"
        "game/**/*.cpp"
        "game/**/*.hpp"
)

# Source files
set(SRC_FILES
        ${GLAD_SRC}
        ${ENGINE_SRC}
        ${GAME_SRC}
)

# Create the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Where's GLAD ?
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/engine/include)

# Link GLFW and GLM to the OpenGL library
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glm glfw OpenGL::GL)

# Copy the shaders in the runtime environment.
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/engine/shaders
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
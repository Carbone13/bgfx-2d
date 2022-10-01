cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)

project(bgfx_2d)

# Includes
include_directories(bgfx_2d PRIVATE "res/")
include_directories(bgfx_2d PRIVATE "src/")
include_directories(bgfx_2d PRIVATE "lib/bgfx/include")
include_directories(bgfx_2d PRIVATE "lib/bx/include")
include_directories(bgfx_2d PRIVATE "lib/glfw/include")
include_directories(bgfx_2d PRIVATE "lib/bimg/include")
include_directories(bgfx_2d PRIVATE "lib/glm")

# Create .exe
add_executable(bgfx_2d
        src/main.cpp src/main.hpp
        src/servers/visual.cpp src/servers/visual.hpp
        src/global.hpp
        src/servers/input.cpp src/servers/input.hpp
        src/rendering/sprite.cpp src/rendering/sprite.hpp
        src/rendering/vertex.hpp
        src/servers/loader.cpp src/servers/loader.hpp
        src/rendering/camera.cpp src/rendering/camera.hpp src/rendering/texture_atlas.hpp)

# Links libraries
target_link_directories(bgfx_2d PRIVATE "lib/bgfx/.build/")
target_link_directories(bgfx_2d PRIVATE "lib/glfw/.build/")
target_link_libraries(bgfx_2d bgfxRelease bxRelease bimg_decodeRelease bimgRelease glfw3)
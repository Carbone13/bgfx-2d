cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)

project(bgfx_2d)


include_directories(bgfx_2d PRIVATE "res/")
include_directories(bgfx_2d PRIVATE "src/")
include_directories(bgfx_2d PRIVATE "lib/bgfx/include")
include_directories(bgfx_2d PRIVATE "lib/bx/include")
include_directories(bgfx_2d PRIVATE "lib/glfw/include")
include_directories(bgfx_2d PRIVATE "lib/glm")


add_executable(bgfx_2d main.cpp)

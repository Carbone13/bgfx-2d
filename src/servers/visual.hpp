#ifndef BGFX_2D_VISUAL_HPP
#define BGFX_2D_VISUAL_HPP

#include "GLFW/glfw3.h"
#include "rendering/sprite.hpp"
#include "bgfx/bgfx.h"

class Visual
{
    GLFWwindow *window = nullptr;
    bgfx::UniformHandle textureSampler {};

    int width {-1};
    int height {-1};

    bgfx::VertexLayout vertexLayout {};

public:
    Visual (int _w, int _h);

    GLFWwindow *getWindow() { return window; }
    bgfx::VertexLayout getVertexLayout () { return vertexLayout;};

    void blit (Sprite sprite);
};

#endif //BGFX_2D_VISUAL_HPP

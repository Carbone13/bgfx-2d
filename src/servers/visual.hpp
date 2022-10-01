#ifndef BGFX_2D_VISUAL_HPP
#define BGFX_2D_VISUAL_HPP

#include <vector>
#include "GLFW/glfw3.h"
#include "rendering/sprite.hpp"
#include "bgfx/bgfx.h"

class Visual
{
    const uint16_t instanceStride = 64;
    std::vector<Sprite> queuedSprites;

    GLFWwindow *window = nullptr;
    bgfx::UniformHandle textureSampler {};

    int width {-1};
    int height {-1};

    bgfx::VertexLayout vertexLayout {};
    bgfx::VertexBufferHandle vbh {};
    bgfx::IndexBufferHandle ibh {};

    bgfx::ProgramHandle program {};

public:
    Visual (int _w, int _h);

    GLFWwindow *getWindow() { return window; }
    bgfx::VertexLayout getVertexLayout () { return vertexLayout;};

    void blit (Sprite sprite);
    void process();
};

#endif //BGFX_2D_VISUAL_HPP

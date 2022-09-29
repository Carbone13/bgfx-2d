#include "sprite.hpp"
#include "global.hpp"

#include "shaders/color.hpp"

Sprite::Sprite()
{
    vbh = bgfx::createVertexBuffer(bgfx::makeRef(vertices, sizeof(vertices)),
                                   global.Visual.getVertexLayout());

    ibh = bgfx::createIndexBuffer(bgfx::makeRef(indices, sizeof(indices)));

    vs = bgfx::createShader(bgfx::makeRef(color_vs, sizeof(color_vs)));
    fs = bgfx::createShader(bgfx::makeRef(color_fs, sizeof(color_fs)));

    shader = bgfx::createProgram(vs, fs, true);

    texture = global.Loader.loadTexture("2x2.png", BGFX_SAMPLER_MAG_POINT);
}
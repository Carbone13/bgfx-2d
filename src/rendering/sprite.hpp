#ifndef BGFX_2D_SPRITE_HPP
#define BGFX_2D_SPRITE_HPP

#include "vertex.hpp"
#include "bgfx/bgfx.h"

class Sprite
{
    const Vertex vertices[4]
    {
                     // pos           // tex
        Vertex{0.0f, 1.0f, 0, 0x7fff},
        Vertex{1.0f, 0.0f, 0x7fff, 0},
        Vertex{0.0f, 0.0f, 0, 0},
        Vertex{1.0f, 1.0f, 0x7fff, 0x7fff},
    };

    const uint16_t indices[6]
    {
        0, 1, 2,
        0, 3, 1
    };

public:

    Sprite();

    bgfx::VertexBufferHandle vbh {};
    bgfx::IndexBufferHandle ibh {};
    bgfx::TextureHandle texture {};

    bgfx::ShaderHandle vs {};
    bgfx::ShaderHandle fs {};
    bgfx::ProgramHandle shader {};
};

#endif //BGFX_2D_SPRITE_HPP

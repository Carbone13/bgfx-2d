#ifndef BGFX_2D_SPRITE_HPP
#define BGFX_2D_SPRITE_HPP

#include "vertex.hpp"
#include "bgfx/bgfx.h"
#include "glm/glm.hpp"

// TODO auto calculate a model matrix, depending on the texture size
class Sprite
{
public:

    glm::vec2 position {0.0f};
    glm::vec2 scale {1.0f};
    float rotation {0.0f};

    Sprite ()= default;
    explicit Sprite(const char *filePath);

    bgfx::TextureHandle texture {};
};

#endif //BGFX_2D_SPRITE_HPP

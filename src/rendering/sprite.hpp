#ifndef BGFX_2D_SPRITE_HPP
#define BGFX_2D_SPRITE_HPP

#include "vertex.hpp"
#include "bgfx/bgfx.h"
#include "glm/glm.hpp"

class Sprite
{
public:

    glm::vec2 position {0.0f};
    glm::vec2 scale {1.0f};
    float rotation {0.0f};

    Sprite ()= default;
    explicit Sprite(const char *filePath);
    explicit Sprite(const char *filePath, int x, int y, int width, int height);

    bgfx::TextureHandle texture {};
    int textureID {0};
    glm::vec2 begin {0.0f};
    glm::vec2 size {1.0f};
};

#endif //BGFX_2D_SPRITE_HPP

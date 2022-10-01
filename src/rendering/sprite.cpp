#include <iostream>
#include "sprite.hpp"
#include "global.hpp"

const uint64_t pixelArtFlags =
        BGFX_SAMPLER_MAG_POINT |
        BGFX_SAMPLER_MIN_POINT |
        BGFX_SAMPLER_UVW_CLAMP;

Sprite::Sprite(const char* filePath)
{
    bgfx::TextureInfo data {};
    texture = global.Loader.loadTexture(filePath, pixelArtFlags, 0, &data);

    scale = glm::vec2(data.width, data.height);
}

Sprite::Sprite(const char *filePath, int x, int y, int width, int height)
{
    bgfx::TextureInfo data {};
    texture = global.Loader.loadTexture(filePath, pixelArtFlags, 0, &data);

    begin = glm::vec2((float)x / (float)data.width, (float)y / (float)data.height);
    size = glm::vec2((float)width / (float)data.width, (float)height / (float)data.height);

    std::cout << begin.x << "|" << begin.y << " " << size.x << "|" << size.y << std::endl;

    scale = glm::vec2(width, height);
}

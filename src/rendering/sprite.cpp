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
#include "sprite.hpp"
#include "global.hpp"

Sprite::Sprite()
{
    texture = global.Loader.loadTexture("sprite.png", BGFX_SAMPLER_MAG_POINT);
}
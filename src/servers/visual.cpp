#define GLFW_EXPOSE_NATIVE_WIN32

#include "visual.hpp"
#include "bgfx/bgfx.h"
#include "GLFW/glfw3native.h"
#include "bx/math.h"

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

Visual::Visual(int _w, int _h)
{
    width = _w;
    height = _h;

    glfwInit();

    window = glfwCreateWindow(width, height, "2D Renderer", nullptr, nullptr);

    bgfx::PlatformData pd;
    bgfx::Init bgfxInit;
    pd.nwh = glfwGetWin32Window(window);
    bgfxInit.type = bgfx::RendererType::Count; // Automatically choose a renderer.
    bgfxInit.resolution.width = width;
    bgfxInit.resolution.height = height;
    bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
    bgfxInit.platformData = pd;
    bgfx::init(bgfxInit);

    bgfx::reset(width, height, BGFX_RESET_VSYNC, bgfxInit.resolution.format);
    bgfx::setDebug(BGFX_DEBUG_TEXT);
    bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x003030FF, 1.0f, 0);
    bgfx::setViewRect(0, 0, 0, bgfx::BackbufferRatio::Equal);

    textureSampler = bgfx::createUniform("s_texture", bgfx::UniformType::Sampler);

    vertexLayout.begin();
    vertexLayout.add(bgfx::Attrib::Position,
                      2, bgfx::AttribType::Float);
    vertexLayout.add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Int16, true, true);
    vertexLayout.end();
}

void Visual::blit(Sprite sprite)
{
    bgfx::touch(0);

    float proj[16];
    bx::mtxOrtho(
            proj
            , -16.0f / 2.0
            , (float)16.0 / 2.0
            , (float)9.0 / 2.0
            , -9.0f / 2.0
            , -1000.0f
            , 1000.0f
            , 0.0f
            , bgfx::getCaps()->homogeneousDepth
    );

    bgfx::setViewTransform(0, nullptr, proj);

    bgfx::setViewRect(0, 0, 0,
                      1600,
                      900);

    bgfx::setTexture(0, textureSampler, sprite.texture);


    bgfx::setVertexBuffer(0, sprite.vbh);
    bgfx::setIndexBuffer(sprite.ibh);

    bgfx::setState(BGFX_STATE_DEFAULT);

    bgfx::submit(0, sprite.shader);
}

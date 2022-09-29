#define GLFW_EXPOSE_NATIVE_WIN32

#include "visual.hpp"
#include "bgfx/bgfx.h"
#include "GLFW/glfw3native.h"
#include "global.hpp"

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

    global.Camera.prepare();
    auto model = glm::scale(glm::mat4(1.0f), glm::vec3(16.0f, 9.0f, 1.0f));

    bgfx::setTransform(reinterpret_cast< void*>(&model));

    bgfx::setTexture(0, textureSampler, sprite.texture);
    bgfx::setVertexBuffer(0, sprite.vbh);
    bgfx::setIndexBuffer(sprite.ibh);
    bgfx::setState(BGFX_STATE_DEFAULT);
    bgfx::submit(0, sprite.shader);
}

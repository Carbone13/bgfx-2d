#define GLFW_EXPOSE_NATIVE_WIN32

#include <iostream>
#include "visual.hpp"
#include "bgfx/bgfx.h"
#include "GLFW/glfw3native.h"
#include "global.hpp"

#include "_compiled/shaders/sprite/sprite.fs.hpp"
#include "_compiled/shaders/sprite/sprite.vs.hpp"

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

    vbh = bgfx::createVertexBuffer(bgfx::makeRef(vertices, sizeof(vertices)),
                                   global.Visual.getVertexLayout());

    ibh = bgfx::createIndexBuffer(bgfx::makeRef(indices, sizeof(indices)));

    auto vs = bgfx::createShader(bgfx::makeRef(sprite_vs, sizeof(sprite_vs)));
    auto fs = bgfx::createShader(bgfx::makeRef(sprite_fs, sizeof(sprite_fs)));

    program = bgfx::createProgram(vs, fs, true);
}

void Visual::blit(Sprite sprite)
{
    queuedSprites.push_back(sprite);
}

// TODO check if multiple rendering work
void Visual::process ()
{
    global.Camera.prepare();
    bgfx::InstanceDataBuffer idb{};
    bgfx::allocInstanceDataBuffer(&idb, queuedSprites.size(), instanceStride);

    uint8_t *data = idb.data;

    for (auto sprite : queuedSprites)
    {
        auto* mtx = (glm::mat4x4*)(float*)data;

        // translate
        *mtx = glm::translate(glm::mat4x4{1.0f}, glm::vec3(sprite.position, 0.0f));
        // rotate (centered pivot)
        *mtx = glm::translate(*mtx, glm::vec3(0.5f * sprite.scale.x, 0.5f * sprite.scale.y, 0.0f));
        *mtx = glm::rotate(*mtx, glm::radians(sprite.rotation), glm::vec3(0.0f, 0.0f, 1.0f));
        *mtx = glm::translate(*mtx, glm::vec3(-0.5f * sprite.scale.x, -0.5f * sprite.scale.y, 0.0f));
        // scale
        *mtx = glm::scale(*mtx, glm::vec3(sprite.scale, 1.0f));

        auto* textureID = (float*)&data[64];
        textureID[0] = sprite.begin.x;
        textureID[1] = sprite.begin.y;
        textureID[2] = sprite.size.x;
        textureID[3] = sprite.size.y;

        data += instanceStride;

        // Set texture
    bgfx::setTexture(0, textureSampler, sprite.texture);
    }

    // Set vertex and index buffer.
    bgfx::setVertexBuffer(0, vbh);
    bgfx::setIndexBuffer(ibh);

    // Set instance data buffer.
    bgfx::setInstanceDataBuffer(&idb);

    // Set render states.
    bgfx::setState(BGFX_STATE_DEFAULT);

    // Submit primitive for rendering to view 0.
    bgfx::submit(0, program);

    queuedSprites.clear();
}

#ifndef BGFX_2D_GLOBAL_HPP
#define BGFX_2D_GLOBAL_HPP

#include <bgfx/bgfx.h>

#include "servers/visual.hpp"
#include "servers/input.hpp"
#include "servers/loader.hpp"
#include "rendering/camera.hpp"

struct Visual;
struct Input;
struct Loader;
struct Camera;

struct Global
{
    Visual Visual;
    Input Input;
    Loader Loader;
    Camera Camera;

    Global () :
            Visual{1600, 900}, Input{Visual.getWindow()}, Loader{}, Camera{}
    {
    }
};

extern Global &global;

#endif //BGFX_2D_GLOBAL_HPP

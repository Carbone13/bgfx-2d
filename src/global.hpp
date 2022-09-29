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
    const int WINDOW_HEIGHT = 1600;
    const int WINDOW_WIDTH = 900;

    Visual Visual;
    Input Input;
    Loader Loader;
    Camera Camera;

    Global () :
            Visual{WINDOW_HEIGHT, WINDOW_WIDTH}, Input{Visual.getWindow()}, Loader{}, Camera{}
    {
    }
};

extern Global &global;

#endif //BGFX_2D_GLOBAL_HPP

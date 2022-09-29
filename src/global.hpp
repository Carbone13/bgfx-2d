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
    // Application Window size
    const int WINDOW_HEIGHT = 1600;
    const int WINDOW_WIDTH = 900;

    // Rendering screen size (in pixel)
    const int SCREEN_HEIGHT = 16;
    const int SCREEN_WIDTH = 9;

    Visual Visual;
    Input Input;
    Loader Loader;
    Camera Camera;

    Global () :
            Visual{WINDOW_HEIGHT, WINDOW_WIDTH}, Input{Visual.getWindow()}, Loader{}, Camera{SCREEN_HEIGHT, SCREEN_WIDTH}
    {
    }
};

extern Global &global;

#endif //BGFX_2D_GLOBAL_HPP

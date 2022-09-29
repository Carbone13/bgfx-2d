#ifndef BGFX_2D_GLOBAL_HPP
#define BGFX_2D_GLOBAL_HPP

#include <bgfx/bgfx.h>

#include "servers/visual.hpp"
#include "servers/input.hpp"
#include "servers/loader.hpp"

struct Visual;
struct Input;
struct Loader;

struct Global
{
    Visual Visual;
    Input Input;
    Loader Loader;

    Global () :
            Visual{1600, 900}, Input{Visual.getWindow()}, Loader{}
    {
    }
};

extern Global &global;

#endif //BGFX_2D_GLOBAL_HPP

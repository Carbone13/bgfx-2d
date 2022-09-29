#ifndef BGFX_2D_INPUT_HPP
#define BGFX_2D_INPUT_HPP

#include "GLFW/glfw3.h"

class Input
{
    GLFWwindow *window;

public:
    explicit Input (GLFWwindow *_window)
    {
       window = _window;
    }

    bool isKeyPressed(int key);
};

#endif //BGFX_2D_INPUT_HPP

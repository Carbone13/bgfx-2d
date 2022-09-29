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
    int getAxis (int keyA, int keyB);
};

#endif //BGFX_2D_INPUT_HPP

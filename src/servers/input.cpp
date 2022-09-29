#include "input.hpp"

bool Input::isKeyPressed(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

int Input::getAxis(int keyA, int keyB)
{
    int v {0};

    if(isKeyPressed(keyA))
        v++;
    if(isKeyPressed(keyB))
        v--;

    return v;
}
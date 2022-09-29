#include "input.hpp"

bool Input::isKeyPressed(int key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

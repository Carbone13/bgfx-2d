#include <iostream>
#include "main.hpp"
#include "global.hpp"

#include "GLFW/glfw3.h"
#include "bgfx/bgfx.h"

static Global globalState;
Global &global = globalState;

Sprite sprite {};

int main ()
{
    load();

    double lastTime = glfwGetTime();
    while(!glfwWindowShouldClose(global.Visual.getWindow()))
    {
        double delta = glfwGetTime() - lastTime;
        lastTime = glfwGetTime();
        update(delta);
        global.Visual.blit(sprite);

        bgfx::frame();
    }
}

void load ()
{

}

void update (float delta)
{
    glfwPollEvents();

    if(global.Input.isKeyPressed(GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(global.Visual.getWindow(), 1);
    }

    glm::vec2 input { global.Input.getAxis(GLFW_KEY_D, GLFW_KEY_A),
                      global.Input.getAxis(GLFW_KEY_W, GLFW_KEY_S)};
    if (input != glm::zero<glm::vec2>())
        input = glm::normalize(input);

    global.Camera.setPosition(global.Camera.getPosition() + 7.0f * delta * input);
}
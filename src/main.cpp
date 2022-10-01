#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "main.hpp"
#include "global.hpp"

#include "GLFW/glfw3.h"
#include "bgfx/bgfx.h"

static Global globalState;
Global &global = globalState;

Sprite sprite { "res/sprite.png"};
Sprite twoTwo {"res/2x2.png"};
Sprite empty {};
Sprite atlas {"res/atlas.png", 0, 0, 6, 4};

int main ()
{
    load();

    twoTwo.position = glm::vec2(-4.0f, 2.0f);
    double lastTime = glfwGetTime();
    while(!glfwWindowShouldClose(global.Visual.getWindow()))
    {
        double delta = glfwGetTime() - lastTime;
        lastTime = glfwGetTime();

        debug(delta);
        update(delta);

        global.Visual.blit(atlas);

        global.Visual.process();
        bgfx::frame();
    }
}

void debug (double delta)
{
    std::vector<std::pair<std::string, double>> times = {
            { "FRAME: ", delta },
            { "DRAW: ", bgfx::getStats()->gpuTimeEnd }
    };

    int y = 0;
    for (const auto &[s, t] : times) {
        auto str =
                std::stringstream() << s
                                    << std::fixed << std::setprecision(3)
                                    << delta << " ms";
        bgfx::dbgTextPrintf(0, y, ((0x2 + y) << 4) | 0xF, str.str().c_str());
        y++;
    }

    auto str =
            std::stringstream() << "DRAW CALL: " << bgfx::getStats()->numDraw;
    bgfx::dbgTextPrintf(0, y, ((0x2 + 4) << 4) | 0xF, str.str().c_str());
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
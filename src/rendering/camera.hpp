#ifndef BGFX_2D_CAMERA_HPP
#define BGFX_2D_CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/scalar_constants.hpp>

#include <bgfx/bgfx.h>

class Camera
{
    glm::mat4 view {1.0f};
    glm::mat4 proj {1.0f};

    glm::vec2 position {0.0f, 0.0f};
    glm::vec2 oldPosition {0.0f, 0.0f};

    void recalculate();
public:
    // GETTERS
    [[nodiscard]] glm::vec2 getPosition() const { return position; }

    // SETTERS
    void setPosition (glm::vec2 _position);

    void prepare ();

    Camera ()
    {
        recalculate();

        proj = glm::ortho(
                -16.0f / 2.0f
                , (float)16.0f / 2.0f
                , (float)9.0f / 2.0f
                , -9.0f / 2.0f
                , -1000.0f
                , 1000.0f);
    }
};


#endif //BGFX_2D_CAMERA_HPP

$input v_texcoord0, v_texid

#include <bgfx_shader.sh>
#include "shaderlib.sh"

SAMPLER2D(s_texture, 0);

void main()
{
    vec2 uv = vec2(v_texcoord0.x * v_texid.z + v_texid.x, v_texcoord0.y * v_texid.w + v_texid.y);
    gl_FragColor = texture2D(s_texture, uv);
}

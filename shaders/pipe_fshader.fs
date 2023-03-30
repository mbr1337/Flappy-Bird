#version 330 core

layout (location = 0) out vec4 color;

in vec2 tc;

uniform sampler2D tex;
uniform int top;

void main()
{
    vec2 tmp = vec2(tc.x, tc.y);
    // Obraca teksturê jeœli rura jest na górze ekranu.
    if (top == 1)
    {
        tmp.y = 1.0f - tmp.y;
    }

    // Potrzbne by dzia³a przezroczystoœæ.
    color = texture(tex, tmp);
    if (color.w < 1.0f)
    {
        discard;
    }
}
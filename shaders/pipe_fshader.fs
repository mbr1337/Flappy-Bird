#version 330 core

layout (location = 0) out vec4 color;

in vec2 tc;

uniform sampler2D tex;
uniform int top;

void main()
{
    vec2 tmp = vec2(tc.x, tc.y);
    // Obraca tekstur� je�li rura jest na g�rze ekranu.
    if (top == 1)
    {
        tmp.y = 1.0f - tmp.y;
    }

    // Potrzbne by dzia�a przezroczysto��.
    color = texture(tex, tmp);
    if (color.w < 1.0f)
    {
        discard;
    }
}
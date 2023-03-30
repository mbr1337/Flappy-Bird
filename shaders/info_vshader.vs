#version 330 core

layout(location = 0) in vec4 aPos;
layout(location = 1) in vec2 aTex;

uniform mat4 projection;
uniform mat4 model;
uniform mat4 view;

out vec2 tc;

void main()
{
    gl_Position = projection * view * model * aPos;
    tc = aTex;
}
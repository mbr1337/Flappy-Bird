#include "Pipe.h"
#include "GameScreen.h"

const float Pipe::WIDTH = 1.5f;
const float Pipe::HEIGHT = 8.0f;

Texture* Pipe::pipeTexture = nullptr;
Mesh* Pipe::pipeMesh = nullptr;

Pipe::Pipe(float x, float y)
{
    position = glm::vec3(x, y, 0.0f);
    model = glm::mat4(1.0f);
    model = glm::translate(model, position);
}

void Pipe::create()
{
    float vertices[] = {
        // wierzcho³ki          // tekstura
        0.0f, 0.0f, 0.1f,       0.0f, 1.0f,
        0.0f, HEIGHT, 0.1f,     0.0f, 0.0f,
        WIDTH, HEIGHT, 0.1f,    1.0f, 0.0f,
        WIDTH, 0.0f, 0.1f,      1.0f, 1.0f
    };

    int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GameScreen::shaders.insert({"pipeShader", Shader("shaders\\pipe_vshader.vs", "shaders\\pipe_fshader.fs") });
    pipeMesh = new Mesh(vertices, sizeof(vertices), indices, sizeof(indices), sizeof(indices) / sizeof(int));
    pipeTexture = new Texture("textures\\pipe.png");
}
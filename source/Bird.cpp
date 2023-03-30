#include "Bird.h"
#include "GameScreen.h"

Bird::Bird()
{
    position = glm::vec3(0.0f, 0.0f, 0.0f);
    rotation = falling = 0.0f;
    alive = true;

    float vertices[] = {
        // wierzcho³ki                                 // tekstura
        -BIRD_SIZE / 2.0f, -BIRD_SIZE / 2, 0.1f,    0.0f, 1.0f,
        -BIRD_SIZE / 2.0f, BIRD_SIZE / 2, 0.1f,    0.0f, 0.0f,
         BIRD_SIZE / 2.0f, BIRD_SIZE / 2, 0.1f,    1.0f, 0.0f,
         BIRD_SIZE / 2.0f, -BIRD_SIZE / 2, 0.1f,   1.0f, 1.0f
    };

    int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GameScreen::shaders.insert({"birdShader", Shader("shaders\\bird_vshader.vs", "shaders\\bird_fshader.fs") });
    birdMesh = new Mesh(vertices, sizeof(vertices), indices, sizeof(indices), sizeof(indices) / sizeof(int));
    birdTexture = new Texture("textures\\bird.png");
}

Bird::~Bird()
{
    delete birdMesh;
    delete birdTexture;
}

void Bird::update()
{
    if (position.y > - 6.0f)
    {
        position.y -= falling;
    }
    
    if (KeyListener::isKeyPressed(GLFW_KEY_SPACE) && alive)
    {
        falling = -0.15f;
    }
    else
    {
        falling += 0.01f;
    }

    rotation = -falling;
}

void Bird::render()
{
    Shader& birdShader = GameScreen::shaders["birdShader"];
    birdShader.use();

    glm::mat4 translationMatrix = glm::mat4(1.0f);
    translationMatrix = glm::translate(translationMatrix, position);
    translationMatrix = glm::rotate(translationMatrix, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
    birdShader.setMat4("model", translationMatrix);

    birdTexture->bind();
    birdMesh->render();

    birdShader.stop();
}
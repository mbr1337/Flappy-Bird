#include "WelcomeScreen.h"

std::map<std::string, Shader> WelcomeScreen::shaders;

WelcomeScreen::WelcomeScreen()
{
    changing = false;

    float backgroundVertices[] = {
        // wierzcho³ki            // tekstura
        -10.0f, -5.625f, 0.0f,    0.0f, 1.0f,
        -10.0f, 5.625f, 0.0f,    0.0f, 0.0f,
          10.0f,  5.625f, 0.0f,    1.0f, 0.0f,
         10.0f, -5.625f, 0.0f,   1.0f, 1.0f
    };

    float infoVertices[] = {
        // wierzcho³ki         // tekstura
        -1.2f, -0.8f, 0.1f,    0.0f, 1.0f, // lewy dolny
        -1.2f, 0.8f, 0.1f,    0.0f, 0.0f, // lewy górny
          1.2f,  0.8f, 0.1f,    1.0f, 0.0f, // prawy górny
         1.2f, -0.8f, 0.1f,   1.0f, 1.0f // prawy dolny
    };

    int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    backgroundMesh = new Mesh(backgroundVertices, sizeof(backgroundVertices), indices, sizeof(indices), sizeof(indices) / sizeof(int));
    backgroundTexture = new Texture("textures\\welcome.jpeg");

    WelcomeScreen::shaders.insert({ "backgroundShader", Shader("shaders\\bg_vshader.vs", "shaders\\bg_fshader.fs") });
    infoMesh = new Mesh(infoVertices, sizeof(infoVertices), indices, sizeof(indices), sizeof(indices) / sizeof(int));
    infoTexture = new Texture("textures\\info.jpeg");
    WelcomeScreen::shaders.insert({ "infoShader", Shader("shaders\\info_vshader.vs", "shaders\\info_fshader.fs") });
}

WelcomeScreen::~WelcomeScreen()
{
    delete backgroundMesh;
    delete backgroundTexture;
    delete infoMesh;
    delete infoTexture;
}

void WelcomeScreen::render()
{
    Shader& backgroundShader = WelcomeScreen::shaders["backgroundShader"];
    Shader& infoShader = WelcomeScreen::shaders["infoShader"];

    backgroundTexture->bind();
    backgroundShader.use();
    backgroundMesh->bind();

    backgroundShader.setMat4("view", glm::mat4(1.0f));

    backgroundMesh->render();

    backgroundShader.stop();
    backgroundTexture->unbind();

    infoTexture->bind();
    infoShader.use();
    infoMesh->bind();

    infoShader.setMat4("view", glm::mat4(1.0f));
    infoShader.setMat4("model", glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -4.0f, 0.0f)));

    infoMesh->render();

    infoShader.stop();
    infoTexture->unbind();
}

void WelcomeScreen::update()
{
    if (!changing && KeyListener::isKeyPressed(GLFW_KEY_ENTER))
    {
        changing = true;
    }

    if (changing)
    {
        Window::changeScreen(1);
    }
}
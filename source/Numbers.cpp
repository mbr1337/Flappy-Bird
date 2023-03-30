#include "Numbers.h"
#include "GameScreen.h"

Mesh*  Numbers::numberMesh = nullptr;
std::map<char, Texture> Numbers::numbersMap;

void Numbers::create()
{
    float vertices[] = {
        // wierzcho³ki        // tekstura
        -0.6f, -1.2f, 0.1f,   0.0f, 1.0f, // lewy dolny
        -0.6f, 1.2f, 0.1f,    0.0f, 0.0f, // lewy górny
         0.6f,  1.2f, 0.1f,   1.0f, 0.0f, // prawy górny
         0.6f, -1.2f, 0.1f,   1.0f, 1.0f // prawy dolny
    };

    int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GameScreen::shaders.insert({ "numberShader", Shader("shaders\\info_vshader.vs", "shaders\\info_fshader.fs") });
    numberMesh = new Mesh(vertices, sizeof(vertices), indices, sizeof(indices), sizeof(indices) / sizeof(int));
    
    Numbers::numbersMap.insert({ '0', Texture("textures\\numbers\\zero.png") });
    Numbers::numbersMap.insert({ '1', Texture("textures\\numbers\\one.png") });
    Numbers::numbersMap.insert({ '2', Texture("textures\\numbers\\two.png") });
    Numbers::numbersMap.insert({ '3', Texture("textures\\numbers\\three.png") });
    Numbers::numbersMap.insert({ '4', Texture("textures\\numbers\\four.png") });
    Numbers::numbersMap.insert({ '5', Texture("textures\\numbers\\five.png") });
    Numbers::numbersMap.insert({ '6', Texture("textures\\numbers\\six.png") });
    Numbers::numbersMap.insert({ '7', Texture("textures\\numbers\\seven.png") });
    Numbers::numbersMap.insert({ '8', Texture("textures\\numbers\\eight.png") });
    Numbers::numbersMap.insert({ '9', Texture("textures\\numbers\\nine.png") });
}
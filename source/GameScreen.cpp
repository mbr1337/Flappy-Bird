#include "GameScreen.h"
#include "KeyListener.h"
#include "Window.h"

#include <iostream>
#include <ctime>

std::map<std::string, Shader> GameScreen::shaders;

void GameScreen::createPipes()
{
    Pipe::create();
    for (size_t i = 0; i < NUMBER_OF_PIPES; i += 2, pipeIndex += 2)
    {
        pipes.push_back(Pipe(OFFSET + pipeIndex * 3.0f, Random::generate(0.0f, 4.0f)));
        pipes.push_back(Pipe(pipes[i].getX(), pipes[i].getY() - 11.5f));
    }
}

void GameScreen::renderPipes()
{
    Shader& pipe = GameScreen::shaders["pipeShader"];
    pipe.use();
    glm::mat4 tmp = glm::mat4(1.0f);
    pipe.setMat4("view", glm::translate(tmp, glm::vec3(horizontalScroll * 0.05f, 0.0f, 0.0f)));
    Pipe::getTexture()->bind();
    Pipe::getMesh()->bind();

    for (size_t i = 0; i < NUMBER_OF_PIPES; i++)
    {
        pipe.setMat4("model", pipes[i].getModel());
        int isPipeTop = i % 2 == 0 ? 1 : 0;
        pipe.setInt("top", isPipeTop);
        Pipe::getMesh()->render();
    }

    pipe.stop();

    Pipe::getMesh()->unbind();
    Pipe::getTexture()->unbind();
}

void GameScreen::updatePipes()
{
    // W zasadzie nieskoñczona pêtla.
    pipes[pipeIndex % NUMBER_OF_PIPES] = Pipe(OFFSET + pipeIndex * 3.0f, Random::generate(0.0f, 4.0f));
    pipes[(pipeIndex + 1) % NUMBER_OF_PIPES] = Pipe(pipes[pipeIndex % NUMBER_OF_PIPES].getX(), pipes[pipeIndex % NUMBER_OF_PIPES].getY() - 11.5f);
    pipeIndex += 2;
}

void GameScreen::renderNumbers()
{
    std::string tmp = std::to_string(points);
    Shader& number = GameScreen::shaders["numberShader"];
    number.use();
    Numbers::getMesh()->bind();

    for (size_t i = 0; i < numbers.size(); i++)
    {
        Texture& texture = Numbers::numbersMap[tmp[i]];
        texture.bind();

        number.setMat4("view", glm::mat4(1.0f));
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(i * 1.2f, 4.0f, 0.0f));
        number.setMat4("model", model);

        Numbers::getMesh()->render();
        texture.unbind();
    }

    number.stop();

    Numbers::getMesh()->unbind();
}

void GameScreen::updateNumbers()
{
    std::string tmp = std::to_string(points);
    numbers.clear();

    for (size_t i = 0; i < tmp.length(); i++)
    {
        numbers.push_back(Numbers(tmp[i]));
    }
}

void GameScreen::addPoints()
{
    for (size_t i = 0; i < NUMBER_OF_PIPES; i += 2)
    {
        float birdX = -horizontalScroll * 0.05f;
        float birdY = bird->getY();
        float pipeUpX = pipes[i].getX();
        float pipeUpY = pipes[i].getY();
        float pipeDownX = pipes[i + 1].getX();
        float pipeDownY = pipes[i + 1].getY();

        // Granica dooko³a ptaszka.
        // Lewa czêœæ ptaszka.
        float birdX0 = birdX - bird->BIRD_SIZE / 2.0f;
        // Prawa czêœæ ptaszka.
        float birdX1 = birdX + bird->BIRD_SIZE / 2.0f;
        // Spód                    
        float birdY0 = birdY - bird->BIRD_SIZE / 2.0f;
        // Góra                    
        float birdY1 = birdY + bird->BIRD_SIZE / 2.0f;

        // Granica dooko³a rury.
        float pipeUpX0 = pipeUpX;
        float pipeUpX1 = pipeUpX + Pipe::WIDTH;
        float pipeUpY0 = pipeUpY;
        float pipeUpY1 = pipeUpY + Pipe::HEIGHT;

        float pipeDownX0 = pipeDownX;
        float pipeDownX1 = pipeDownX + Pipe::WIDTH;
        float pipeDownY0 = pipeDownY;
        float pipeDownY1 = pipeDownY + Pipe::HEIGHT;

        if (birdX1 > pipeUpX0 + (Pipe::WIDTH / 2) && birdX1 < pipeUpX1 - (Pipe::WIDTH / 2.3))
        {
            if (birdY1 < pipeUpY1 && birdY0 > pipeDownY0)
            {
                points++;
            }
        }
    }
}

bool GameScreen::pipeCollision()
{
    for (size_t i = 0; i < NUMBER_OF_PIPES; i++)
    {
        float birdX = -horizontalScroll * 0.05f;
        float birdY = bird->getY();
        float pipeX = pipes[i].getX();
        float pipeY = pipes[i].getY();

        // Granica dooko³a ptaszka.
        // Lewa czêœæ ptaszka.
        float birdX0 = birdX - bird->BIRD_SIZE / 2.0f;
        // Prawa czêœæ ptaszka.
        float birdX1 = birdX + bird->BIRD_SIZE / 2.0f;
        // Spód                    
        float birdY0 = birdY - bird->BIRD_SIZE / 2.0f;
        // Góra                    
        float birdY1 = birdY + bird->BIRD_SIZE / 2.0f;

        // Granica dooko³a rury.
        float pipeX0 = pipeX;
        float pipeX1 = pipeX + Pipe::WIDTH;
        float pipeY0 = pipeY;
        float pipeY1 = pipeY + Pipe::HEIGHT;

        // Ptaszek jest wewn¹trz rury.
        if (birdX1 > pipeX0 && birdX0 < pipeX1)
        {
            if (birdY1 > pipeY0 && birdY0 < pipeY1)
            {
                return true;
            }
        }

        // Ptaszek uderzy³ w górê lub dó³ ekranu.
        if (birdY1 >= 10.0f * 9.0f / 16.0f || birdY0 <= -10.0f * 9.0f / 16.0f)
        {
            return true;
        }
    }

    return false;
}

GameScreen::GameScreen()
{
    horizontalScroll = scrollIndex = pipeIndex = points = 0;
    control = true;

    float backgroundVertices[] = {
        // wierzcho³ki               // tekstura
        -10.0f, -5.625f, 0.0f,    0.0f, 1.0f,
        -10.0f, 5.625f, 0.0f,    0.0f, 0.0f,
          0.0f,  5.625f, 0.0f,    1.0f, 0.0f,
         0.0f, -5.625f, 0.0f,   1.0f, 1.0f
    };

    float infoVertices[] = {
        // wierzcho³ki               // tekstura
        -1.2f, -0.8f, 0.0f,    0.0f, 1.0f, // lewy dolny
        -1.2f, 0.8f, 0.0f,    0.0f, 0.0f, // lewy górny
          1.2f, 0.8f, 0.0f,    1.0f, 0.0f, // prawy górny
         1.2f, -0.8f, 0.0f,   1.0f, 1.0f // prawy dolny
    };

    int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    backgroundMesh = new Mesh(backgroundVertices, sizeof(backgroundVertices), indices, sizeof(indices), sizeof(indices) / sizeof(int));
    backgroundTexture = new Texture("textures\\bg.jpeg");
    GameScreen::shaders.insert({ "backgroundShader", Shader("shaders\\bg_vshader.vs", "shaders\\bg_fshader.fs") });
    infoMesh = new Mesh(infoVertices, sizeof(infoVertices), indices, sizeof(indices), sizeof(indices) / sizeof(int));
    infoTexture = new Texture("textures\\end.jpeg");
    GameScreen::shaders.insert({ "infoShader", Shader("shaders\\info_vshader.vs", "shaders\\info_fshader.fs") });

    bird = new Bird();
    createPipes();
    Numbers::create();
}

GameScreen::~GameScreen()
{
    delete Pipe::getTexture();
    delete Pipe::getMesh();

    delete backgroundTexture;
    delete backgroundMesh;
    delete infoMesh;
    delete infoTexture;
    delete bird;
}

void GameScreen::update()
{
    if (control)
    {
        horizontalScroll--;
        if (-horizontalScroll % 335 == 0)
        {
            scrollIndex++;
        }

        if (-horizontalScroll > 250 && -horizontalScroll % 120 == 0)
        {
            updatePipes();
        }
    }

    bird->update();

    if (control && pipeCollision())
    {
        bird->setAlive(false);
        bird->fall();
        control = false;
    }
    else
    {
        addPoints();
        updateNumbers();
    }

    if (!control && KeyListener::isKeyPressed(GLFW_KEY_R))
    {
        Window::changeScreen(1);
    }
}

void GameScreen::render()
{
    Shader& backgroundShader = GameScreen::shaders["backgroundShader"];
    Shader& infoShader = GameScreen::shaders["infoShader"];

    backgroundTexture->bind();
    backgroundShader.use();
    backgroundMesh->bind();
    for (int i = scrollIndex; i < scrollIndex + 3; i++)
    {
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(i * 10.0f + horizontalScroll * 0.03f, 0.0f, 0.0f));
        backgroundShader.setMat4("view", view);
        backgroundMesh->render();
    }

    backgroundShader.stop();
    backgroundTexture->unbind();

    renderPipes();
    bird->render();
    renderNumbers();

    if (!bird->isAlive())
    {
        infoTexture->bind();
        infoShader.use();
        infoMesh->bind();

        infoShader.setMat4("view", glm::mat4(1.0f));
        glm::mat4 translationMatrix = glm::mat4(1.0f);
        translationMatrix = glm::scale(translationMatrix, glm::vec3(2.0f, 2.0f, 0.0f));
        infoShader.setMat4("model", translationMatrix);

        infoMesh->render();

        infoShader.stop();
        infoTexture->unbind();
    }
}
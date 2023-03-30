#pragma once

#include "Screen.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "Bird.h"
#include "Pipe.h"
#include "Random.h"
#include "Numbers.h"

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

#include <vector>
#include <map>

/**
 * @brief Klasa zajmuj�ca sie wy�wietlaniem pola gry oraz kontroluje to co si� na nim dzieje.
*/
class GameScreen : public Screen
{
private:
	Mesh* backgroundMesh;
	Texture* backgroundTexture;
	Mesh* infoMesh;
	Texture* infoTexture;

	Bird* bird;
	std::vector<Pipe> pipes;
	std::vector<Numbers> numbers;

	// Sk�adowa �ledz�ca przewijanie. Wykorzystywana do przewijania t�a, rur oraz obiczania pozycji ptaszka wzgl�dem przeszk�d.
	int horizontalScroll;
	// Sk�adowa pomocnicza zliczaj�ca ile kawa�k�w t�a ju� przemin�o. Dzi�ki niej mo�liwe jest przewijanie go w niesko�czono��.
	int scrollIndex;
	int pipeIndex;
	int points;
	bool control;
	// Przesuni�cie, by rury nie pojaiwa�y si� od razu przed ptaszkiem.
	const float OFFSET = 5.0f;
	const int NUMBER_OF_PIPES = 10;
	
	/**
	 * @brief Tworzy vector rur do wy�wietlenia.
	*/
	void createPipes();
	/**
	 * @brief Renderuje rury na ekranie.
	*/
	void renderPipes();

	/**
	 * @brief Tworzy nowe rury po wyj�ciu pary poza ekran.
	*/
	void updatePipes();

	/**
	 * @brief Renderuje Wynik gracza na g�rze ekranu.
	*/
	void renderNumbers();

	/**
	 * @brief Aktualizuje wynik na ekranie zgodnie z post�pami gracza.
	*/
	void updateNumbers();

	/**
	 * @brief Zlicza punkty zdobywane podczas gry.
	*/
	void addPoints();

	/**
	 * @brief Zajmuje si� sprawdzeniem kolizji ptaszka z elementami w grze.
	 * @return true, je�li nast�pi�a kolizja, false je�li nie.
	*/
	bool pipeCollision();
public:

	/**
	 * @brief Mapa zwieraj�ca wszystkie shadery u�ywane na tym ekranie.
	*/
	static std::map<std::string, Shader> shaders;

	/**
	 * @brief Inicjalizuje gr�.
	*/
	GameScreen();
	~GameScreen();

	/**
	 * @brief Aktualizuje to co dzieje si� w grze.
	*/
	void update();

	/**
	 * @brief Renderuje gr�.
	*/
	void render();
};

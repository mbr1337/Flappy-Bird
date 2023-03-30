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
 * @brief Klasa zajmuj¹ca sie wyœwietlaniem pola gry oraz kontroluje to co siê na nim dzieje.
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

	// Sk³adowa œledz¹ca przewijanie. Wykorzystywana do przewijania t³a, rur oraz obiczania pozycji ptaszka wzglêdem przeszkód.
	int horizontalScroll;
	// Sk³adowa pomocnicza zliczaj¹ca ile kawa³ków t³a ju¿ przeminê³o. Dziêki niej mo¿liwe jest przewijanie go w nieskoñczonoœæ.
	int scrollIndex;
	int pipeIndex;
	int points;
	bool control;
	// Przesuniêcie, by rury nie pojaiwa³y siê od razu przed ptaszkiem.
	const float OFFSET = 5.0f;
	const int NUMBER_OF_PIPES = 10;
	
	/**
	 * @brief Tworzy vector rur do wyœwietlenia.
	*/
	void createPipes();
	/**
	 * @brief Renderuje rury na ekranie.
	*/
	void renderPipes();

	/**
	 * @brief Tworzy nowe rury po wyjœciu pary poza ekran.
	*/
	void updatePipes();

	/**
	 * @brief Renderuje Wynik gracza na górze ekranu.
	*/
	void renderNumbers();

	/**
	 * @brief Aktualizuje wynik na ekranie zgodnie z postêpami gracza.
	*/
	void updateNumbers();

	/**
	 * @brief Zlicza punkty zdobywane podczas gry.
	*/
	void addPoints();

	/**
	 * @brief Zajmuje siê sprawdzeniem kolizji ptaszka z elementami w grze.
	 * @return true, jeœli nast¹pi³a kolizja, false jeœli nie.
	*/
	bool pipeCollision();
public:

	/**
	 * @brief Mapa zwieraj¹ca wszystkie shadery u¿ywane na tym ekranie.
	*/
	static std::map<std::string, Shader> shaders;

	/**
	 * @brief Inicjalizuje grê.
	*/
	GameScreen();
	~GameScreen();

	/**
	 * @brief Aktualizuje to co dzieje siê w grze.
	*/
	void update();

	/**
	 * @brief Renderuje grê.
	*/
	void render();
};

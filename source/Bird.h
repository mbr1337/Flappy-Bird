#pragma once

#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"
#include "KeyListener.h"

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

/**
 * @brief Klasa reprezentuj¹ca ptaszka w grze, jego stan (¿ywy lub nie) i po³o¿enie.
*/
class Bird
{
private:
	Mesh* birdMesh;
	Texture* birdTexture;
	glm::vec3 position;
	
	float rotation;
	float falling;
	bool alive;

public:
	const float BIRD_SIZE = 1.0f;

	Bird();
	~Bird();

	/**
	 * @brief Metoda odpowiedzialna za zmianê pozycji ptaszka, oraz sterowanie nim.
	*/
	void update();

	/**
	 * @brief Rysowanie ptaszka.
	*/
	void render();

	/**
	 * @brief Opadanie ptaszka po kolizji z przeszkod¹ (rura, kraniec pola gry).
	*/
	void fall() { falling = -0.15f; }

	/**
	 * @brief Zwraca koordynaty x ptaszka.
	 * @return po³o¿enie ptaszka w osi x
	*/
	float getX() { return position.x; }

	/**
	 * @brief Zwraca koordynaty y ptaszka.
	 * @return po³o¿enie ptaszka w osi y
	*/
	float getY() { return position.y; }

	/**
	 * @brief Zwraca stan ptaszka.
	 * @return true, jeœli ptaszek ¿yje, w przeciwnym wypadku false.
	*/
	bool isAlive() { return alive; }

	/**
	 * @brief Zmienia stan ptaszka.
	 * @param value true - ptaszek ¿yje, false nie ¿yje
	*/
	void setAlive(bool value) { alive = value; }
};
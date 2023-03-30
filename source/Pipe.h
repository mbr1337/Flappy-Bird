#pragma once
#include "Texture.h"
#include "Mesh.h"
#include "Shader.h"

#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

class Pipe
{
private:
	glm::vec3 position;
	glm::mat4 model;

	static Texture* pipeTexture;
	static Mesh* pipeMesh;

public:
	/**
	 * @brief Szerokoœæ rury
	*/
	static const float WIDTH;

	/**
	 * @brief Wysokoœæ rury
	*/
	static const float HEIGHT;

	/**
	 * @brief Konstruktor tworz¹cy obiekt Pipe o zdanych wspó³rzêdnych
	 * @param x wspó³rzêdna x rury
	 * @param y wspó³rzêdna y rury
	*/
	Pipe(float x, float y);

	/**
	 * @brief Zwraca po³o¿enie rury w osi x
	 * @return po³o¿enie rury w osi x
	*/
	float getX() { return position.x; }

	/**
	 * @brief Zwraca po³o¿enie rury w osi y
	 * @return po³o¿enie rury w osi y
	*/
	float getY() { return position.y; }

	/**
	 * @brief Zwraca macierz, w której zapisywane s¹ wszystkie przekszta³cenia modelu (translacja, roacja, skalowanie.)
	 * @return macierz
	*/
	glm::mat4 getModel() { return model; }

	/**
	 * @brief Tworzy siatkê i wczytuje teksturê.
	*/
	static void create();

	/**
	 * @brief Zwraca siatkê, na któr¹ nak³adana jest tekstura.
	 * @return wskaŸnik na siatkê
	*/
	static Mesh* getMesh() { return pipeMesh; }

	/**
	 * @brief Zwraca teksturê, rury.
	 * @return wskaŸnik na teksturê
	*/
	static Texture* getTexture() { return pipeTexture; }
};

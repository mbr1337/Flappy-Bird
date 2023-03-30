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
	 * @brief Szeroko�� rury
	*/
	static const float WIDTH;

	/**
	 * @brief Wysoko�� rury
	*/
	static const float HEIGHT;

	/**
	 * @brief Konstruktor tworz�cy obiekt Pipe o zdanych wsp�rz�dnych
	 * @param x wsp�rz�dna x rury
	 * @param y wsp�rz�dna y rury
	*/
	Pipe(float x, float y);

	/**
	 * @brief Zwraca po�o�enie rury w osi x
	 * @return po�o�enie rury w osi x
	*/
	float getX() { return position.x; }

	/**
	 * @brief Zwraca po�o�enie rury w osi y
	 * @return po�o�enie rury w osi y
	*/
	float getY() { return position.y; }

	/**
	 * @brief Zwraca macierz, w kt�rej zapisywane s� wszystkie przekszta�cenia modelu (translacja, roacja, skalowanie.)
	 * @return macierz
	*/
	glm::mat4 getModel() { return model; }

	/**
	 * @brief Tworzy siatk� i wczytuje tekstur�.
	*/
	static void create();

	/**
	 * @brief Zwraca siatk�, na kt�r� nak�adana jest tekstura.
	 * @return wska�nik na siatk�
	*/
	static Mesh* getMesh() { return pipeMesh; }

	/**
	 * @brief Zwraca tekstur�, rury.
	 * @return wska�nik na tekstur�
	*/
	static Texture* getTexture() { return pipeTexture; }
};

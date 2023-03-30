#pragma once
#include "Texture.h"
#include "Mesh.h"
#include "Shader.h"

#include <map>

class Numbers
{
private:
	int number;

	static Mesh* numberMesh;

public:
	/**
	 * @brief Tworzy obiekt z zadan� cyfr�.
	 * @param num 
	*/
	Numbers(int num) { number = num; }

	/**
	 * @brief Mapa przechowujaca tekstury cyfr.
	 * Np. numbersMap['2'] zwr�cy tekstur� cyfry '2'.
	*/
	static std::map<char, Texture> numbersMap;

	/**
	 * @brief Tworzy siatk�, na kt�rej b�d� wy�wietlane cyfry, oraz �aduje tekstury.
	*/
	void static create();

	/**
	 * @brief Zwraca siatk�, na kt�rej wy�wietlane s� cyfry.
	 * @return wska�nik na obiekt typu Mesh
	*/
	static Mesh* getMesh() { return numberMesh; }

	/**
	 * @brief Zwraca cyfr� przechowywan� w danej instancji.
	 * @return cyfra
	*/
	int getNumber() { return number; }
};
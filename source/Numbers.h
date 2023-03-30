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
	 * @brief Tworzy obiekt z zadan¹ cyfr¹.
	 * @param num 
	*/
	Numbers(int num) { number = num; }

	/**
	 * @brief Mapa przechowujaca tekstury cyfr.
	 * Np. numbersMap['2'] zwrócy teksturê cyfry '2'.
	*/
	static std::map<char, Texture> numbersMap;

	/**
	 * @brief Tworzy siatkê, na której bêd¹ wyœwietlane cyfry, oraz ³aduje tekstury.
	*/
	void static create();

	/**
	 * @brief Zwraca siatkê, na której wyœwietlane s¹ cyfry.
	 * @return wskaŸnik na obiekt typu Mesh
	*/
	static Mesh* getMesh() { return numberMesh; }

	/**
	 * @brief Zwraca cyfrê przechowywan¹ w danej instancji.
	 * @return cyfra
	*/
	int getNumber() { return number; }
};
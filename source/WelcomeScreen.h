#pragma once
#include "Screen.h"
#include "KeyListener.h"
#include "Window.h"
#include "Mesh.h"
#include "Texture.h"
#include "Shader.h"

#include <iostream>
#include <map>

class WelcomeScreen : public Screen
{
private:
	Mesh* backgroundMesh;
	Texture* backgroundTexture;
	Mesh* infoMesh;
	Texture* infoTexture;

	bool changing;

public:

	/**
	 * @brief Mapa zwieraj¹ca shadery u¿ywane na tym ekranie.
	*/
	static std::map<std::string, Shader> shaders;

	/**
	 * @brief Inicjalizuje ekran
	*/
	WelcomeScreen();
	~WelcomeScreen();

	/**
	 * @brief Renderuje obiekty na ekranie.
	*/
	void render();

	/**
	 * @brief Aktualizuje logikê gry.
	*/
	void update();

};
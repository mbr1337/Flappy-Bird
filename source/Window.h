#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "KeyListener.h"
#include "Shader.h"
#include "Screen.h"
#include "WelcomeScreen.h"
#include "GameScreen.h"
#include "Random.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

class Window
{
private:
	std::string title;
	GLFWwindow* glfwWindow;
	
	static Screen* game;
	static Window* window;

	int width, height;

	Window();

	void init();
	void loop();
public:
	~Window();

	/**
	 * @brief Inicjalizuje OpenGL i uruchamia pêtlê gry.
	*/
	void run();

	/**
	 * @brief Zmienia ekran gry.
	 * @param screen numer ekranu (od 0)
	*/
	static void changeScreen(int screen);

	/**
	 * @brief Zwraca obiekt typu Window.
	 * @return wskaŸnik na Window
	*/
	static Window* get();

	/**
	 * @brief Metoda zapewniaj¹ca poprawne skalowanie obrazu po zmianie rozmiaru okna.
	 * @param window wskaŸnik typu GLFWwindow
	 * @param width szerokoœæ okna
	 * @param height wysokoœæ okna
	*/
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
};
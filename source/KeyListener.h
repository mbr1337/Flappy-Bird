#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

/**
 * @brief Klasa zajmujaca si� "nas�uchiwaniem" wci�ni�� klawiszy na klawiaturze.
*/
class KeyListener
{
private:
	static KeyListener* instance;

	bool keyPressed[GLFW_KEY_LAST];
	KeyListener();
public:
	~KeyListener();

	/**
	 * @brief W�a�ciwa metoda zajmujaca si� nas�uchiwaniem kalwiatury.
	 * @param window wska�nik typu GLFWwindow do okna, w kt�rym chcemy nas�uchiwa�.
	 * @param key klawisz na klawiaturze 
	 * @param scancode kod klawisza
	 * @param action rodzaj wykonanej akcji (naci�ni�cie, puszczenie)
	 * @param mods modyfikatory np. Shif + klawisz
	*/
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	/**
	 * @brief Zwraca obiekt KeyListener.
	 * @return obiekt KeyListener
	*/
	static KeyListener* get();

	/**
	 * @brief Sprawdza czy klawisz o danym kodzie zosta� naci�ni�ty.
	 * @param keyCode kod klawisza
	 * @return true je�li dany klawisz zosta� naci�ni�ty, w przeciwnym wypadku false
	*/
	static bool isKeyPressed(int keyCode);
};

#endif

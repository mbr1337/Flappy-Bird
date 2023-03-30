#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

/**
 * @brief Klasa zajmujaca siê "nas³uchiwaniem" wciœniêæ klawiszy na klawiaturze.
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
	 * @brief W³aœciwa metoda zajmujaca siê nas³uchiwaniem kalwiatury.
	 * @param window wskaŸnik typu GLFWwindow do okna, w którym chcemy nas³uchiwaæ.
	 * @param key klawisz na klawiaturze 
	 * @param scancode kod klawisza
	 * @param action rodzaj wykonanej akcji (naciœniêcie, puszczenie)
	 * @param mods modyfikatory np. Shif + klawisz
	*/
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	/**
	 * @brief Zwraca obiekt KeyListener.
	 * @return obiekt KeyListener
	*/
	static KeyListener* get();

	/**
	 * @brief Sprawdza czy klawisz o danym kodzie zosta³ naciœniêty.
	 * @param keyCode kod klawisza
	 * @return true jeœli dany klawisz zosta³ naciœniêty, w przeciwnym wypadku false
	*/
	static bool isKeyPressed(int keyCode);
};

#endif

#include "KeyListener.h"

KeyListener* KeyListener::instance = nullptr;

KeyListener* KeyListener::get()
{
	if (KeyListener::instance == nullptr)
	{
		KeyListener::instance = new KeyListener();
	}

	return KeyListener::instance;
}

KeyListener::KeyListener()
{
	for (size_t i = 0; i < GLFW_KEY_LAST; i++)
	{
		keyPressed[i] = false;
	}	
}

KeyListener::~KeyListener()
{
	delete KeyListener::instance;
}

void KeyListener::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		get()->keyPressed[key] = true;
	}
	else if (action == GLFW_RELEASE)
	{
		get()->keyPressed[key] = false;
	}
}

bool KeyListener::isKeyPressed(int keyCode)
{
	return get()->keyPressed[keyCode];
}
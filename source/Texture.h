#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Texture
{
private:
	unsigned textureID;
	int width, height;
	int nrChannels;
public:
	Texture() { textureID = width = height = nrChannels = 0; };

	/**
	 * @brief £aduje teksturê z podanej lokalizacji.
	 * @param path lokalizacja tekstury
	*/
	Texture(const char* path);

	void bind() { glBindTexture(GL_TEXTURE_2D, textureID); }
	void unbind() { glBindTexture(GL_TEXTURE_2D, 0); }
};
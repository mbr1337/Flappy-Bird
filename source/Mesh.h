#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh
{
private:
	// Przechowuej dane o wi�zaniach w tablicy wierzcho�k�w. 
	unsigned vao;
	// Bufor przechowujacy wierzcho�ki.
	unsigned vbo;
	unsigned ebo;
	int verticesCount;

	void draw();
public:
	/**
	 * @brief Tworzy now� siatk� na podstawie podanej tablicy wierzcho�k�w
	 * @param vertices  wierzcho�ki
	 * @param sizeOfVertices rozmair tablicy wierzcho�k�w w bajtach
	 * @param indices tablica kolejno�ci wierzcho�k�w dla EBO
	 * @param sizeOfIndices rozmiar tablicy z kolejno�ci� wierzcho�k�w w bajtach
	 * @param indicesLen ilo�� element�w w tablicy indices
	*/
	Mesh(float* vertices, size_t sizeOfVertices, int* indices, size_t sizeOfIndices, int indicesLen);

	/**
	 * @brief Dowi�zanie VAO, dla kt�rego tworzona jest siatka.
	*/
	void bind();

	/**
	 * @brief Odczepienie VAO.
	*/
	void unbind();

	/**
	 * @brief Renderuje utworzon� siatk�
	*/
	void render();
};
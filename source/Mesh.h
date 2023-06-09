#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh
{
private:
	// Przechowuej dane o wiązaniach w tablicy wierzchołków. 
	unsigned vao;
	// Bufor przechowujacy wierzchołki.
	unsigned vbo;
	unsigned ebo;
	int verticesCount;

	void draw();
public:
	/**
	 * @brief Tworzy nową siatkę na podstawie podanej tablicy wierzchołków
	 * @param vertices  wierzchołki
	 * @param sizeOfVertices rozmair tablicy wierzchołków w bajtach
	 * @param indices tablica kolejności wierzchołków dla EBO
	 * @param sizeOfIndices rozmiar tablicy z kolejnością wierzchołków w bajtach
	 * @param indicesLen ilość elementów w tablicy indices
	*/
	Mesh(float* vertices, size_t sizeOfVertices, int* indices, size_t sizeOfIndices, int indicesLen);

	/**
	 * @brief Dowiązanie VAO, dla którego tworzona jest siatka.
	*/
	void bind();

	/**
	 * @brief Odczepienie VAO.
	*/
	void unbind();

	/**
	 * @brief Renderuje utworzoną siatkę
	*/
	void render();
};
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Mesh
{
private:
	// Przechowuej dane o wi¹zaniach w tablicy wierzcho³ków. 
	unsigned vao;
	// Bufor przechowujacy wierzcho³ki.
	unsigned vbo;
	unsigned ebo;
	int verticesCount;

	void draw();
public:
	/**
	 * @brief Tworzy now¹ siatkê na podstawie podanej tablicy wierzcho³ków
	 * @param vertices  wierzcho³ki
	 * @param sizeOfVertices rozmair tablicy wierzcho³ków w bajtach
	 * @param indices tablica kolejnoœci wierzcho³ków dla EBO
	 * @param sizeOfIndices rozmiar tablicy z kolejnoœci¹ wierzcho³ków w bajtach
	 * @param indicesLen iloœæ elementów w tablicy indices
	*/
	Mesh(float* vertices, size_t sizeOfVertices, int* indices, size_t sizeOfIndices, int indicesLen);

	/**
	 * @brief Dowi¹zanie VAO, dla którego tworzona jest siatka.
	*/
	void bind();

	/**
	 * @brief Odczepienie VAO.
	*/
	void unbind();

	/**
	 * @brief Renderuje utworzon¹ siatkê
	*/
	void render();
};
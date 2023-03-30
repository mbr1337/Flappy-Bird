#pragma once

#include "glad/glad.h"
#include "../glm/glm.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Klasa odpowiedzialna za ³adowanie shaderów z plików o podanej œcie¿ce. Jest to ta sama klasa, której u¿ywaliœmy podczas zajêæ.
*/
class Shader
{
public:
    // ID nadane wygenerowanemu shader'owi.
	unsigned ID;

    Shader() { ID = 0; }

	/**
	 * @brief Konstruktor tworz¹cy vertex i fragment shader z plików podanych w œcie¿ce.
	 * @param vertexPath œcie¿ka do vertex shader'a
	 * @param fragmentPath œcie¿ka do fragment shader'a
	*/
	Shader(const char* vertexPath, const char* fragmentPath);

	/**
	 * @brief Dowi¹zanie shader'a, by móg³ byæ u¿ywany w programie.
	*/
	void use()
	{
		glUseProgram(ID);
	}

    /**
     * @brief Zwolnienie shader'a.
    */
    void stop()
    {
        glUseProgram(0);
    }

	/**
	 * @brief Ustawia uniform typu bool o podanej nazwie
	 * @param name nazwa uniformu
	 * @param value wartoœæ
	*/
	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}

    /**
     * @brief Ustawia uniform typu int o podanej nazwie
     * @param name nazwa uniformu
     * @param value wartoœæ
    */
	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

    /**
     * @brief Ustawia uniform typu float o podanej nazwie
     * @param name nazwa uniformu
     * @param value wartoœæ
    */
	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

    /**
     * @brief Ustawia uniform typu vec2 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param value wartoœæ
    */
    void setVec2(const std::string& name, const glm::vec2& value) const
    {
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    /**
     * @brief Ustawia uniform typu vec2 o podanej nazwie
     * @param name nazwa uniformu
     * @param x pierwsza wartoœæ wektora
     * @param y druga wartoœæ wektora
    */
    void setVec2(const std::string& name, float x, float y) const
    {
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
    }
    
    /**
     * @brief Ustawia uniform typu vec3 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param value wartoœæ
    */
    void setVec3(const std::string& name, const glm::vec3& value) const
    {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    /**
     * @brief Ustawia uniform typu vec3 o podanej nazwie
     * @param name nazwa uniformu
     * @param x pierwsza wartoœæ wektora
     * @param y druga wartoœæ wektora
     * @param z trzecia wartoœæ wektora
    */
    void setVec3(const std::string& name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }
    
    /**
     * @brief Ustawia uniform typu vec4 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param value wartoœæ
    */
    void setVec4(const std::string& name, const glm::vec4& value) const
    {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    /**
     * @brief Ustawia uniform typu vec4 o podanej nazwie
     * @param name nazwa uniformu
     * @param x pierwsza wartoœæ wektora
     * @param y druga wartoœæ wektora
     * @param z trzecia wartoœæ wektora
     * @param w czwarta wartoœæ wektora
    */
    void setVec4(const std::string& name, float x, float y, float z, float w) const
    {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }
    
    /**
     * @brief Ustawia uniform typu mat2 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param mat macierz
    */
    void setMat2(const std::string& name, const glm::mat2& mat) const
    {
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    
    /**
     * @brief Ustawia uniform typu mat3 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param mat macierz
    */
    void setMat3(const std::string& name, const glm::mat3& mat) const
    {
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    
    /**
     * @brief Ustawia uniform typu mat4 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param mat macierz
    */
    void setMat4(const std::string& name, const glm::mat4& mat) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }

private:
    /**
     * @brief Sprawdza czy shader zosta³ skompilowany poprawnie.
     * @param shader id shadera
     * @param type b³¹d na jakim etapie chcemy sprawdziæ b³¹d
     * PROGRAM - etap kompilacji ca³ego programu
     * VERTEX, FRAGMENT - kompilowanie poszczególnych shaderów
    */
    void checkCompileErrors(GLuint shader, std::string type);
};


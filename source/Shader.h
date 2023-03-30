#pragma once

#include "glad/glad.h"
#include "../glm/glm.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Klasa odpowiedzialna za �adowanie shader�w z plik�w o podanej �cie�ce. Jest to ta sama klasa, kt�rej u�ywali�my podczas zaj��.
*/
class Shader
{
public:
    // ID nadane wygenerowanemu shader'owi.
	unsigned ID;

    Shader() { ID = 0; }

	/**
	 * @brief Konstruktor tworz�cy vertex i fragment shader z plik�w podanych w �cie�ce.
	 * @param vertexPath �cie�ka do vertex shader'a
	 * @param fragmentPath �cie�ka do fragment shader'a
	*/
	Shader(const char* vertexPath, const char* fragmentPath);

	/**
	 * @brief Dowi�zanie shader'a, by m�g� by� u�ywany w programie.
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
	 * @param value warto��
	*/
	void setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
	}

    /**
     * @brief Ustawia uniform typu int o podanej nazwie
     * @param name nazwa uniformu
     * @param value warto��
    */
	void setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
	}

    /**
     * @brief Ustawia uniform typu float o podanej nazwie
     * @param name nazwa uniformu
     * @param value warto��
    */
	void setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
	}

    /**
     * @brief Ustawia uniform typu vec2 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param value warto��
    */
    void setVec2(const std::string& name, const glm::vec2& value) const
    {
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    /**
     * @brief Ustawia uniform typu vec2 o podanej nazwie
     * @param name nazwa uniformu
     * @param x pierwsza warto�� wektora
     * @param y druga warto�� wektora
    */
    void setVec2(const std::string& name, float x, float y) const
    {
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
    }
    
    /**
     * @brief Ustawia uniform typu vec3 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param value warto��
    */
    void setVec3(const std::string& name, const glm::vec3& value) const
    {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    /**
     * @brief Ustawia uniform typu vec3 o podanej nazwie
     * @param name nazwa uniformu
     * @param x pierwsza warto�� wektora
     * @param y druga warto�� wektora
     * @param z trzecia warto�� wektora
    */
    void setVec3(const std::string& name, float x, float y, float z) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }
    
    /**
     * @brief Ustawia uniform typu vec4 o podanej nazwie (wymagana biblioteka glm)
     * @param name nazwa uniformu
     * @param value warto��
    */
    void setVec4(const std::string& name, const glm::vec4& value) const
    {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }

    /**
     * @brief Ustawia uniform typu vec4 o podanej nazwie
     * @param name nazwa uniformu
     * @param x pierwsza warto�� wektora
     * @param y druga warto�� wektora
     * @param z trzecia warto�� wektora
     * @param w czwarta warto�� wektora
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
     * @brief Sprawdza czy shader zosta� skompilowany poprawnie.
     * @param shader id shadera
     * @param type b��d na jakim etapie chcemy sprawdzi� b��d
     * PROGRAM - etap kompilacji ca�ego programu
     * VERTEX, FRAGMENT - kompilowanie poszczeg�lnych shader�w
    */
    void checkCompileErrors(GLuint shader, std::string type);
};


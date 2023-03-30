#pragma once

/**
 * @brief Klasa abstrakcyjn¹, która s³u¿y za bazê do tworzenia ekranów gry.
*/
class Screen
{
public:
	
	/**
	 * @brief Aktualizowanie logiki gry.
	*/
	void virtual update() = 0;

	/**
	 * @brief Renderowanie tego co ma byæ na ekranie.
	*/
	void virtual render() = 0;
};
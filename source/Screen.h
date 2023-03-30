#pragma once

/**
 * @brief Klasa abstrakcyjn�, kt�ra s�u�y za baz� do tworzenia ekran�w gry.
*/
class Screen
{
public:
	
	/**
	 * @brief Aktualizowanie logiki gry.
	*/
	void virtual update() = 0;

	/**
	 * @brief Renderowanie tego co ma by� na ekranie.
	*/
	void virtual render() = 0;
};
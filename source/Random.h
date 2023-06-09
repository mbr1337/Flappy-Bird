#pragma once
#include <ctime>
#include <cstdlib>


class Random
{
public:
	/**
	 * @brief Zainicjalizowanie generatora liczb pseudolosowych.
	*/
	static void initialize() { srand(time(0)); }

	/**
	 * @brief Generuje liczbę pseudolosową z podanego przedziało <from, to).
	 * @param from początek przedziału
	 * @param to koniec przedziału
	 * @return wygenerowana liczba
	*/
	static float generate(float from, float to) { return from + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (to - from))); }
};

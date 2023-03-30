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
	 * @brief Generuje liczb� pseudolosow� z podanego przedzia�o <from, to).
	 * @param from pocz�tek przedzia�u
	 * @param to koniec przedzia�u
	 * @return wygenerowana liczba
	*/
	static float generate(float from, float to) { return from + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (to - from))); }
};

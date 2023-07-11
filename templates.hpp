#pragma once
#include "declaration.hpp"

/**
* @brief Szablon aktualizuj�cy �redni� przy dodawaniu nowego profesora
* @param a Pierwsza warto��
* @param b Druga warto��
*/

template <class T, class U>
T newAverage(T a, U b) {
	return (a + b)/2;
}

/**
* @brief Szablon losuj�cy losow� warto��
* @param low Najmniejsza warto��
* @param high Najwi�ksza warto��
*/

template <class X>
X rand_int(X low, X high) {
	static std::default_random_engine re{ std::random_device{}() };
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}
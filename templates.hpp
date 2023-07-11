#pragma once
#include "declaration.hpp"

/**
* @brief Szablon aktualizuj¹cy œredni¹ przy dodawaniu nowego profesora
* @param a Pierwsza wartoœæ
* @param b Druga wartoœæ
*/

template <class T, class U>
T newAverage(T a, U b) {
	return (a + b)/2;
}

/**
* @brief Szablon losuj¹cy losow¹ wartoœæ
* @param low Najmniejsza wartoœæ
* @param high Najwiêksza wartoœæ
*/

template <class X>
X rand_int(X low, X high) {
	static std::default_random_engine re{ std::random_device{}() };
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(re, Dist::param_type{ low,high });
}
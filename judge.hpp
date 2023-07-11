#pragma once
#include "professors.hpp"

/**
* @brief Klasa abstrakcyjna s�u��ca za baz� polimorfizmu
* 
*/

class judge {
public:
	/**
	* @brief Domy�lny konstruktor klasy judge
	*/
	judge() {}
	/**
	* @brief Domy�lny destruktor klasy judge
	*/
	~judge() {}
	/**
	* @brief Metoda czysto wirtualna s�u��ca do przyznawania punkt�w Hirscha profesorom
	* Funkcja zwraca obiekt klasy profesora.
	* @param name Imie profesora
	* @param surname Nazwisko profesora
	* @param publications Liczba publikacji
	* @param ministerials Liczba punkt�w ministerialnych
	* @return professor
	*/
	virtual professor setScore(const std::string& name, const std::string& surname, int publications, int ministerials) = 0;
};

class hirshJudge : public judge {
public:
	/**
	* @brief Domy�lny konstruktor klasy hirschJudge
	*/
	hirshJudge() {}
	/**
	* @brief Domy�lny destruktor klasy hirschJudge
	*/
	~hirshJudge() {}
	/**
	* @brief Metoda typu inline s�u��ca do przyznawania punkt�w Hirscha profesorom
	* Funkcja zwraca obiekt klasy profesora.
	* @param name Imi� profesora
	* @param surname Nazwisko profesora
	* @param publications Liczba publikacji
	* @param ministerials Liczba punkt�w ministerialnych
	* @return professor
	*/
	inline professor setScore(const std::string& name, const std::string& surname, int publications, int ministerials);
};

class exampleJudge : public judge {
public:
	/**
	* @brief Domy�lny konstruktor klasy exampleJudge
	*/
	exampleJudge() {}
	/**
	* @brief Domy�lny destruktor klasy exampleJudge
	*/
	~exampleJudge() {}
	/**
	* @brief Metoda typu inline s�u��ca do przyznawania punkt�w Hirscha profesorom
	* Funkcja zwraca obiekt klasy profesora.
	* @param name Imi� profesora
	* @param surname Nazwisko profesora
	* @param publications Liczba publikacji
	* @param ministerials Liczba punkt�w ministerialnych
	* @return professor
	*/
	inline professor setScore(const std::string& name, const std::string& surname, int publications, int ministerials);
};

professor hirshJudge::setScore(const std::string& name, const std::string& surname, int publications, int ministerials) {
	int Hirsh = (publications / ministerials) % 10;
	return professor(name, surname, publications, ministerials, Hirsh);
}

professor exampleJudge::setScore(const std::string& name, const std::string& surname, int publications, int ministerials) {
	int Hirsh = rand_int(0, 10);
	return professor(name, surname, publications, ministerials, Hirsh);
}
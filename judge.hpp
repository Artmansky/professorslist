#pragma once
#include "professors.hpp"

/**
* @brief Klasa abstrakcyjna s³u¿¹ca za bazê polimorfizmu
* 
*/

class judge {
public:
	/**
	* @brief Domyœlny konstruktor klasy judge
	*/
	judge() {}
	/**
	* @brief Domyœlny destruktor klasy judge
	*/
	~judge() {}
	/**
	* @brief Metoda czysto wirtualna s³u¿¹ca do przyznawania punktów Hirscha profesorom
	* Funkcja zwraca obiekt klasy profesora.
	* @param name Imie profesora
	* @param surname Nazwisko profesora
	* @param publications Liczba publikacji
	* @param ministerials Liczba punktów ministerialnych
	* @return professor
	*/
	virtual professor setScore(const std::string& name, const std::string& surname, int publications, int ministerials) = 0;
};

class hirshJudge : public judge {
public:
	/**
	* @brief Domyœlny konstruktor klasy hirschJudge
	*/
	hirshJudge() {}
	/**
	* @brief Domyœlny destruktor klasy hirschJudge
	*/
	~hirshJudge() {}
	/**
	* @brief Metoda typu inline s³u¿¹ca do przyznawania punktów Hirscha profesorom
	* Funkcja zwraca obiekt klasy profesora.
	* @param name Imiê profesora
	* @param surname Nazwisko profesora
	* @param publications Liczba publikacji
	* @param ministerials Liczba punktów ministerialnych
	* @return professor
	*/
	inline professor setScore(const std::string& name, const std::string& surname, int publications, int ministerials);
};

class exampleJudge : public judge {
public:
	/**
	* @brief Domyœlny konstruktor klasy exampleJudge
	*/
	exampleJudge() {}
	/**
	* @brief Domyœlny destruktor klasy exampleJudge
	*/
	~exampleJudge() {}
	/**
	* @brief Metoda typu inline s³u¿¹ca do przyznawania punktów Hirscha profesorom
	* Funkcja zwraca obiekt klasy profesora.
	* @param name Imiê profesora
	* @param surname Nazwisko profesora
	* @param publications Liczba publikacji
	* @param ministerials Liczba punktów ministerialnych
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
#pragma once
#include "templates.hpp"

/**
* @brief Klasa profesora
* Klasa zawiera dane profesora takie jak: Imie i nazwisko, publikacje, punkty ministerialne i punkty Hirsha.
* Zawiera równie¿ funkcje, które maj¹ na celu ustawianie tych zmiennych lub zwracanie ich.
*/

class professor {
private:
	std::pair<std::string, std::string> name;
	int publications, ministerials, Hirsch;
public:
	/**
	* @brief Konstruktor profesora
	* Przyjmuje i ustawia wszystkie wartoœci prywatne klasy profesora.
	* @param name Imie profesora
	* @param surname Nazwisko profesora
	* @param publications Publikacje profesora
	* @param ministerials Punkty ministerialne profesora
	* @param Hirsch Punkty rankingu Hirsch
	*/
	professor(const std::string& name, const std::string& surname, int publications, int ministerials, int Hirsch) :name(name, surname), publications(publications), ministerials(ministerials), Hirsch(Hirsch) {}
	/**
	* @brief Podstawowy konstruktor kopiuj¹cy
	* Konstruktor przyjmuje inny obiekt typu professor i kopiuje jego dane do siebie
	* @param newProfessor professor przekazany do skopiowania
	* 
	* 
	*/
	professor(const professor& newProfessor) :name(newProfessor.name.first, newProfessor.name.second), publications(newProfessor.publications), ministerials(newProfessor.ministerials), Hirsch(newProfessor.Hirsch) {}
	/**
	* @brief Zwykly konstruktor klasy professor 
	* Konstruktor nie robi nic specjalnego
	*
	*
	*/
	~professor() {};
	/**
	* @brief Funkcja zwracaj¹ca imiê profesora
	* Funkcja zwraca wartoœæ z pola name. Dokladnie jego pierwsz¹ czêœæ czyli imiê
	* @return std::string
	*
	*/
	const std::string& getName() const { return name.first; }
	/**
	* @brief Funkcja zwracaj¹ca nazwisko profesora
	* Funkcja zwraca wartoœæ z pola name. Dokladnie jego drug¹ czêœæ czyli nazwisko.
	* @return std::string
	*
	*/
	const std::string& getSurname() const { return name.second; }
	/**
	* @brief Funkcja zwracaj¹ca liczbê publikacji danego profesora
	* @return int
	*
	*/
	const int& getPublications() const { return publications; }
	/**
	* @brief Funkcja zwracaj¹ca liczbê punktów ministerialnych danego profesora
	* @return int
	*
	*/
	const int& getMinisterials() const { return ministerials; }
	/**
	* @brief Funkcja zwracaj¹ca liczbê punktów Hirsch danego profesora
	* @return int
	*
	*/
	const int& getHirsch() const { return Hirsch; }
	/**
	* @brief Przeci¹¿enie operatora "<<"
	* ZaprzyjaŸnione przeci¹¿enie operatora "<<", które umo¿liwia wyœwietlenie klasy professora, a dok³adnie jego danych.
	* @param operation strumien przekazany do wypisywania
	* @param toPrint klasa przekazana przez wskaŸnik (t¹ ta funkcja wypisze)
	* @return std::ostream
	*
	*/
	friend std::ostream& operator <<(std::ostream& operation, const professor* toPrint);
};

/**
* @brief Klasa bêd¹ca list¹ profesorów
* Zawiera wektor profesorów i zestaw funkcji do operowania nim.
*/

class professorList {
public:
	std::vector<professor> profList;
	/**
	* @brief Standardowy konstruktor
	*
	*/
	professorList() {}
	/**
	* @brief Wirtualny destruktor klasy professorList
	*
	*/
	virtual ~professorList() = default;
};
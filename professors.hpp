#pragma once
#include "templates.hpp"

/**
* @brief Klasa profesora
* Klasa zawiera dane profesora takie jak: Imie i nazwisko, publikacje, punkty ministerialne i punkty Hirsha.
* Zawiera r�wnie� funkcje, kt�re maj� na celu ustawianie tych zmiennych lub zwracanie ich.
*/

class professor {
private:
	std::pair<std::string, std::string> name;
	int publications, ministerials, Hirsch;
public:
	/**
	* @brief Konstruktor profesora
	* Przyjmuje i ustawia wszystkie warto�ci prywatne klasy profesora.
	* @param name Imie profesora
	* @param surname Nazwisko profesora
	* @param publications Publikacje profesora
	* @param ministerials Punkty ministerialne profesora
	* @param Hirsch Punkty rankingu Hirsch
	*/
	professor(const std::string& name, const std::string& surname, int publications, int ministerials, int Hirsch) :name(name, surname), publications(publications), ministerials(ministerials), Hirsch(Hirsch) {}
	/**
	* @brief Podstawowy konstruktor kopiuj�cy
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
	* @brief Funkcja zwracaj�ca imi� profesora
	* Funkcja zwraca warto�� z pola name. Dokladnie jego pierwsz� cz�� czyli imi�
	* @return std::string
	*
	*/
	const std::string& getName() const { return name.first; }
	/**
	* @brief Funkcja zwracaj�ca nazwisko profesora
	* Funkcja zwraca warto�� z pola name. Dokladnie jego drug� cz�� czyli nazwisko.
	* @return std::string
	*
	*/
	const std::string& getSurname() const { return name.second; }
	/**
	* @brief Funkcja zwracaj�ca liczb� publikacji danego profesora
	* @return int
	*
	*/
	const int& getPublications() const { return publications; }
	/**
	* @brief Funkcja zwracaj�ca liczb� punkt�w ministerialnych danego profesora
	* @return int
	*
	*/
	const int& getMinisterials() const { return ministerials; }
	/**
	* @brief Funkcja zwracaj�ca liczb� punkt�w Hirsch danego profesora
	* @return int
	*
	*/
	const int& getHirsch() const { return Hirsch; }
	/**
	* @brief Przeci��enie operatora "<<"
	* Zaprzyja�nione przeci��enie operatora "<<", kt�re umo�liwia wy�wietlenie klasy professora, a dok�adnie jego danych.
	* @param operation strumien przekazany do wypisywania
	* @param toPrint klasa przekazana przez wska�nik (t� ta funkcja wypisze)
	* @return std::ostream
	*
	*/
	friend std::ostream& operator <<(std::ostream& operation, const professor* toPrint);
};

/**
* @brief Klasa b�d�ca list� profesor�w
* Zawiera wektor profesor�w i zestaw funkcji do operowania nim.
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
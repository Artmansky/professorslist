#pragma once
#include "genres.hpp"

/**
* @brief G³ówna klasa dziedzicz¹ca po professorList i genreList
* Zawiera 3 najwa¿niejsze funkcje bazy danych: Dodawanie i usuwanie profesorów oraz mo¿liwoœæ wypisania ca³ej bazy.
*/

class mainBase :public professorList, public genreList {
public:
	/**
* @brief Konstruktor domyœlny klasy mainBase
*/
	mainBase() {}
	/**
* @brief Destruktor domyœlny klasy mainBase
*/
	~mainBase() {}
	/**
* @brief Funkcja typu inline dodaj¹ca profesora do dziedziny i wektora profesorów
* Funkcja sprawdza czy dziedzina istnieje, je¿eli nie to tworzy now¹, je¿eli tak to dodaje do niej profesora.
* @param newProfessor obiekt profesora, który ma byæ dodany do danej dziedziny
* @param genreTitle nazwa dziedziny, do której ma byæ dodany profesor
*/
	inline void addProfessor(professor newProfessor, const std::string& genreTitle);
	/**
	* @brief Funkcja typu inline usuwaj¹ca profesora z bazy danych
	* Funkcja sprawdza czy osoba istnieje, je¿eli tak to usuwa tego profesora. Je¿eli dziedzina oka¿e siê pusta to równie¿ usunie t¹ dziedzinê.
	* @param name Imie usuwanego profesora
	* @param surname Nazwisko usuwanego profesora
	*/
	inline void removeProfessor(const std::string& name, const std::string& surname);
	/**
* @brief Przeci¹¿enie operatora "<<"
* ZaprzyjaŸnione przeci¹¿enie operatora "<<", które umo¿liwia wyœwietlenie klasy mainBase, a dok³adnie ca³ej bazy.
* @param operation strumien przekazany do wypisywania
* @param toPrint klasa przekazana przez wskaŸnik (t¹ ta funkcja wypisze)
* @return std::ostream
*
*/
	friend std::ostream& operator << (std::ostream& operation, const mainBase* toPrint);
};

void mainBase::addProfessor(professor newProfessor, const std::string& genreTitle) {
	professor* added = new professor(newProfessor);
	for (int i = 0; i < genList.size(); i++) {
		if (genreTitle == genList[i].getTitle()) {
			genList[i].addMember(added);
			profList.push_back(newProfessor);
			genList[i].setAverage(newAverage(genList[i].getAverage(), newProfessor.getPublications()));
			return;
		}
	}
	addWholeNew(newProfessor, profList, genList, genreTitle);
}

void mainBase::removeProfessor(const std::string& name, const std::string& surname) {
	for (int i = 0; i < genList.size(); i++) {
		if (genList[i].delMember(name, surname)) {
			std::cout << "Person deleted successfully" << std::endl;
			if (genList[i].getSize() == 0) {
				genList.erase(genList.begin() + i);
				std::cout << "Genre deleted due to no active members" << std::endl;
			}
			else genList[i].removalAverage();
		}
		else std::cout << "No person of this name is present in the base" << std::endl;
	}
}
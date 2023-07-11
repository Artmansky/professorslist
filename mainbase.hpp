#pragma once
#include "genres.hpp"

/**
* @brief G��wna klasa dziedzicz�ca po professorList i genreList
* Zawiera 3 najwa�niejsze funkcje bazy danych: Dodawanie i usuwanie profesor�w oraz mo�liwo�� wypisania ca�ej bazy.
*/

class mainBase :public professorList, public genreList {
public:
	/**
* @brief Konstruktor domy�lny klasy mainBase
*/
	mainBase() {}
	/**
* @brief Destruktor domy�lny klasy mainBase
*/
	~mainBase() {}
	/**
* @brief Funkcja typu inline dodaj�ca profesora do dziedziny i wektora profesor�w
* Funkcja sprawdza czy dziedzina istnieje, je�eli nie to tworzy now�, je�eli tak to dodaje do niej profesora.
* @param newProfessor obiekt profesora, kt�ry ma by� dodany do danej dziedziny
* @param genreTitle nazwa dziedziny, do kt�rej ma by� dodany profesor
*/
	inline void addProfessor(professor newProfessor, const std::string& genreTitle);
	/**
	* @brief Funkcja typu inline usuwaj�ca profesora z bazy danych
	* Funkcja sprawdza czy osoba istnieje, je�eli tak to usuwa tego profesora. Je�eli dziedzina oka�e si� pusta to r�wnie� usunie t� dziedzin�.
	* @param name Imie usuwanego profesora
	* @param surname Nazwisko usuwanego profesora
	*/
	inline void removeProfessor(const std::string& name, const std::string& surname);
	/**
* @brief Przeci��enie operatora "<<"
* Zaprzyja�nione przeci��enie operatora "<<", kt�re umo�liwia wy�wietlenie klasy mainBase, a dok�adnie ca�ej bazy.
* @param operation strumien przekazany do wypisywania
* @param toPrint klasa przekazana przez wska�nik (t� ta funkcja wypisze)
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
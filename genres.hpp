#pragma once
#include "judge.hpp"
/**
* @brief Klasa dziedziny
* Klasa zawiera dane dziedziny takie jak: nazwe i opis, �redni� punkt�w ministerialnych i wektor wska�nik�w na profesor�w tej dziedziny.
* Zawiera r�wnie� funkcje, kt�re maj� na celu ustawianie tych zmiennych lub zwracanie ich. Posiada r�wnie� funkcje dodaj�ce lub usuwaj�ce profesor�w z wektora.
*/
class genre {
private:
	std::string title, description;
	double average;
	std::vector<professor*> members;
public:
	/**
*@brief Podstawowy konstruktor klasy dziedziny, pobiera wymagane dane i tworzy obiekt.
* @param title Nazwa dziedziny
* @param description Kr�tki opis dziedziny (100 znak�w maksymalnie)
* Ustawia r�wnie� �redni� na 0.
*
*/
	genre(const std::string& title, const std::string& description) : title(title), description(description), average(0.0) {}
	/**
* @brief Domy�lny konstruktor klasy dziedziny
*/
	~genre();
	/**
	* @brief Metoda zwracaj�ca tytu� danej dziedziny
	* @return std::string
	*/
	const std::string& getTitle() const { return title; }
	/**
	* @brief Metoda zwracaj�ca opis danej dziedziny
	* @return std::string
	*/
	const std::string& getDescription() const { return description; }
	/**
	* @brief Metoda wektor wska�nik�w na u�ytkownik�w danej dziedziny
	* @return std::vector<professor*>
	*/
	const std::vector<professor*>& getList() const { return members; }
	/**
	* @brief Metoda zwracaj�ca �redni� punkt�w ministerialnych danej dziedziny
	* @return double
	*/
	const double& getAverage() const { return average; }
	/**
	* @brief Metoda zwracaj�ca ilo�� profesor�w danej dziedziny
	* @return int
	*/
	const int& getSize() const { return members.size(); }
	/**
	* @brief Funkcja ustawiaj�ca now� �redni� danej dziedziny
	* @param average nowa warto�� �redniej
	*/
	inline void setAverage(double average) { this->average = average; }
	/**
	* @brief Funkcja dodaj�ca nowego profesora do wektora w danej dziedzinie
	* @param newProfessor wska�nik na nowego profesora, kt�ry ma by� dodany do wektora.
	*/
	inline void addMember(professor* newProfessor) { members.push_back(newProfessor); }
	/**
	* @brief Funkcja ustawiaj�ca now� �redni� danej dziedziny
	* Zlicza punkty ministerialne i dzieli je przez liczb� profesor�w w danej dziedzinie.
	*/
	inline void removalAverage();
	/**
	* @brief Funkcja usuwaj�ca danego profesora z dziedziny
	* Sprawdza czy dany profesor istnieje w bazie, je�eli tak to usuwa go.
	* @param name Imie profesora
	* @param surname Nazwisko profesora
	* @return bool
	*/
	inline bool delMember(const std::string& name, const std::string& surname);
	/**
* @brief Przeci��enie operatora "<<"
* Zaprzyja�nione przeci��enie operatora "<<", kt�re umo�liwia wy�wietlenie klasy dziedziny, a dok�adnie jej danych i cz�onk�w.
* @param operation strumie� przekazany do wypisywania
* @param toPrint klasa przekazana do wypisania
* @return std::ostream
*
*/
	friend std::ostream& operator << (std::ostream& operation, const genre& toPrint);
};


/**
* @brief Klasa listy dziedzin
* Klasa ta zawiera wektor dziedzin i funkcj�, dodaj�c� now� dziedzin� je�eli ta wcze�niej nie istnia�a.
*/
class genreList {
public:
	std::vector<genre> genList;
	/**
	* @brief Konstruktor domy�lny klasy genreList
	*/
	genreList() {}
	/**
	* @brief Funkcja dodaj�ca ca�kowicie now� dziedzin� wraz z pierwszym profesorem w tej dziedzinie
	* @param newProfessor obiekt nowego profesora
	* @param profList lista profesor�w, do kt�rej do�o�ony b�dzie profesor
	* @param genList lista dziedzin, do kt�rej dodana zostanie nowa dziedzina
	* @param genreTitle nazwa nowej dziedziny
	*/
	inline void addWholeNew(professor newProfessor, std::vector<professor>& profList, std::vector<genre>& genList, const std::string& genreTitle);
	/**
	* @brief Destruktor domy�lny klasy genreList
	*/
	virtual ~genreList() = default;
};

bool genre::delMember(const std::string& name, const std::string& surname) {
	for (int i = 0; i < members.size(); i++) {
		if ((members[i]->getName() == name) && (members[i]->getSurname() == surname)) {
			delete members[i];
			members[i] = nullptr;
			members.erase(members.begin() + i);
			return true;
		}
	}
	return false;
}

void genreList::addWholeNew(professor newProfessor, std::vector<professor>& profList,std::vector<genre>& genList,const std::string& genreTitle) {
	professor* added = new professor(newProfessor);
	std::string newDescription;
	std::cout << "Genre (\"" << genreTitle << "\") doesn't exist. Provide it's descritpion (max 100 characters) below: " << std::endl;
	std::cin >> std::setw(100) >> newDescription;
	genList.push_back(genre(genreTitle, newDescription));
	profList.push_back(newProfessor);
	genList[genList.size() - 1].addMember(added);
	genList[genList.size() - 1].setAverage(newProfessor.getPublications());
	std::cout << "Member added!" << std::endl;
}

void genre::removalAverage() {
	int sum = 0;
	for (int i = 0; i < members.size(); i++) {
		sum = sum + members[i]->getPublications();
	}
	this->average = sum / members.size();
}
#pragma once
#include "judge.hpp"
/**
* @brief Klasa dziedziny
* Klasa zawiera dane dziedziny takie jak: nazwe i opis, œredni¹ punktów ministerialnych i wektor wskaŸników na profesorów tej dziedziny.
* Zawiera równie¿ funkcje, które maj¹ na celu ustawianie tych zmiennych lub zwracanie ich. Posiada równie¿ funkcje dodaj¹ce lub usuwaj¹ce profesorów z wektora.
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
* @param description Krótki opis dziedziny (100 znaków maksymalnie)
* Ustawia równie¿ œredni¹ na 0.
*
*/
	genre(const std::string& title, const std::string& description) : title(title), description(description), average(0.0) {}
	/**
* @brief Domyœlny konstruktor klasy dziedziny
*/
	~genre();
	/**
	* @brief Metoda zwracaj¹ca tytu³ danej dziedziny
	* @return std::string
	*/
	const std::string& getTitle() const { return title; }
	/**
	* @brief Metoda zwracaj¹ca opis danej dziedziny
	* @return std::string
	*/
	const std::string& getDescription() const { return description; }
	/**
	* @brief Metoda wektor wskaŸników na u¿ytkowników danej dziedziny
	* @return std::vector<professor*>
	*/
	const std::vector<professor*>& getList() const { return members; }
	/**
	* @brief Metoda zwracaj¹ca œredni¹ punktów ministerialnych danej dziedziny
	* @return double
	*/
	const double& getAverage() const { return average; }
	/**
	* @brief Metoda zwracaj¹ca iloœæ profesorów danej dziedziny
	* @return int
	*/
	const int& getSize() const { return members.size(); }
	/**
	* @brief Funkcja ustawiaj¹ca now¹ œredni¹ danej dziedziny
	* @param average nowa wartoœæ œredniej
	*/
	inline void setAverage(double average) { this->average = average; }
	/**
	* @brief Funkcja dodaj¹ca nowego profesora do wektora w danej dziedzinie
	* @param newProfessor wskaŸnik na nowego profesora, który ma byæ dodany do wektora.
	*/
	inline void addMember(professor* newProfessor) { members.push_back(newProfessor); }
	/**
	* @brief Funkcja ustawiaj¹ca now¹ œredni¹ danej dziedziny
	* Zlicza punkty ministerialne i dzieli je przez liczbê profesorów w danej dziedzinie.
	*/
	inline void removalAverage();
	/**
	* @brief Funkcja usuwaj¹ca danego profesora z dziedziny
	* Sprawdza czy dany profesor istnieje w bazie, je¿eli tak to usuwa go.
	* @param name Imie profesora
	* @param surname Nazwisko profesora
	* @return bool
	*/
	inline bool delMember(const std::string& name, const std::string& surname);
	/**
* @brief Przeci¹¿enie operatora "<<"
* ZaprzyjaŸnione przeci¹¿enie operatora "<<", które umo¿liwia wyœwietlenie klasy dziedziny, a dok³adnie jej danych i cz³onków.
* @param operation strumieñ przekazany do wypisywania
* @param toPrint klasa przekazana do wypisania
* @return std::ostream
*
*/
	friend std::ostream& operator << (std::ostream& operation, const genre& toPrint);
};


/**
* @brief Klasa listy dziedzin
* Klasa ta zawiera wektor dziedzin i funkcjê, dodaj¹c¹ now¹ dziedzinê je¿eli ta wczeœniej nie istnia³a.
*/
class genreList {
public:
	std::vector<genre> genList;
	/**
	* @brief Konstruktor domyœlny klasy genreList
	*/
	genreList() {}
	/**
	* @brief Funkcja dodaj¹ca ca³kowicie now¹ dziedzinê wraz z pierwszym profesorem w tej dziedzinie
	* @param newProfessor obiekt nowego profesora
	* @param profList lista profesorów, do której do³o¿ony bêdzie profesor
	* @param genList lista dziedzin, do której dodana zostanie nowa dziedzina
	* @param genreTitle nazwa nowej dziedziny
	*/
	inline void addWholeNew(professor newProfessor, std::vector<professor>& profList, std::vector<genre>& genList, const std::string& genreTitle);
	/**
	* @brief Destruktor domyœlny klasy genreList
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
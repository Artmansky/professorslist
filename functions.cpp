#include "functions.hpp"

void menu() {
	std::cout << "Choose what would you like to do:" << std::endl;
	std::cout << "1. Add new member" << std::endl;
	std::cout << "2. Remove member" << std::endl;
	std::cout << "3. Print the database" << std::endl;
	std::cout << "5. Quit" << std::endl;
}

professor askfor() {
	int random = rand_int(0, 1);
	judge* spec;
	if (random == 1) spec = new hirshJudge();
	else spec = new exampleJudge();
	std::string name, surname;
	int ministerials, publications;
	std::cout << "Please type below:" << std::endl;
	std::cout << "Name:" << std::endl;
	std::cin >> name;
	std::cout << "Surname:" << std::endl;
	std::cin >> surname;
	std::cout << "Ministerial points of " << name << " " << surname << std::endl;
	std::cin >> ministerials;
	std::cout << "Number of publications of " << name << " " << surname << std::endl;
	std::cin >> publications;
	professor temp = spec->setScore(name, surname, publications, ministerials);
	delete spec;
	return temp;
}

bool mainProgram() {
	std::cout << "Welcome" << std::endl;
	mainBase* main = new mainBase();
	std::string genreName, name, surname;
	int option = 0;
	while (option != 5) {
		menu();
		std::cin >> option;
		switch (option) {
		case 1:
			std::cout << "What genre is this professor representing?" << std::endl;
			std::cin >> genreName;
			main->addProfessor(askfor(), genreName);
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			system("cls");
			break;
		case 2:
			std::cout << "Who do you want to remove from the list?" << std::endl;
			std::cout << "Name:" << std::endl;
			std::cin >> name >> surname;
			main->removeProfessor(name,surname);
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			system("cls");
			break;
		case 3:
			std::cout << main << std::endl;
			break;
		case 5:
			break;
		default:
			std::cout << "Wrong choice" << std::endl;
			break;
		}
	}
	std::cout << "Goodbye" << std::endl;
	return true;
}
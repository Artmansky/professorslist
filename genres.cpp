#include "genres.hpp"

genre::~genre() {
	for (int i = 0; i < members.size(); i++) {
		delete members[i];
		members[i] = nullptr;
	}
}

std::ostream& operator << (std::ostream& operation, const genre& toPrint) {
	operation << "Genre: " << toPrint.getTitle() << std::endl;
	operation << "Description: " << toPrint.getDescription() << std::endl;
	operation << "Average publications: " << toPrint.getAverage() << std::endl;
	operation << "Members list:" << std::endl;
	operation << "Name" << " | " << "Surname" << " | " << "Publications" << " | " << "Ministerials" << " | " << "Hirsch" << std::endl;
	for (int i = 0; i < toPrint.members.size(); i++) {
		operation << toPrint.members[i] << std::endl;
	}
	return operation;
}
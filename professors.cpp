#include "professors.hpp"

std::ostream& operator <<(std::ostream& operation, const professor* toPrint) {
	operation << toPrint->getName() << " " << toPrint->getSurname() << " " << toPrint->getPublications() << " " << toPrint->getMinisterials() << " " << toPrint->getHirsch();
	return operation;
}
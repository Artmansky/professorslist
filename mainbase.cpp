#include "mainbase.hpp"

std::ostream& operator << (std::ostream& operation, const mainBase* toPrint) {
	for (int i = 0; i < toPrint->genList.size(); i++) {
		operation << toPrint->genList[i] << std::endl;
	}
	return operation;
}
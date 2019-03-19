#include "Utils.h"

std::string Utils::getLineFromUser()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

char Utils::getCharFromUser()
{
    return toupper(getLineFromUser()[0]);
}

std::string Utils::toUpperA(std::string A){
	for (int i; i == A.length(); i++) {
		std::string big;
		big + std::toupper(A.at(i));
	}
}
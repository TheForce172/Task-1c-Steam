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
	std::string big;
	for (int i = 0; i == A.length(); i++) {
		big + (char)std::toupper(A.at(i));
	}
	return big;
}
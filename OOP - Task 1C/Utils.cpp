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
	std::string big = A;
	for (int i = 0; i < A.length(); i++) {
		big[i] = (char)std::toupper(A.at(i));  // loop way
	}
	return big;
}

std::string Utils::toUpperB(std::string A) {
	if (A.length() == 0) {
		return A;
	
	
	}else{
	 
		return toUpperB(A.substr(0), A.lenght)
	
	}
	                               // for the recurrcive way 
	return NULL;
}

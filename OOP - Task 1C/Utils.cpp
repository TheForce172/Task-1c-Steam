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
	}
	else {
		return static_cast<char>(toupper(A[0])) + toUpperB(A.substr(1));
	}
}	
	                      // for the recurrcive way

int Utils::ramdonNum(){

		int lowest = 1, highest = 60;
		int range = (highest - lowest) + 1;

		int randNum = lowest + rand() % range;
		 
		return randNum;

}

bool Utils::StartsWith(std::string fullText, std::string searchText)
{
	return toUpperA(searchText) == toUpperA(fullText.substr(0, searchText.length()));
}

std::string Utils::decimalLength(double num, int places)
{
	std::ostringstream out;
	out << std::setprecision(places) << num;
	std::string o;
	o = out.str();
	return o;
}


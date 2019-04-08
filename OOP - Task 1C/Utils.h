#pragma once

#include <string>
#include <iostream>
#include <cctype>
#include <iomanip>
#include <sstream>

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
	static std::string toUpperA(std::string); // for loop
	static std::string toUpperB(std::string); // recurrsive way 
	static int ramdonNum();
	static bool StartsWith(std::string fullText, std::string searchText);
	static std::string decimalLength(double num, int places);
};


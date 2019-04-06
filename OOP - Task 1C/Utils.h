#pragma once

#include <string>
#include <iostream>
#include <cctype>

class Utils
{
  public:
    static std::string getLineFromUser();
    static char getCharFromUser();
	static std::string toUpperA(std::string); // for loop
	static std::string toUpperB(std::string); // recurrsive way 

};


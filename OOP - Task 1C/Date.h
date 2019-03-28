#pragma once

#include <ctime>	// for date functions

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Date {
public:
	Date();	                
	Date(int, int, int);	

	int getDay() const;		
	int getMonth() const;		
	int getYear() const;		

	void setDate(int, int, int);	
	void setCurrentDate();    

	bool operator==(const Date&) const;  	

	ostream& putDataInStream(ostream&) const;	
	istream& getDataFromStream(istream&);	
private:
	int day_, month_, year_;
};

ostream& operator<<(ostream&, const Date&);	
istream& operator>>(istream&, Date&);	


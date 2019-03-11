#pragma once

class Date
{
private:
	int month, day, year;
public:
	Date();
	Date(int, int, int);

	~Date() {}

	int getDay();
	int getMonth();
	int getYear();

	void setDay(int);
	void setMonth(int);
	void setYear(int);
	
};
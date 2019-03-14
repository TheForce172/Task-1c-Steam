#pragma once

class Date
{
private:
	int month, day, year;

public:
	Date();
	Date(int, int, int);
	~Date() {}

	static Date CurrentDate;
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void setDay(const int);
	void setMonth(const int);
	void setYear(const int);
};

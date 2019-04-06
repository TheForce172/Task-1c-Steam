#include "Date.h"  

Date::Date() {		
	setCurrentDate();
}

Date::Date(int d, int m, int y) 	
	: day_(d), month_(m), year_(y)
{}

int Date::getDay() const {
	return day_;
}

int Date::getMonth() const {
	return month_;
}

int Date::getYear() const {
	return year_;
}

void Date::setDate(int d, int m, int y) {
	day_ = d;
	month_ = m;
	year_ = y;
}
void Date::setCurrentDate() {  	
	time_t now(time(0));
	struct tm t;
	localtime_s(&t, &now);
	day_ = t.tm_mday;
	month_ = t.tm_mon + 1;
	year_ = t.tm_year + 1900;
}

bool Date::operator==(const Date& d) const { 
	return
		(day_ == d.day_) &&
		(month_ == d.month_) &&
		(year_ == d.year_);
}

void Date::operator=(const string string)
{
	year_ = stoi(string.substr(0, 4));
	month_ = stoi(string.substr(5, 6));
	day_ = stoi(string.substr(8, 9));

}

ostream& Date::putDataInStream(ostream& os) const {
	os << setfill('0');
	os << setw(4) << year_ << "-";
	os << setw(2) << month_ << "-";
	os << setw(2) << day_;
	os << setw(4) << year_;
	os << setfill(' ');
	return os;
}

istream& Date::getDataFromStream(istream& is) {
	char ch;			
	is >> day_ >> ch >> month_ >> ch >> year_;
	return is;
}

ostream& operator<<(ostream& os, const Date& aDate) {
	return aDate.putDataInStream(os);
}

istream& operator>>(istream& is, Date& aDate) {
	return aDate.getDataFromStream(is);
}

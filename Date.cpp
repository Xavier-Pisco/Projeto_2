#pragma warning(disable : 4996)
#include "Date.h"
#include <ctime>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Date::Date()
{
	time_t t = time(0);
	tm* ltm = localtime(&t);
	this->year = 1900 + ltm->tm_year;
	this->month = 1 + ltm->tm_mon;
	this->day = ltm->tm_mday;
}

Date::Date(string date) {

	year = stoi(date.substr(0, date.find_first_of('/')));
	date.erase(0, date.find_first_of('/') + 1);
	month = stoi(date.substr(0, date.find_first_of('/')));
	date.erase(0, date.find_first_of('/') + 1);
	day = stoi(date);
}


Date::Date(unsigned short day, unsigned short month, unsigned year) {

	this->year = year;
	this->month = month;
	this->day = day;
}

/*********************************
 * GET Methods
 ********************************/
unsigned short Date::getDay() const {

	return day;

}

unsigned short Date::getMonth() const {

	return month;

}

unsigned Date::getYear() const {

	return year;

}

string Date::getContent() const
{
	return (to_string(day) + '/' + to_string(month) + '/' + to_string(year));
}


/*********************************
 * SET Methods
 ********************************/

void Date::setDay(unsigned short day) {

	this->day = day;

}

void Date::setMonth(unsigned short month) {

	this->month = month;

}

void Date::setYear(unsigned year) {

	this->year = year;

}



void Date::show() const
{
	cout << year << '/' << setfill('0') << setw(2) << month << '/' << setfill('0') << setw(2) << day << endl;
};

bool Date::isValid() const
{
	if (year % 4 == 0)
	{
		if (month == 2)
		{
			if (day < 29 && day > 0)
				return true;
		}
		else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 31 && day > 0)
			{
				return true;
			}
		}
		else
		{
			if (day <= 30 && day > 0)
				return true;
		}
	}
	else
	{
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		{
			if (day <= 31 && day > 0)
			{
				return true;
			}
		}
		else if (month != 2)
		{
			if (day <= 30 && day > 0)
				return true;
		}
		else
		{
			if (day <= 28 && day > 0)
				return true;
		}
	}
	return false;
};

bool Date::isEqualTo(const Date & date) const
{
	if (this->year == date.getYear() and this->month == date.getMonth() and this->day == date.getDay())
		return true;

	return false;
};

bool Date::isNotEqualTo(const Date & date) const
{
	if (this->year == date.getYear() and this->month == date.getMonth() and this->day == date.getDay())
		return false;

	return true;
}

bool Date::isAfter(const Date & date) const
{
	if (this->year < date.getYear())
		return false;

	if (this->year == date.getYear())
	{
		if (this->month < date.getMonth())
			return false;

		if (this->month == date.getMonth())
		{
			if (this->day < date.getDay())
				return false;

			if (this->day == date.getDay())
				return false;
		}
	}


	return true;
}

bool Date::isBefore(const Date & date) const
{
	if (this->year > date.getYear())
		return false;

	if (this->year == date.getYear())
	{
		if (this->month > date.getMonth())
			return false;

		if (this->month == date.getMonth())
		{
			if (this->day > date.getDay())
				return false;

			if (this->day == date.getDay())
				return false;
		}
	}


	return true;
};


//// disply a Date in a nice format
//ostream& operator<<(ostream & out, const Date & date) {
//
//	// REQUIRES IMPLEMENTATION
//
//}
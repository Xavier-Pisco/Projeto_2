#pragma once

#include "defs.h"

using namespace std;

class Date {
private:
	unsigned short day;
	unsigned short month;
	unsigned year;

public:
	Date();
	Date(string date);
	Date(unsigned short day, unsigned short month, unsigned year);

	// GET methods
	unsigned short getDay() const;
	unsigned short getMonth() const;
	unsigned getYear() const;
	string getContent() const;

	// SET methods

	void setDay(unsigned short day);
	void setMonth(unsigned short month);
	void setYear(unsigned year);

	// outhet methods */
	void show() const;
	bool isValid() const; //checks if date is valid
	bool isEqualTo(const Date& date) const; //checks if 2 dates are equal
	bool isNotEqualTo(const Date& date) const; //checks if 2 dates are not equal
	bool isAfter(const Date& date) const; //checks if a date is after another
	bool isBefore(const Date& date) const; //checks if a date is before another
	//friend ostream& operator<<(ostream& out, const Date& date);

};

bool(checkIfDateIsPossible(string date));
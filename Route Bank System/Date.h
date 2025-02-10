#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

class Date {
	// Attributes:
	int day;
	int month;
	int year;

public:
	// Cons:
	Date() {
		day = month = year = 0;
	}
	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	// Setters:
	void setDay(int day) {
		this->day = day;
	}
	void setMonth(int month) {
		this->month = month;
	}
	void setYear(int year) {
		this->year = year;
	}
	void setDate(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	// Getters:
	int getDay() {
		return this->day;
	}
	int getMonth() {
		return this->month;
	}
	int getYear() {
		return this->year;
	}
	string getDate() {
		return to_string(day) + " / " + to_string(month) + " / " + to_string(year);
	}

	// Methods:
	void printDate() {
		cout << day << " / " << month << " / " << year << endl;
	}

	// Des:
	~Date() {

	}
};

#endif // DATE_H

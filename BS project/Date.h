#pragma once
#include <iostream>
#include <string>
using namespace std;

class Date
{
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
	string getDateDot() {
		return to_string(day) + "." + to_string(month) + "." + to_string(year);
	}

	// Methods:
	void printDate() {
		cout << day << " / " << month << " / " << year << endl;
	}

	// Des:
	~Date() {

	}
};

#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define blue "\033[34m"
#define black "\033[30m"
#define yellowBack "\033[43m"
#define resetColor "\033[39m"
#define resetBack "\033[49m"
#define headColor "\033[43m\033[4m\033[30m"
#define resetHead "\033[49m\033[24m\033[39m"
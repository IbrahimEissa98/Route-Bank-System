#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <exception>
#include "functions.h"
#include "Date.h"
using namespace std;

class Person
{
protected:
	// Attributes :
	static double dollar;
	int id, age;
	string name, password;
	Date dob; // date of birth

public:
	// Constructors:
	Person() {
		this->id = 0;
		this->age = 0;
	}
	Person(int id, string name, string password, Date dob) {
		this->id = id;
		this->age = 2025 - dob.getYear();   // validate above 18
		this->name = name;
		this->password = password;
		this->dob = dob;
	}

	// Setters:
	void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setPassword(string password) {
		this->password = password;
	}
	void setDateOfBirth(Date dob) {
		this->dob = dob;
	}

	// Getters :
	int getId() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getPassword() {
		return this->password;
	}
	Date getDateOfBirth() {
		return this->dob;
	}
	int getAge() {
		return this->age;
	}

	// Methods:
	virtual void displayInfo() = 0;

	// Destructor:
	~Person() {

	}
};


#endif // PERSON_H

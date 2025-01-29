#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <exception>
#include "functions.h"
using namespace std;

class Person {
protected:
	// Attributes :
	static double dollar;
	int id;
	string name, password;

public:
	// Constructors:
	Person() {
		this->id = 0;
	}
	Person(int id, string name, string password) {
		this->id = id;
		this->name = name;
		this->password = password;
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

	// Methods:
	virtual void displayInfo() = 0;

	// Destructor:
	~Person() {

	}
};


#endif // PERSON_H

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <exception>
#include "Functions.h"
#include "Date.h"
#include "Validation.h"
using namespace std;

class Person {
protected:
	// Attributes :
	static double dollar;
	static int staticBankId;
	int bankId, age;
	string name, password, nationalID, gender;
	Date dob;		// dop -> date of birth

public:
	// Constructors:
	Person() {
		this->bankId = ++staticBankId;
		this->age = 0;
	}
	Person(string nationalID, string name, string password, string gender) {
		this->bankId = ++staticBankId;
		this->nationalID = nationalID;
		this->dob = getBirthDateFromId();
		this->age = 2025 - dob.getYear();   // validate above 18
		this->name = name;
		this->password = password;
		this->gender = gender;
	}

	// Setters:
	void setNationalID(string nationalID) {
		if (!(Validation::nationalId(nationalID))) {
			//throw exception("Invalid National ID !!");
		}
		this->nationalID = nationalID;
	}
	void setName(string name) {
		if (!(Validation::name(name))) {
			//throw exception("Invalid Name !!");
		}
		this->name = name;
	}
	void setPassword(string password) {
		if (!(Validation::password(password))) {
			//throw exception("Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)");
		}
		this->password = password;
	}
	void setGender(string gender) {
		this->gender = gender;
	}

	// Getters :
	int getBankId() {
		return this->bankId;
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
	string getNationalID() {
		return this->nationalID;
	}
	string getGender() {
		return this->gender;
	}

	// Methods:
	virtual void displayInfo() = 0;

	Date getBirthDateFromId() {
		string nationalId = this->nationalID;
		string date = nationalId.substr(0, 7);
		int nDate = stoi(date);
		int arr[7]{};
		for (int i = 6; i >= 0; i--)
		{
			arr[i] = nDate % 10;
			nDate /= 10;
		}
		int day{}, month{}, year{};
		day = arr[5] * 10 + arr[6];
		month = arr[3] * 10 + arr[4];
		if (arr[0] == 2) {
			year = 1900 + arr[1] * 10 + arr[2];
		}
		else if (arr[0] == 3) {
			year = 2000 + arr[1] * 10 + arr[2];
		}
		return Date(day, month, year);
	}

	// Destructor:
	~Person() {

	}
};


#endif // PERSON_H

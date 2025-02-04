#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <exception>
#include "Functions.h"
#include "Date.h"
#include "Validation.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

class Person {
protected:
	// Attributes :
	static double dollar;
	static int staticBankId;
	int bankId, age;
	string name, password, nationalID, gender, phone, email;
	Date dob;		// dop -> date of birth

	int calculateAge() {
		int birthYear = dob.getYear();
		if (birthYear < 18) {
			//throw exception("Unable to create account, you are under 18!");
		}
		// to get current year
		auto now = system_clock::now();
		time_t now_c = system_clock::to_time_t(now);
		tm now_tm;
		localtime_s(&now_tm, &now_c);
		int currentYear = 1900 + now_tm.tm_year;
		return
			(currentYear - birthYear);
	}

public:
	// Constructors:
	Person() {
		this->bankId = ++staticBankId;
		this->age = 0;
	}
	Person(string nationalID, string name, string password,
		string gender, string phone, string email) {
		this->bankId = ++staticBankId;
		this->nationalID = nationalID;
		this->dob = getBirthDateFromId();
		this->age = calculateAge();   // validate above 18
		this->name = name;
		this->password = password;
		this->gender = gender;
		this->phone = phone;
		this->email = email;
	}
	Person(string nationalID, string name, string password,
		string gender, string phone) {
		this->bankId = ++staticBankId;
		this->nationalID = nationalID;
		this->dob = getBirthDateFromId();
		this->age = calculateAge();   // validate above 18
		this->name = name;
		this->password = password;
		this->gender = gender;
		this->phone = phone;
	}

	// Setters:
	void setNationalID(string nationalID) {
		if (!(Validation::nationalId(nationalID))) {
			//throw exception("Invalid National ID !!");
		}else
			this->nationalID = nationalID;
	}
	void setName(string name) {
		if (!(Validation::name(name))) {
			//throw exception("Invalid Name !!");
		}else
			this->name = name;
	}
	void setPassword(string password) {
		if (!(Validation::password(password))) {
			//throw exception("Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)");
		}else
			this->password = password;
	}
	void setGender(string gender) {
			this->gender = gender;
	}
	void setPhone(string phone) {
		if (!(Validation::phone(phone))) {
			//throw exception("Invalid Phone number !!");
		}
		else
			this->phone = phone;
	}
	void setEmail(string email) {
		if (!(Validation::email(email))) {
			//throw exception("Invalid Email !!");
		}
		else
			this->email = email;
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
	string getphone() {
		return this->phone;
	}
	string getEmail() {
		return this->email;
	}

	// Methods:
	virtual void displayInfo() = 0;

	Date getBirthDateFromId() {
		if (!Validation::nationalId(this->nationalID)) {
			//throw exception("Invalid National ID !");
		}
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

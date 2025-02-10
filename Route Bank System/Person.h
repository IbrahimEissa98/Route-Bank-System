#ifndef PERSON_H
#define PERSON_H

#include <exception>
#include "Date.h"
#include "Validation.h"
#include <chrono>
using namespace std::chrono;

class Person {
protected:
	// Attributes :
	static double dollar;
	static int staticBankId;
	int bankId, age;
	string name, password, nationalID, gender, phone, email;
	Date dob;		// dop -> date of birth

	Date getBirthDateFromId() {
		if (!Validation::nationalId(this->nationalID)) {
			cout << "Invalid National ID !" << endl;
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

	int calculateAge() {
		int birthYear = dob.getYear();

		// to get current year
		auto now = system_clock::now();
		time_t now_c = system_clock::to_time_t(now);
		tm now_tm;
		localtime_s(&now_tm, &now_c);
		int currentYear = 1900 + now_tm.tm_year;
		int ageC = currentYear - birthYear;
		if (ageC >= 18) {
			return ageC;
		}
		else
			cout << "Unable to create account, you are under 18!" << endl;
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
		setNationalID(nationalID);
		this->dob = getBirthDateFromId();
		this->age = calculateAge();   // validate above 18
		setName(name);
		setPassword(password);
		this->gender = gender;
		setPhone(phone);
		setEmail(email);
	}
	Person(string nationalID, string name, string password,
		string gender, string phone) {
		this->bankId = ++staticBankId;
		setNationalID(nationalID);
		this->dob = getBirthDateFromId();
		this->age = calculateAge();   // validate above 18
		setName(name);
		setPassword(password);
		this->gender = gender;
		setPhone(phone);
	}

	// Setters:
	void setNationalID(string nationalID) {
		if (Validation::nationalId(nationalID)) {
			this->nationalID = nationalID;
		}else
			cout << "Invalid National ID !!" << endl;
	}
	void setName(string name) {
		if (Validation::name(name)) {
			this->name = name;
		}else
			cout << "Invalid Name !!" << endl;
	}
	void setPassword(string password) {
		if (Validation::password(password)) {
			this->password = password;
		}else
			cout << "Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)" << endl;
	}
	void setGender(string gender) {
		this->gender = gender;
	}
	void setPhone(string phone) {
		if (Validation::phone(phone)) {
			this->phone = phone;
		}
		else
			cout << "Invalid Phone number !!" << endl;
	}
	void setEmail(string email) {
		if (Validation::email(email)) {
			this->email = email;
		}
		else
			cout << "Invalid Email !!" << endl;
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

	// Destructor:
	~Person() {

	}
};


#endif // PERSON_H

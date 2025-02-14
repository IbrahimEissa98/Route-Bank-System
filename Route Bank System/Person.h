#ifndef PERSON_H
#define PERSON_H

#include <exception>
#include "Date.h"
#include "Validation.h"
//#include "GlobalMethods.h"

class Person {
protected:
	// Attributes :
	static double dollar;
	int age;
	string name, password, nationalID, gender, phone, email;
	Date dob;		// dop -> date of birth

public:
	// Constructors:
	Person() {
		//this->bankId = ++staticBankId;
		this->age = 0;
	}
	Person(string nationalID, string name, string password,
		string gender, string phone, string email) {
		//this->bankId = ++staticBankId;
		setNationalID(nationalID);
		this->dob = Validation::getBirthDateFromId(this->nationalID);
		this->age = Validation::calculateAge(this->dob);   // validate above 18
		setName(name);
		setPassword(password);
		this->gender = gender;
		setPhone(phone);
		setEmail(email);
	}
	Person(string nationalID, string name, string password,
		string gender, string phone) {
		//this->bankId = ++staticBankId;
		setNationalID(nationalID);
		this->dob = Validation::getBirthDateFromId(this->nationalID);
		this->age = Validation::calculateAge(this->dob);   // validate above 18
		setName(name);
		setPassword(password);
		this->gender = gender;
		setPhone(phone);
	}

	// Setters:
	void setNationalID(string nationalID) {
		if (Validation::nationalId(nationalID)) {
			this->nationalID = nationalID;
		}else {
			//throw exception("Invalid National ID !!");
			cout << "Invalid National ID !!" << endl;
		}
	}
	void setName(string name) {
		if (Validation::name(name)) {
			this->name = name;
		}else {
			//throw exception("Invalid Name !!");
			cout << "Invalid Name !!" << endl;
		}
	}
	void setPassword(string password) {
		if (Validation::password(password)) {
			this->password = password;
		}else {
			//throw exception("Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)");
			cout << "Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)" << endl;
		}

	}
	void setGender(string gender) {
		this->gender = gender;
	}
	void setPhone(string phone) {
		if (Validation::phone(phone)) {
			this->phone = phone;
		}
		else {
			//throw exception("Invalid Phone number !!");
			cout << "Invalid Phone number.. !!" << endl;
		}
	}
	void setEmail(string email) {
		if (Validation::email(email)) {
			this->email = email;
		}
		else if (email.length() == 0) {
			this->email = "Not Available";
		}
		else if (email == "Not Available") {
			this->email = "Not Available";
		}
		else {
			//throw exception("Invalid Email !!");
			cout << "Invalid Email.. !!" << endl;
		}
	}

	// Getters :
	/*int getBankId() {
		return this->bankId;
	}*/
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
	string getPhone() {
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

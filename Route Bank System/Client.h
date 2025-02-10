#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"

class Client :public Person {
	// Attributes:
	static int staticAccountNumber;
	string accountNumber;
	double balance;

public:
	// Constructors:
	Client() {
		this->balance = 0;
		accountNumber = "Route" + to_string(++staticAccountNumber);
	}
	Client(string nationalID, string name, string password,
		string gender, string phone, string email, double balance)
		:Person(nationalID, name, password, gender,phone,email) {
		accountNumber = "Route" + to_string(++staticAccountNumber);
		setBalance(balance);
	}
	Client(string nationalID, string name, string password,
		string gender, string phone, double balance)
		:Person(nationalID, name, password, gender, phone) {
		accountNumber = "Route" + to_string(++staticAccountNumber);
		setBalance(balance);
	}
	Client(Client& c) {
		accountNumber = "Route" + to_string(++staticAccountNumber);
		this->bankId = c.bankId;
		this->nationalID = c.nationalID;
		this->dob = c.dob;
		this->age = c.age;
		this->name = c.name;
		this->password = c.password;
		this->gender = c.gender;
		this->balance = 0;
	}

	// Setters:
	void setBalance(double balance) {
		if (Validation::balance(balance)) {
			this->balance = balance;
		}
		else
			cout << "Invalid Start Balance !!" << endl;
	}

	// Getters:
	double getBalance() {
		return this->balance;
	}
	double getBalanceInDollar() {
		return this->balance / dollar;
	}

	// Methods:
	void deposit(double amount) {
		if (amount > 0) {
			this->balance += amount;
		}
		else {
			cout << "Invalid Amount !!" << endl;
		}
	}
	void withdraw(double amount) {
		if (amount <= balance && amount > 0) {
			this->balance -= amount;
		}
		else {
			cout << "Invalid Amount !!" << endl;
		}
	}
	void trnsferTo(double amount, Client& recipient) {
		if (amount <= balance && amount > 0) {
			this->balance -= amount;
			recipient.balance += amount;
		}
		else {
			cout << "Invalid Amount !!" << endl;
		}
	}
	void checkBalance() {
		cout << "Your balance = " << this->balance << " EGP" << endl;
	}

	// Methods:
	void displayInfo() {
		cout << endl;
		cout << "Bank ID       : " << this->bankId << endl;
		cout << "Account Number: " << this->accountNumber << endl;
		cout << "National ID   : " << this->nationalID << endl;
		cout << "Name          : " << this->name << endl;
		cout << "Date of Birth : " << this->dob.getDate() << endl;
		cout << "Age           : " << this->age << endl;
		cout << "Gender        : " << this->gender << endl;
		cout << "Phone         : " << this->phone << endl;
		cout << "Email         : " << this->email << endl;
		cout << "Balance       : " << this->balance<<" EGP" << endl;
		cout << "Balance in $  : " << getBalanceInDollar()<<" $" << endl;
		cout << "========================================" << endl;
	}

	// Destructor:
	~Client() {

	}
};

#endif // CLIENT_H

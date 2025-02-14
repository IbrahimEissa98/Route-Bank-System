#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include "GlobalMethods.h"
//#include "Functions.h"

class Client :public Person {
	// Attributes:
	static int staticAccountNumber;
	static int staticClientBankId;
	string clientBankId;
	string accountNumber;
	double balance;


public:
	// Constructors:
	Client() {
		this->balance = 0;
		accountNumber = "Route" + GlobalMethods::accountNumberYM() + to_string(staticAccountNumber++);
		this->clientBankId = "C" + to_string(staticClientBankId++);
	}
	Client(string nationalID, string name, string password,
		string gender, string phone, string email, double balance)
		:Person(nationalID, name, password, gender, phone, email) {
		this->clientBankId = "C" + to_string(staticClientBankId++);
		accountNumber = "Route" + GlobalMethods::accountNumberYM() + to_string(staticAccountNumber++);
		setBalance(balance);
	}
	Client(string nationalID, string name, string password,
		string gender, string phone, double balance)
		:Person(nationalID, name, password, gender, phone) {
		this->clientBankId = "C" +to_string(staticClientBankId++);
		accountNumber = "Route" + GlobalMethods::accountNumberYM() + to_string(staticAccountNumber++);
		setBalance(balance);
	}
	Client(string accountNumber, string bankID,
		string nationalID, string name, string password,
		string gender, string phone, string email, double balance)
		:Person(nationalID, name, password, gender, phone, email) {
		this->accountNumber = accountNumber;
		this->clientBankId = bankID;
		this->balance = balance;
	}
	/*Client(Client& c) {
		this->accountNumber =c.accountNumber;
		this->clientBankId = c.clientBankId;
		this->nationalID = c.nationalID;
		this->dob = c.dob;
		this->age = c.age;
		this->name = c.name;
		this->password = c.password;
		this->email = c.email;
		this->phone = c.phone;
		this->gender = c.gender;
		this->balance = c.balance;
	}*/
	/*void operator =(Client& c) {
		this->accountNumber = c.accountNumber;
		this->clientBankId = c.clientBankId;
		this->nationalID = c.nationalID;
		this->dob = c.dob;
		this->age = c.age;
		this->name = c.name;
		this->password = c.password;
		this->email = c.email;
		this->phone = c.phone;
		this->gender = c.gender;
		this->balance = c.balance;
	}*/


	// Setters:
	void setBalance(double balance) {
		if (Validation::balance(balance)) {
			this->balance = balance;
		}
		else {
			//throw exception("Invalid Start Balance !!");
			cout << "Invalid Start Balance !!" << endl;
		}
	}

	// Getters:
	string getBankID () {
		return this->clientBankId;
	}
	string getAccountNumber() {
		return this->accountNumber;
	}
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
			//throw exception("Invalid Amount !!");
			cout << "Invalid Amount !!" << endl;
		}
	}
	void withdraw(double amount) {
		if (amount <= balance && amount > 0) {
			this->balance -= amount;
		}
		else {
			//throw exception("Invalid Amount !!");
			cout << "Invalid Amount !!" << endl;
		}
	}
	void trnsferTo(double amount, Client& recipient) {
		if (amount <= balance && amount > 0) {
			withdraw(amount);
			deposit(amount);
		}
		else {
			//throw exception("Invalid Amount !!");
			cout << "Invalid Amount !!" << endl;
		}
	}
	void checkBalance() {
		cout << "Your balance = " << this->balance << " EGP" << endl;
	}

	// Methods:
	void displayInfo() {
		cout << endl;
		cout << "Bank ID       : " << this->clientBankId << endl;
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

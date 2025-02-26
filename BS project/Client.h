#pragma once
#include "Person.h"
#include "AccountActivity.h"

class Client : public Person
{
// Attributes:
	static int staticAccountNumber;
	static int staticClientBankId;
	string clientBankId;
	string accountNumber;
	double balance;
	AccountActivity transactions;


public:
	// Constructors:
	Client() {
		this->balance = 0;
	}
	Client(string nationalID, string name, string password,
		string gender, string phone, string email, double balance)
		:Person(nationalID, name, password, gender, phone, email) {
		this->clientBankId = "C" + to_string(staticClientBankId++);
		this->accountNumber = "Route" + accountNumberYM() + to_string(staticAccountNumber++);
		setBalance(balance);
		this->transactions.setId(nationalID);
	}
	Client(string nationalID, string name, string password,
		string gender, string phone, double balance)
		:Person(nationalID, name, password, gender, phone) {
		this->clientBankId = "C" +to_string(staticClientBankId++);
		this->accountNumber = "Route" + accountNumberYM() + to_string(staticAccountNumber++);
		setBalance(balance);
		this->transactions.setId(nationalID);
	}
	Client(string accountNumber, string bankID,
		string nationalID, string name, string password,
		string gender, string phone, string email, double balance)
		:Person(nationalID, name, password, gender, phone, email) {
		this->accountNumber = accountNumber;
		this->clientBankId = bankID;
		this->balance = balance;
		this->transactions.setId(nationalID);
	}

	// Setters:
	void setAccountNumber(string accNum={}) {
		if (accNum.size() == 0) {
			this->accountNumber = accNum;
		}
		else {
			this->accountNumber = "Route" + accountNumberYM() + to_string(staticAccountNumber++);
		}
	}
	void setBankId(string bankId = {}) {
		if (bankId.size() == 0) {
			this->clientBankId = bankId;
		}
		else {
			this->clientBankId = "C" + to_string(staticClientBankId++);
		}
	}
	void setBalance(double balance) {
		if (Validation::balance(balance)) {
			this->balance = balance;
		}
		else {
			cout << red << "Invalid Start Balance...!" << resetColor << endl;
		}
	}
	void setTransactions(AccountActivity trans) {
		this->transactions = trans;
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
	AccountActivity getTransactions() {
		return this->transactions;
	}

	// Methods:
	void deposit(double amount) {
		if (amount > 0) {
			this->balance += amount;
			cout << green << "\nThe amount has been deposited successfully...\n" << resetColor << endl;
			
			transactions.addTransaction("Deposit", amount);
		}
		else {
			cout << red << "\nInvalid Amount !!\n" << resetColor << endl;
		}
	}
	void withdraw(double amount) {
		if (amount <= balance && amount > 0) {
			this->balance -= amount;
			cout << green << "\nThe amount has been withdrawed successfully...\n" << resetColor << endl;
			
			transactions.addTransaction("Withdraw", amount);
		}
		else {
			cout << red << "Invalid Amount !!" << resetColor << endl;
		}
	}
	void trnsferTo(double amount, Client& recipient) {
		if (amount <= balance && amount > 0) {
			this->balance -= amount;
			recipient.balance += amount;
			cout << green << "\nThe amount has been sent successfully...\n" << resetColor << endl;
			cout << "Your New Balance = " << green << getBalance() << resetColor << " EGP\n\n";
			transactions.addTransaction("Transfer", amount);
			recipient.transactions.addTransaction("Receive", amount);
		}
		else {
			cout << red << "Invalid Amount !!" << resetColor << endl;
		}
	}
	void checkBalance() {
		cout << "Your balance = " << green << this->balance << resetColor << " EGP\n\n";
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

static vector<Client> AllClients;
static vector<Client>::iterator clIt;
static vector<Client>::iterator upClIt;
static vector<Client>::iterator searchClIt;

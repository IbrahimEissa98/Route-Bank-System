#pragma once

#include "Methods.h"

class AccountActivity
{
private:
	string clientId;
	vector<string> transactions;
	

public:
	AccountActivity(){}
	AccountActivity(string id,vector<string> transactions) {
		this->clientId = id;
		for (string s : transactions) {
			this->transactions.push_back(s);
		}
	}

	void setId(string id) {
		this->clientId = id;
	}
	void setTransactions(vector<string> transactions) {
		for (string s : transactions) {
			this->transactions.push_back(s);
		}
	}

	string getId() {
		return this->clientId;
	}
	vector<string> getTransactions() {
		return this->transactions;
	}

	//Methods:
	void addTransaction(string transType, double amount) {
		Date transDate = dateOfAppointmentGetter();
		string trans = transDate.getDateDot() + " " + realTime() + " " + transType + ": " + to_string(amount);
		this->transactions.push_back(trans);
	}
	void addTransaction(string trans) {
		this->transactions.push_back(trans);
	}
	void displayAllTransactions() {
		if (transactions.size() == 0) {
			cout << red << "No transactions available...!\n\n" << resetColor;
		}
		for (string s : transactions) {
			cout << s << endl;
		}
		cout << endl;
	}
};


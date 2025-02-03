#include "Functions.h"

#include <iostream>
#include <string>
#include "Validation.h"
#include "Client.h"
#include "Employee.h"
using namespace std;

void addClient() {
	cout << "Adding Client -->>\n" << endl;
	cout << "National ID :  ";
	string nationalId;
	cin >> nationalId;
	while (!(Validation::nationalId(nationalId))) {
		cout << "Invalid National ID !!" << endl;
		cout << "National ID :  ";
		cin >> nationalId;
	}

	cout << "Name :  ";
	string name;
	getline(cin >> ws, name);
	while (!(Validation::name(name))) {
		cout << "Invalid Name !!" << endl;
		cout << "Name :  ";
		getline(cin >> ws, name);
	}

	cout << "Password :  ";
	string pass;
	getline(cin >> ws, pass);
	while (!(Validation::password(pass))) {
		cout << "Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)" << endl;
		cout << "Password :  ";
		getline(cin >> ws, pass);
	}

	cout << "Gender :  ";
	string gender;
	int num;
	cout << "1) Male    2) Female   ";
	cin >> num;
	while (num != 1 && num != 2) {
		cout << "Invalid Gender Choice !!" << endl;
		cout << "1) Male    2) Female   ";
		cin >> num;
	}
	if (num == 1)
		gender = "Male";
	else if (num == 2)
		gender = "Female";

	cout << "Start Balance\"at least 1500 EGP\" :  ";
	int balance;
	cin >> balance;
	while (!Validation::balance(balance)) {
		cout << "Invalid Start Balance !!" << endl;
		cout << "Start Balance :  ";
		cin >> balance;
	}


	Client c(nationalId, name, pass, gender, balance);
	c.displayInfo();
}


void addEmployee() {
	cout << endl;
	cout << "Adding Employee -->>" << endl;
	cout << "National ID :  ";
	string nationalId;
	cin >> nationalId;
	while (!(Validation::nationalId(nationalId))) {
		cout << "Invalid National ID !!" << endl;
		cout << "National ID :  ";
		cin >> nationalId;
	}

	cout << "Name :  ";
	string name;
	getline(cin >> ws, name);
	while (!(Validation::name(name))) {
		cout << "Invalid Name !!" << endl;
		cout << "Name :  ";
		getline(cin >> ws, name);
	}

	cout << "Password :  ";
	string pass;
	getline(cin >> ws, pass);
	while (!(Validation::password(pass))) {
		cout << "Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)" << endl;
		cout << "Password :  ";
		getline(cin >> ws, pass);
	}

	cout << "Gender :  ";
	string gender;
	int num;
	cout << "1) Male    2) Female   ";
	cin >> num;
	while (num != 1 && num != 2) {
		cout << "Invalid Gender Choice !!" << endl;
		cout << "1) Male    2) Female   ";
		cin >> num;
	}
	if (num == 1)
		gender = "Male";
	else if (num == 2)
		gender = "Female";

	cout << "Start Balance\"at least 5000 EGP\" :  ";
	int salary;
	cin >> salary;
	while (!Validation::balance(salary)) {
		cout << "Invalid Start Balance !!" << endl;
		cout << "Start Balance :  ";
		cin >> salary;
	}


	Employee e(nationalId, name, pass, gender, salary);
	e.displayInfo();
}

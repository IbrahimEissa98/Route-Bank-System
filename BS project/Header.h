#pragma once
#include "ClientManager.h"

static void headerBankName() {
	system("cls");
	system("color 0F");
	ifstream head;
	head.open("Screens\\header bank name.txt");
	cout << "\033[1m\033[32m";
	if (head.is_open()) {
		string line;
		while (getline(head, line)) {
			cout << line << endl;
		}
		cout << "\033[39m\n\n";
	}
	head.close();
}

static void seeYouSoon() {
	system("cls");
	system("color 8E");
	ifstream seeYou;
	seeYou.open("Screens\\see you soon.txt");
	if (seeYou.is_open()) {
		string line;
		while (getline(seeYou, line)) {
			cout << line << endl;
		}
	}
	seeYou.close();
	this_thread::sleep_for(chrono::milliseconds(2000));
}

static void updatePassFunc(Person* person) {
	cout << "\nUPDATING PASSWORD ==>\n\n";
	string pass = inputPassword();
	if (person->getPassword() != pass) {
		person->setPassword(pass);
		cout << green << "\nPassword Updated successfully...\n\n" << resetColor;
	}
	else {
		cout << red << "\nUnsuccessful password updating!\n ";
		cout << "\nThe new password is the same as the old one...\n\n" << resetColor;
	}
}

static Client* loginClientFunc(string id, string password) {
	cout << headColor << "\n\nLogin as Client ==>\n\n" << resetHead;
	cout << "National ID :  ";
	cin >> id;
	cout << "\nPassword    :  ";
	cin >> password;
	for (clIt = AllClients.begin(); clIt != AllClients.end(); clIt++) {
		if (id == clIt->getNationalID() && password == clIt->getPassword()) {
			return clIt._Ptr;
		}
	}
	return nullptr;
}

static Employee* loginEmployeeFunc(string id, string password) {
	cout << headColor << "\n\nLogin as Employee ==>\n\n" << resetHead;
	cout << "National ID :  ";
	cin >> id;
	cout << "\nPassword    :  ";
	cin >> password;
	for (emIt = AllEmployes.begin(); emIt != AllEmployes.end(); emIt++) {
		if (id == emIt->getNationalID() && password == emIt->getPassword()) {
			return emIt._Ptr;
		}
	}
	return nullptr;
}

static vector<string> inputData(int n) {
	string s;
	vector<string> v;
	if (n == 1)s = "Client"; else if (n == 2)s = "Employee"; else s = "Admin";
	cout << headColor << "\nAdding " << s << " -- >> \n" << resetHead << endl;

	string id = inputID();
	if (Validation::calculateAge(Validation::getBirthDateFromId(id)) < 21) {
		return v;
	}

	if (n == 1) {
		for (searchClIt = AllClients.begin(); searchClIt != AllClients.end(); searchClIt++) {
			if (searchClIt->getNationalID() == id) {
				throw exception("\033[31m\nThis National ID is already exist...!\n\n\033[39m");
			}
		}
	}
	else if (n == 2) {
		for (searchEmIt = AllEmployes.begin(); searchEmIt != AllEmployes.end(); searchEmIt++) {
			if (searchEmIt->getNationalID() == id) {
				throw exception("\033[31m\nThis National ID is already exist...!\n\n\033[39m");
			}
		}
	}
	string name = inputName();
	string pass = inputPassword();
	string gender = inputGender();
	string phone = inputPhone();
	string email = inputEmail();

	double money;
	if (n == 1) {
		money = inputBalance();
	}
	else {
		money = inputSalary();
	}


	v = { id,name,pass,gender,phone,email,to_string(money) };
	return v;
}

static bool updateData(int n) {
	headerBankName();
	(n == 1) ? searchClIt->displayInfo() : searchEmIt->displayInfo();

	string s = (n == 1) ? "Client" : "Employee";
	string s1 = (n == 1) ? "Balance" : "Salary";
	cout << headColor << "\nUpdate " << s << " Data-- >> \n" << resetHead << endl;
	cout << "( 1 ) Update National ID\n";
	cout << "( 2 ) Update Name\n";
	cout << "( 3 ) Update Gender\n";
	cout << "( 4 ) Update Phone\n";
	cout << "( 5 ) Update Email\n";
	cout << "( 6 ) Update " << s1 << endl;
	cout << "( 0 ) Exit & Save updates\n";

	char choice{};
	cout << "\nEnter choice : ";
	cin >> choice;

	switch (choice) {
	case '1':
		(n == 1) ? searchClIt->setNationalID(inputID()) : searchEmIt->setNationalID(inputID());
		cout << green << "\n\nNational ID Updated Successfully...\n\n" << resetColor;
		system("pause");
		return true;
		break;

	case '2':
		(n == 1) ? searchClIt->setName(inputName()) : searchEmIt->setName(inputName());
		cout << green << "\n\nName Updated Successfully...\n\n" << resetColor;
		system("pause");
		return true;
		break;

	case '3':
		(n == 1) ? searchClIt->setGender(inputGender()) : searchEmIt->setGender(inputGender());
		cout << green << "\n\nGender Updated Successfully...\n\n" << resetColor;
		system("pause");
		return true;
		break;

	case '4':
		(n == 1) ? searchClIt->setPhone(inputPhone()) : searchEmIt->setPhone(inputPhone());
		cout << green << "\n\nPhone Updated Successfully...\n\n" << resetColor;
		system("pause");
		return true;
		break;

	case '5':
		(n == 1) ? searchClIt->setEmail(inputEmail()) : searchEmIt->setEmail(inputEmail());
		cout << green << "\n\nEmail Updated Successfully...\n\n" << resetColor;
		system("pause");
		return true;
		break;

	case '6':
		(n == 1) ? searchClIt->setBalance(inputBalance()) : searchEmIt->setSalary(inputSalary());
		cout << green << "\n\n" << s1 << "Updated Successfully...\n\n" << resetColor;
		system("pause");
		return true;
		break;

	case '0':
		(n == 1) ? FileManager::updateClients() : FileManager::updateEmployes();
		return false;
		break;

	default:
		cout << red << "\n\nWrong Choice...!\n\n" << resetColor;
		system("pause");
		return true;
		break;
	}
}
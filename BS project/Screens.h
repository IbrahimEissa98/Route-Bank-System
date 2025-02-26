#pragma once
#include "AdminManager.h" 

class Screens
{
private:
	static void bankName() {
		ifstream name;
		name.open("Screens\\bank name.txt");
		cout << "\033[1m\033[32m";
		if (name.is_open()) {
			string line;
			while (getline(name, line)) {
				cout << line << endl;
			}
		}
		name.close();
		this_thread::sleep_for(chrono::milliseconds(3000));
		cout << "\033[0m";
	}

	static void welcome() {
		ifstream welcomeTo;
		welcomeTo.open("Screens\\welcome.txt");
		if (welcomeTo.is_open()) {
			string line;
			while (getline(welcomeTo, line)) {
				cout << line << endl;
			}
		}
		welcomeTo.close();
		this_thread::sleep_for(chrono::milliseconds(2000));
	}

	static void welcomeScreen() {
		system("color 1F");
		welcome();
		bankName();
	}

	static void loginOptions() {
		headerBankName();
		cout << headColor << "Login AS ==>\n" << resetHead << endl;
		cout << "< 1 > Client\n" << endl;
		cout << "< 2 > Employee\n" << endl;
		cout << "< 3 > Admin\n" << endl;
	}

	static int loginAs() {
		char choice{};
		while (true) {
			loginOptions();
			
			cout << "\nEnter your choice :  ";
			cin >> choice;
			if (choice < '1' || choice > '3') {
				cout << red << "\nUnknown Choice...!\n" << resetColor << endl;
				system("pause");
			}
			else {
				break;
			}
		}
		return choice;
	}

	static void invalid(char c) {
		switch (c) {
		case '1':
			cout << red << "\nInvalid Client ID or Password...!\n" << resetColor << endl;
			system("pause");
			loginScreen(loginAs());
			break;
		case '2':
			cout << red "\nInvalid Employee ID or Password...!\n" << resetColor << endl;
			system("pause");
			loginScreen(loginAs());
			break;
		case '3':
			cout << red << "\nInvalid Admin ID or Password...!\n" << resetColor << endl;
			system("pause");
			loginScreen(loginAs());
			break;

		default:
			break;
		}
	}

	static void logout() {
		seeYouSoon();
		loginScreen(loginAs());
	}

	static void loginScreen(char c) {
		headerBankName();
		string id, pass;
		switch (c) {
		case '1':
			Client* client;
			client = ClientManager::login(id, pass);
			if (client != nullptr) {
				while (ClientManager::clientOptions(client));
				logout();
			}
			else {
				invalid('1');
			}
			break;

		case '2':
			Employee * employee;
			employee = EmployeeManager::login(id, pass);
			if (employee != nullptr) {
				while (EmployeeManager::employeeOptions(employee));
				logout();
			}
			else {
				invalid('2');
			}
			break;
		case '3':
			if (AdminManager::login(id, pass) == true) {
				while(AdminManager::AdminOptions(systemAdmin));
				logout();
			}
			else {
				invalid('3');
			}
			break;

		default:
			break;
		}
	}

public:

	static void runApp() {
		welcomeScreen();
		FileManager::getAllData();
		loginScreen(loginAs());
	}

};

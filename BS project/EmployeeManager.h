#pragma once
#include "ClientManager.h"

class EmployeeManager
{
public:
	static void printEmployeeMenu() {
		headerBankName();
		cout << headColor << "WELCOME -->    " << resetHead << blue << emIt->getName() <<
			"\033[36m\t\tTotal Clients : " << to_string(AllClients.size()) << resetColor << "\n\n";
		cout << "< 1 > Display my informations\n" << endl;
		cout << "< 2 > Change password\n" << endl;
		cout << "< 3 > Add New Client\n" << endl;
		cout << "< 4 > Search For Client\n" << endl;
		cout << "< 5 > List All Clients\n" << endl;
		cout << "< 6 > Update Client Informations\n" << endl;
		cout << "< 0 > Logout\n" << endl;
	}

	static void newClient(Employee* employee) {
		try {
			vector<string>v = inputData(1);
			if (v.size() == 7) {
				Client c (v[0], v[1], v[2], v[3], v[4], v[5], stod(v[6]));
				employee->addClient(c);
				cout << green << "\n\nClient account created successfully...\n\n" << resetColor;
				c.displayInfo();
				FileManager::updateClients();
			}
		}
		catch (exception& e) {
			cout << endl << e.what() << endl;
		}
	}

	static void listAllClients(Employee* employee) {
		cout << headColor << "\nAll Bank Clients ==>\n\n" << resetHead;
		employee->listClients();
	}

	static void searchForClient(Employee* employee) {
		cout << headColor << "\nSearch for Client ==>\n\n" << resetHead;
		string id;
		cout << "Enter National ID :  ";
		cin >> id;
		Client* client = employee->searchClient(id);
		if (client != nullptr) {
			client->displayInfo();
		}
		char c{};
		cout << "\nShow Account Activity ( 1>Yes , 0>No ) :  ";
		cin >> c;
		if (c == '1') {
			cout << endl;
			client->getTransactions().displayAllTransactions();
		}
	}

	static void editClientInfo(Employee* employee) {
		searchForClient(employee);
		if (searchClIt != AllClients.end() ) {
			while (updateData(1));
		}
	}

	static Employee* login(string id, string password) {
		return loginEmployeeFunc(id, password);
	}

	static bool employeeOptions(Employee* employee) {
		while (true) {
			printEmployeeMenu();
			char choice{};
			while (true) {
				cout << "\nEnter your choice :  ";
				cin >> choice;
				if (choice < '0' || choice > '6') {
					cout << red << "\n\nUnknown Choice...!\n\n" << resetColor << endl;
					system("pause");
					break;
				}
				else {
					break;
				}
			}

			switch (choice) {
			case '1':
				headerBankName();
				employee->displayInfo();
				system("pause");
				break;

			case '2':
				headerBankName();
				ClientManager::updatePassword(employee);
				FileManager::updateEmployes();
				system("pause");
				break;

			case '3':
				headerBankName();
				newClient(employee);
				system("pause");
				break;

			case '4': {
				headerBankName();
				searchForClient(employee);
				system("pause");
			}
				break;

			case '5': {
				headerBankName();
				listAllClients(employee);
				system("pause");
			}
				break;

			case '6': 
				headerBankName();
				editClientInfo(employee);
				system("pause");
				break;

			case '0':
				return false;

			default:
				break;
			}
		}
	}
};


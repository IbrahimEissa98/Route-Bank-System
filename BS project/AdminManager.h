#pragma once
#include "Admin.h"
#include "EmployeeManager.h"

class AdminManager
{
public:
	static void printAdminMenu() {
		headerBankName();
		cout << headColor << "WELCOME -->    " << resetHead << blue << systemAdmin->getName() <<
			"\033[36m\t\tTotal Clients : " << to_string(AllClients.size()) <<
			"\t\tTotal Employes : " << to_string(AllEmployes.size()) << resetColor << "\n\n";
		cout << "< 1 > Display my informations\n" << endl;
		cout << "< 2 > Change password\n" << endl;
		cout << "< 3 > Add New Client\n" << endl;
		cout << "< 4 > Search For Client\n" << endl;
		cout << "< 5 > List All Clients\n" << endl;
		cout << "< 6 > Update Client Informations\n" << endl;
		cout << "< 7 > Add New Employee\n" << endl;
		cout << "< 8 > Search For Employee\n" << endl;
		cout << "< 9 > List All Employes\n" << endl;
		cout << "< 10 > Update Employee Informations\n" << endl;
		cout << "< 0 > Logout\n" << endl;
	}

	static void newEmployee(Admin* admin) {
		try {
			vector<string>v = inputData(2);
			if (v.size() == 7) {
				Employee e(v[0], v[1], v[2], v[3], v[4], v[5], stod(v[6]));
				admin->addEmployee(e);
				cout << green << "\n\nEmployee account created successfully...\n\n" << resetColor;
				e.displayInfo();
				FileManager::updateEmployes();
			}
		}
		catch (exception& e) {
			cout << endl << e.what() << endl;
		}
	}

	static void listAllEmployes(Admin* admin) {
		cout << headColor << "\nAll Bank Employes ==>\n\n" << resetHead;
		admin->listEmployes();
	}

	static void searchForEmployee(Admin* admin) {
		cout << headColor << "\nSearch for Client ==>\n\n" << resetHead;
		string id;
		cout << "Enter National ID :  ";
		cin >> id;
		
		Employee* employee = admin->searchEmployee(id);
		if (employee != nullptr) {
			employee->displayInfo();
		}
	}

	static void editEmployeeInfo(Admin* admin) {
		searchForEmployee(admin);
		if (searchEmIt != AllEmployes.end()) {
			while (updateData(2));
		}
	}

	static bool login(string id, string password) {
		cout << headColor << "\n\nLogin as Admin ==>\n\n" << resetHead;
		cout << "National ID :  ";
		cin >> id;
		cout << "\nPassword    :  ";
		cin >> password;
		if (id == systemAdmin->getNationalID() && password == systemAdmin->getPassword()) {
			return true;
		}
		return false;
	}

	static bool AdminOptions(Admin* admin) {
		while (true) {
			printAdminMenu();
			int choice{};
			while (true) {
				cout << "\nEnter your choice :  ";
				cin >> choice;
				if (choice < 0 || choice > 10) {
					cout << red << "\n\nUnknown Choice...!\n" << resetColor << endl;
					system("pause");
					break;
				}
				else {
					break;
				}
			}

			switch (choice) {
			case 1:
				headerBankName();
				admin->displayInfo();
				system("pause");
				break;

			case 2:
				headerBankName();
				ClientManager::updatePassword(admin);
				admin->saveAdminToFile();
				system("pause");
				break;

			case 3:
				headerBankName();
				EmployeeManager::newClient(admin);
				system("pause");
				break;

			case 4: {
				headerBankName();
				EmployeeManager::searchForClient(admin);
				system("pause");
			}
				break;

			case 5: {
				headerBankName();
				EmployeeManager::listAllClients(admin);
				system("pause");
			}
				break;

			case 6:
				headerBankName();
				EmployeeManager::editClientInfo(admin);
				system("pause");
				break;

			case 7:
				headerBankName();
				newEmployee(admin);
				system("pause");
				break;

			case 8: {
				headerBankName();
				searchForEmployee(admin);
				system("pause");
			}
				break;

			case 9: {
				headerBankName();
				listAllEmployes(admin);
				system("pause");
			}
				break;

			case 10:
				headerBankName();
				editEmployeeInfo(admin);
				system("pause");
				break;

			case 0:
				return false;

			default:
				break;
			}
		}
	}
};


#ifndef FILESHELPER_H
#define FILESHELPER_H

//#include <iostream>
#include <fstream>
//#include "Client.h"
//#include "Admin.h"
//#include <vector>
#include "GlobalData.h"
#include "Parser.h"
//using namespace std;

class FilesHelper {
private:
	static void saveLastIds(string fileName,int id) {
		ofstream saveId;
		saveId.open(fileName);
		if (saveId.is_open()) {
			saveId << ++id;
		}
		saveId.close();
	}

	static int getLastIds(string fileName) {
		ifstream getId;
		getId.open(fileName);
		int accNum{};
		if (getId.is_open()) {
			getId >> accNum;
		}
		getId.close();
		return accNum;
	}

	static void clearFile(string fileName, string idFileName, int startId) {
		ofstream file;

		file.open(fileName, ios::out);
		file.close();

		saveLastIds(idFileName, startId);
	}

public:

	// Client Account Number
	static void saveLastAccountNumber() {
		string fileName = "dataBase\\Client\\Last Account Number.txt";
		saveLastIds(fileName, getLastIds(fileName));
	}
	static int getLastAccountNumber() {
		string fileName = "dataBase\\Client\\Last Account Number.txt";
		int id = getLastIds(fileName);
		return id;
	}

	// Client Id
	static void saveLastClientId() {
		string fileName = "dataBase\\Client\\Last Client ID.txt";
		saveLastIds(fileName, getLastIds(fileName));
	}
	static int getLastClientId() {
		string fileName = "dataBase\\Client\\Last Client ID.txt";
		int id = getLastIds(fileName);
		return id;
	}

	// Employee Id
	static void saveLastEmployeeId() {
		string fileName = "dataBase\\Employee\\LastEmployeeID.txt";
		saveLastIds(fileName, getLastIds(fileName));
	}
	static int getLastEmployeeId() {
		string fileName = "dataBase\\Employee\\LastEmployeeID.txt";
		int id = getLastIds(fileName);
		return id;
	}

	// Save new data
	static void saveClient(Client& c) {
		ofstream addClient;
		string line = c.getAccountNumber() + "|" + c.getBankID() + "|"
			+ c.getNationalID() + "|" + c.getName() + "|"
			+ c.getPassword() + "|" + c.getGender() + "|" +
			c.getPhone() + "|" + c.getEmail() + "|"
			+ to_string(c.getBalance());
		addClient.open("dataBase\\Client\\Clients.txt", ios::app);
		if (addClient.is_open()) {
			addClient << line << endl;
		}
		addClient.close();
		saveLastAccountNumber();
		saveLastClientId();
		AllClients.push_back(c);
	}

	static void saveEmployee(Employee& e) {
		ofstream addEmployee;
		string line = e.getBankId() + "|"
			+ e.getNationalID() + "|" + e.getName() + "|"
			+ e.getPassword() + "|" + e.getGender() + "|" +
			e.getPhone() + "|" + e.getEmail() + "|"
			+ e.getDateOfAppointment() + "|"
			+ to_string(e.getSalary());
		addEmployee.open("dataBase\\Employee\\Employes.txt", ios::app);
		if (addEmployee.is_open()) {
			addEmployee << line << endl;
		}
		addEmployee.close();
		saveLastEmployeeId();
		AllEmployes.push_back(e);
	}

	static void saveAdmin(Admin& e) {
		ofstream addAdmin;
		string line = e.getBankId() + "|"
			+ e.getNationalID() + "|" + e.getName() + "|"
			+ e.getPassword() + "|" + e.getGender() + "|" +
			e.getPhone() + "|" + e.getEmail() + "|"
			+ e.getDateOfAppointment() + "|"
			+ to_string(e.getSalary());
		addAdmin.open("dataBase\\Admin\\Admin.txt", ios::app);
		if (addAdmin.is_open()) {
			addAdmin << line << endl;
		}
		addAdmin.close();
	}

	// Importing Data from text files
	static void importClientsData() {
		ifstream getClientsData;
		getClientsData.open("dataBase\\Client\\Clients.txt");
		string line;
		if (getClientsData.is_open()) {
			while (getline(getClientsData, line)) {
				AllClients.push_back(Parser::ParseToClient(line));
			}
		}
		getClientsData.close();
	}

	static void importEmployesData() {
		ifstream getEmployesData;
		getEmployesData.open("dataBase\\Employee\\Employes.txt");
		string line;
		if (getEmployesData.is_open()) {
			while (getline(getEmployesData, line)) {
				AllEmployes.push_back(Parser::ParseToEmployee(line));
			}
		}
		getEmployesData.close();
	}

	static void importAdminData() {
		ifstream getAdminData;
		getAdminData.open("dataBase\\Admin\\Admin.txt");
		string line;
		if (getAdminData.is_open()) {
			while (getline(getAdminData, line)) {
				systemAdmin.push_back(Parser::ParseToAdmin(line));
			}
		}
		getAdminData.close();
	}

	// print all clients & Employes data
	static void getClientsData() {
		for (int i = 0; i < AllClients.size(); i++)
		{
			AllClients[i].displayInfo();
		}
	}

	static void getEmployesData() {
		for (int i = 0; i < AllEmployes.size(); i++)
		{
			AllEmployes[i].displayInfo();
		}
	}


	// Clear Files
	static void clearClients() {
		clearFile("dataBase\\Client\\Clients.txt",
			"dataBase\\Client\\Last Client ID.txt", 1000000000);

		// Restore Account Number file
		saveLastIds("dataBase\\Client\\Last Account Number.txt", 100);

		while (!AllClients.empty()) {
			AllClients.pop_back();
		}
	}

	static void clearEmployes() {
		clearFile("dataBase\\Employee\\Employes.txt",
			"dataBase\\Employee\\LastEmployeeID.txt", 1000000000);

		while (!AllEmployes.empty()) {
			AllEmployes.pop_back();
		}
	}


};


#endif // FILESHELPER_H

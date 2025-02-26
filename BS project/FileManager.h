#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"

class FileManager :public DataSourceInterface
{
private:
	static void addClient(Client c) {
		FilesHelper::saveClient(c);
		FilesHelper::saveTransaction(c.getTransactions());
	}

	static void addEmployee(Employee e) {
		FilesHelper::saveEmployee(e);
	}

	static void getAllClients() {
		FilesHelper::importClientsData();
		FilesHelper::importTransactionsData();
	}

	static void getAllEmployes() {
		FilesHelper::importEmployesData();
	}

	static void getAdmin() {
		FilesHelper::importAdminData();
	}

	static void removeAllClients() {
		FilesHelper::clearClientsFile();
		FilesHelper::clearTransactionsFile();
	}

	static void removeAllEmployes() {
		FilesHelper::clearEmployesFile();
	}

public:
	static void getAllData() {
		getAllClients();
		getAllEmployes();
		getAdmin();
	}

	static void updateClients() {
		removeAllClients();
		for (upClIt = AllClients.begin(); upClIt != AllClients.end(); upClIt++) {
			addClient(*upClIt);
		}
	}

	static void updateEmployes () {
		removeAllEmployes();
		for (upEmIt = AllEmployes.begin(); upEmIt != AllEmployes.end(); upEmIt++) {
			addEmployee(*upEmIt);
		}
	}
};

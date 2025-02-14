#ifndef FILEMANAGER_H
#define FILEMANAGER_H

//#include "DataSourceInterface.h"
#include "FilesHelper.h"


class FileManager  {
public:
	static void addClient(Client c) {
		FilesHelper::saveClient(c);
	}

	static void addEmployee(Employee e) {
		FilesHelper::saveEmployee(e);
	}

	/*static void addAdmin(Admin a) {
		FilesHelper::saveAdmin(a);
	}*/

	static void getAllClients() {
		FilesHelper::getClientsData();
	}

	static void getAllEmployes() {
		FilesHelper::getEmployesData();
	}

	static void removeAllClients() {
		FilesHelper::clearClients();
	}

	static void removeAllEmployes() {
		FilesHelper::clearEmployes();
	}


};

#endif // FILEMANAGER_H

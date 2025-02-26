#pragma once
#include "Admin.h"
//#include "Client.h"

class DataSourceInterface
{
public:
	virtual void addClient(Client* c) = 0;
	virtual void addEmployee(Employee* e) = 0;
	//virtual void addAdmin(Admin a) = 0;
	virtual void getAllClients() = 0;
	virtual void getAllEmployes() = 0;
	//virtual void getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployes() = 0;
	//virtual void removeAllAdmins() = 0;
};


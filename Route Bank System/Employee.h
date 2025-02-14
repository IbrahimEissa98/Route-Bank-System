#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Client.h"
#include <fstream>
//#include "Person.h"
//#include "GlobalMethods.h"
//#include "GlobalData.h"
//#include "Functions.h"
//#include "FileManager.h"
//#include "FilesHelper.h"
//#include "DataSourceInterface.h"
//#include "Parser.h"

extern vector<Client> AllClients;



class Employee :public Person {
protected:
	static int staticEmployeeBankId;
	string BankId;
	double salary;
	Date dateOfAppointment;

public:

	Employee() {
		this->salary = 0;
		this->BankId = "E" + to_string(staticEmployeeBankId++);
	}

	Employee(string nationalID, string name, string password,
		string gender, string phone, string email, double salary)
		:Person(nationalID, name, password, gender,phone,email) {
		setSalary(salary);
		this->BankId = "E" + to_string(staticEmployeeBankId++);
		this->dateOfAppointment = GlobalMethods::dateOfAppointment();
	}

	Employee(string nationalID, string name, string password,
		string gender, string phone, double salary)
		:Person(nationalID, name, password, gender, phone) {
		setSalary(salary);
		this->BankId = "E" + to_string(staticEmployeeBankId++);
		this->dateOfAppointment = GlobalMethods::dateOfAppointment();
	}
	Employee( string bankID, string nationalID, string name,
		string password, string gender, string phone,
		string email, Date dateOfAppointment, double salary)
		:Person(nationalID, name, password, gender, phone, email) {
		this->BankId = bankID;
		this->salary = salary;
		this->dateOfAppointment = dateOfAppointment;
	}

	// Setters:
	void setBankId(string id) {
		this->BankId = id;
	}
	void setSalary(double salary) {
		if (Validation::salary(salary)) {
			this->salary = salary;
		}
		else {
			//throw exception("Invalid less Salary !!");
			cout << "Invalid less Salary !!" << endl;
		}
	}
	void setDateOfAppointment(Date appointmentDate) {
		this->dateOfAppointment = appointmentDate;
	}

	// Getters:
	string getBankId() {
		return BankId;
	}
	double getSalary() {
		return this->salary;
	}
	string getDateOfAppointment() {
		return this->dateOfAppointment.getDate();
	}

	// Methods:
	void addClient() {
		cout << "\nAdding Client -->>" << endl;
		string id = GlobalMethods::inputID();
		if (Validation::calculateAge(Validation::getBirthDateFromId(id)) < 21) {
			system("pause>0");
			return;
		}
		string name = GlobalMethods::inputName();
		string pass = GlobalMethods::inputPassword();
		string gender = GlobalMethods::inputGender();
		string phone = GlobalMethods::inputPhone();
		string email = GlobalMethods::inputEmail();
		double balance = GlobalMethods::inputBalance();
		Client c(id, name, pass, gender, phone, email, balance);
		c.displayInfo();
		AllClients.push_back(c);
		//FilesHelper::saveClient(c);
		//GlobalMethods::inputClient();
	}

	Client* searchClient(string id) {
		for (int it = 0; it < AllClients.size(); it++) {
			if (AllClients[it].getNationalID() == id) {
				AllClients[it].displayInfo();
				return &(AllClients[it]);
			}
			else {
				cout << "Client Not found.." << endl;
				return nullptr;
			}
		}
	}

	void listClients() {
		if (AllClients.empty()) {
			cout << "No Available Clients.." << endl;
			return;
		}
		for (int it = 0; it < AllClients.size(); it++) {
			AllClients[it].displayInfo();
		}
	}

	void editClient(string id) {
		if (searchClient(id) != nullptr) {
			searchClient(id)->setName(GlobalMethods::inputName());
			searchClient(id)->setPassword(GlobalMethods::inputPassword());
			searchClient(id)->setPhone(GlobalMethods::inputPhone());
			searchClient(id)->setGender(GlobalMethods::inputGender());
			searchClient(id)->setEmail(GlobalMethods::inputEmail());
			searchClient(id)->setBalance(GlobalMethods::inputBalance());
		}
	}

	void exitEmployeeSystem() {
		ofstream file("dataBase\\Client\\Clients.txt", ios::trunc);
		if (file.is_open()) {
			for (auto c : AllClients) {
				string line = c.getAccountNumber() + "|" + c.getBankID() + "|"
					+ c.getNationalID() + "|" + c.getName() + "|"
					+ c.getPassword() + "|" + c.getGender() + "|" +
					c.getPhone() + "|" + c.getEmail() + "|"
					+ to_string(c.getBalance());
				file << line << endl;
			}
			file.close();
		}
	}

	void displayInfo() {
		cout << endl;
		cout << "Bank ID       : " << this->BankId << endl;
		cout << "National ID   : " << this->nationalID << endl;
		cout << "Name          : " << this->name << endl;
		cout << "Date of Birth : " << this->dob.getDate() << endl;
		cout << "Date of Appint: " << this->dateOfAppointment.getDate() << endl;
		cout << "Age           : " << this->age << endl;
		cout << "Gender        : " << this->gender << endl;
		cout << "Phone         : " << this->phone << endl;
		cout << "Email         : " << this->email << endl;
		cout << "Salary        : " << this->salary << " EGP" << endl;
		cout << "========================================" << endl;
	}
	~Employee() {}
};

#endif // EMPLOYEE_H

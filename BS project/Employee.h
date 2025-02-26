#pragma once
#include "Client.h"


class Employee :public Person
{
protected:
	static int staticEmployeeBankId;
	string BankId;
	double salary;
	Date dateOfAppointment;

public:

	Employee() {
		this->salary = 0;
	}

	Employee(string nationalID, string name, string password,
		string gender, string phone, string email, double salary)
		:Person(nationalID, name, password, gender,phone,email) {
		setSalary(salary);
		this->BankId = "E" + to_string(staticEmployeeBankId++);
		this->dateOfAppointment = dateOfAppointmentGetter();
	}

	Employee(string nationalID, string name, string password,
		string gender, string phone, double salary)
		:Person(nationalID, name, password, gender, phone) {
		setSalary(salary);
		this->BankId = "E" + to_string(staticEmployeeBankId++);
		this->dateOfAppointment = dateOfAppointmentGetter();
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
	void setBankId(string bankId = {}) {
		if (bankId.size() == 0) {
			this->BankId = "E" + to_string(staticEmployeeBankId++);
		}
		else {
			this->BankId = bankId;
		}
	}
	void setSalary(double salary) {
		if (Validation::salary(salary)) {
			this->salary = salary;
		}
		else {
			cout << red << "Invalid less Salary !!" << resetColor << endl;
		}
	}
	void setDateOfAppointment(Date appointmentDate) {
		this->dateOfAppointment = appointmentDate;
	}
	void setAutoDateOfAppointment() {
		this->dateOfAppointment = dateOfAppointmentGetter();
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
	void addClient(Client& client) {
		AllClients.push_back(client);
	}

	Client* searchClient(string id) {
		for (searchClIt = AllClients.begin(); searchClIt != AllClients.end(); searchClIt++) {
			if (searchClIt->getNationalID() == id) {
				return searchClIt._Ptr;
			}
		}
		cout << red << "\n\nClient Not found..\n" << resetColor << endl;
		return nullptr;
	}

	void listClients() {
		if (AllClients.empty()) {
			cout << red << "\nNo Available Clients..." << resetColor << endl;
			return;
		}
		for (searchClIt = AllClients.begin(); searchClIt != AllClients.end(); searchClIt++) {
			searchClIt->displayInfo();
		}
	}

	void editClient(string id) {
		if (searchClient(id) != nullptr) {
			searchClient(id)->setName(inputName());
			searchClient(id)->setPassword(inputPassword());
			searchClient(id)->setPhone(inputPhone());
			searchClient(id)->setGender(inputGender());
			searchClient(id)->setEmail(inputEmail());
			searchClient(id)->setBalance(inputBalance());
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

static vector<Employee> AllEmployes;
static vector<Employee>::iterator emIt;
static vector<Employee>::iterator upEmIt;
static vector<Employee>::iterator searchEmIt;

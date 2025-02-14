#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"
//#include "FileManager.h"

extern vector<Employee> AllEmployes;

class Admin :public Employee {
public:
	Admin() {
		this->BankId = "ADMIN_1000";
	}
	Admin(string nationalID, string name, string password,
		string gender, string phone, string email, double salary)
		:Employee(nationalID, name, password, gender, phone, email, salary) {
		this->BankId = "ADMIN_1000";
	}
	Admin(string nationalID, string name, string password,
		string gender, string phone, double salary)
		:Employee(nationalID, name, password, gender, phone, salary) {
		this->BankId = "ADMIN_1000";
	}
	Admin(string bankId, string nationalID, string name, string password,
		string gender, string phone, string email, Date dateOfAppointment, double salary)
		:Employee(bankId, nationalID, name, password, gender, phone, email, dateOfAppointment, salary) {

	}


	// Methods:
	void addEmployee() {
		cout << "\nAdding Employee -->>" << endl;
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
		double salary = GlobalMethods::inputSalary();
		Employee e(id, name, pass, gender, phone, email, salary);
		e.displayInfo();
		AllEmployes.push_back(e);
	}

	Employee* searchEmployee(string id) {
		for (int it = 0; it < AllEmployes.size(); it++) {
			if (AllEmployes[it].getNationalID() == id) {
				AllEmployes[it].displayInfo();
				return &(AllEmployes[it]);
			}
			else {
				cout << "Employee Not found.." << endl;
				return nullptr;
			}
		}
	}

	void listEmployes() {
		if (AllEmployes.empty()) {
			cout << "No Available Employes.." << endl;
			return;
		}
		for (int it = 0; it < AllEmployes.size(); it++) {
			AllEmployes[it].displayInfo();
		}
	}

	void editClient(string id) {
		if (searchEmployee(id) != nullptr) {
			searchEmployee(id)->setName(GlobalMethods::inputName());
			searchEmployee(id)->setPassword(GlobalMethods::inputPassword());
			searchEmployee(id)->setPhone(GlobalMethods::inputPhone());
			searchEmployee(id)->setGender(GlobalMethods::inputGender());
			searchEmployee(id)->setEmail(GlobalMethods::inputEmail());
			searchEmployee(id)->setSalary(GlobalMethods::inputBalance());
		}
	}

	void exitAdminSystem() {
		exitEmployeeSystem();
		ofstream file("dataBase\\Employee\\Employes.txt", ios::trunc);
		if (file.is_open()) {
			for (auto c : AllEmployes) {
				string line = c.getBankId() + "|"
					+ c.getNationalID() + "|" + c.getName() + "|"
					+ c.getPassword() + "|" + c.getGender() + "|" +
					c.getPhone() + "|" + c.getEmail() + "|"
					+ to_string(c.getSalary());
				file << line << endl;
			}
			file.close();
		}
	}


	~Admin() {}
};


#endif // ADMIN_H

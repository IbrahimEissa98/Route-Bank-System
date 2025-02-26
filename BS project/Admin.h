#pragma once
#include "Employee.h"
#include "FileParser.h"

class Admin : public Employee
{
private:
	Admin() {
		this->BankId = "ADMIN_1";
	}
	Admin(string nationalID, string name, string password,
		string gender, string phone, string email, double salary)
		:Employee(nationalID, name, password, gender, phone, email, salary) {
		this->BankId = "ADMIN_1";
	}
	Admin(string bankId, string nationalID, string name, string password,
		string gender, string phone, string email, Date dateOfAppointment, double salary)
		:Employee(bankId, nationalID, name, password, gender, phone, email, dateOfAppointment, salary) { }

	static Admin* sysAdmin;

public:
	Admin(const Admin&) = delete;
	Admin& operator=(const Admin&) = delete;

	static Admin* getAdmin() {
		if (sysAdmin == nullptr) {
			sysAdmin = loadAdminFromFile();
			if (sysAdmin == nullptr) {
				while (true) {
					vector<string>v = inputAdminData();
					if (v.size() == 7) {
						sysAdmin = new Admin(v[0], v[1], v[2], v[3], v[4], v[5], stod(v[6]));
						saveAdminToFile();
						break;
					}
				}
			}
		}
		return sysAdmin;
	}


	// Methods:
	void addEmployee(Employee& employee) {
		AllEmployes.push_back(employee);
	}

	Employee* searchEmployee(string id) {
		for (searchEmIt=AllEmployes.begin(); searchEmIt != AllEmployes.end(); searchEmIt++) {
			if (searchEmIt->getNationalID() == id) {
				return searchEmIt._Ptr;
			}
		}
		cout << red << "\n\nEmployee Not found...\n" << resetColor << endl;
		return nullptr;
	}

	void listEmployes() {
		if (AllEmployes.empty()) {
			cout << red << "No Available Employes.." << resetColor << endl;
			return;
		}
		for (searchEmIt = AllEmployes.begin(); searchEmIt != AllEmployes.end(); searchEmIt++) {
			searchEmIt->displayInfo();
		}
	}

	void editEmployee(string id) {
		if (searchEmployee(id) != nullptr) {
			searchEmployee(id)->setName(inputName());
			searchEmployee(id)->setPassword(inputPassword());
			searchEmployee(id)->setPhone(inputPhone());
			searchEmployee(id)->setGender(inputGender());
			searchEmployee(id)->setEmail(inputEmail());
			searchEmployee(id)->setSalary(inputBalance());
		}
	}

	static vector<string> splitEmployee(string line) {
		vector<string> v;
		stringstream s(line);
		string part;
		while (getline(s, part, '|')) {
			v.push_back(part);
		}
		return v;
	}

	static Admin* loadAdminFromFile() {
		ifstream file("dataBase\\Admin\\Admin.txt");
		if (!file.is_open()) {
			cout << red << "Error: Unable to open file for loading Admin data." << resetColor << endl;
			return nullptr;
		}

		string line;
		if (getline(file, line)) {
			vector<string> data = splitEmployee(line);
			if (data.size() == 9) {
				file.close();
				return new Admin(data[0], data[1], data[2], data[3], data[4], data[5], data[6], convertDate(data[7]), stod(data[8]));
			}
			else {
				cout << red << "Error: Incomplete Admin data in file" << resetColor << endl;
			}
		}
		file.close();
		return nullptr;
	}

	static void saveAdminToFile() {
		string date = sysAdmin->getBankId() + "|"
			+ sysAdmin->getNationalID() + "|" + sysAdmin->getName() + "|"
			+ sysAdmin->getPassword() + "|" + sysAdmin->getGender() + "|" +
			sysAdmin->getPhone() + "|" + sysAdmin->getEmail() + "|"
			+ sysAdmin->getDateOfAppointment() + "|"
			+ to_string(sysAdmin->getSalary());
		ofstream saveAdmin("dataBase\\Admin\\Admin.txt");
		if (saveAdmin.is_open()) {
			saveAdmin << date;
			saveAdmin.close();
		}
		else {
			cout << red << "Error: Unable to open file for saving Admin data." << resetColor << endl;
		}
	}

	~Admin() {}
};

static Admin* systemAdmin;
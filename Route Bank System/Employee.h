#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include"Person.h"

class Employee :public Person {
protected:
	double salary;

public:

	Employee() {
		this->salary = 0;
	}

	Employee(string nationalID, string name, string password,
		string gender, string phone, string email, double salary)
		:Person(nationalID, name, password, gender,phone,email) {
		setSalary(salary);
	}

	Employee(string nationalID, string name, string password,
		string gender, string phone, double salary)
		:Person(nationalID, name, password, gender, phone) {
		setSalary(salary);
	}


	void setSalary(double salary) {
		if (Validation::salary(salary)) {
			this->salary = salary;
		}
		else {
			cout << "Invalid less Salary !!" << endl;
		}
	}

	double getSalary() {
		return this->salary;
	}

	void displayInfo() {
		cout << endl;
		cout << "Bank ID       : " << this->bankId << endl;
		cout << "National ID   : " << this->nationalID << endl;
		cout << "Name          : " << this->name << endl;
		cout << "Date of Birth : " << this->dob.getDate() << endl;
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

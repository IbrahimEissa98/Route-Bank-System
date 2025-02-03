#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <exception>
#include"Date.h"
#include"Person.h"
using namespace std;

class Employee :public Person {
protected:
	double salary;

public:

	Employee() {
		this->salary = 0;
	}

	Employee(string nationalID, string name, string password, string gender, double salary)
		:Person(nationalID, name, password, gender) {
		this->salary = salary;
	}


	void setSalary(double salary) {
		if (!(Validation::balance(salary))) {
			//throw exception("Invalide less Salary !!");
		}
		else {
			this->salary = salary;
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
		cout << "Salary        : " << this->salary << " EGP" << endl;
		cout << "========================================" << endl;
	}
	~Employee() {}
};

#endif // EMPLOYEE_H

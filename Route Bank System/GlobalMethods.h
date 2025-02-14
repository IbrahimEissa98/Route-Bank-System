#ifndef GLOBALMETHODS_H
#define GLOBALMETHODS_H

//#include <iostream>
//#include <string>
#include <sstream>
#include <vector>
#include "Validation.h"
//#include "GlobalData.h"
//#include "Client.h"
//#include "FileManager.h"
//#include "Admin.h"
//#include "Date.h"
//#include <thread>
//#include <chrono>
//using namespace std::chrono;

class GlobalMethods
{
public:
	static string accountNumberYM() {  //Year & month
		auto now = system_clock::now();
		time_t now_c = system_clock::to_time_t(now);
		tm now_tm;
		localtime_s(&now_tm, &now_c);
		int currentYear = 1900 + now_tm.tm_year;
		int currentMonth = now_tm.tm_mon;
		int currentDay = now_tm.tm_mday;
		if (currentMonth < 9) {
			if (currentDay < 10) {
				return to_string(currentYear)
					+ "0" + to_string(currentMonth + 1)
					+ "0" + to_string(currentDay);
			}
			else {
				return to_string(currentYear)
					+ "0" + to_string(currentMonth + 1)
					+ to_string(currentDay);
			}
		}
		else {
			if (currentDay < 10) {
				return to_string(currentYear)
					+ to_string(currentMonth + 1)
					+ "0" + to_string(currentDay);
			}
			else {
				return to_string(currentYear)
					+ to_string(currentMonth + 1)
					+ to_string(currentDay);
			}
		}
	}

	static Date dateOfAppointment() {  //Year & month
		auto now = system_clock::now();
		time_t now_c = system_clock::to_time_t(now);
		tm now_tm;
		localtime_s(&now_tm, &now_c);
		int currentYear = 1900 + now_tm.tm_year;
		int currentMonth = now_tm.tm_mon;
		int currentDay = now_tm.tm_mday;

		return Date(currentDay, currentMonth + 1, currentYear);
	}

	static Date convertDate(string sDate) {
		vector<int> v;
		stringstream s(sDate);
		while (getline(s, sDate, '/')) {
			v.push_back(stoi(sDate));
		}
		return Date(v[0], v[1], v[2]);
	}


	static string inputID() {
		cout << "National ID :  ";
		string nationalId;
		cin >> nationalId;
		while (!(Validation::nationalId(nationalId))) {
			cout << "Invalid National ID !!" << endl;
			cout << "National ID :  ";
			cin >> nationalId;
		}
		return nationalId;
	}

	static string inputName() {
		cout << "Name :  ";
		string name;
		//cin.ignore();
		getline(cin >> ws, name);
		while (!(Validation::name(name))) {
			cout << "Invalid Name !!" << endl;
			cout << "Name :  ";
			getline(cin >> ws, name);
		}
		return name;
	}

	static string inputPassword() {
		cout << "Password :  ";
		string pass;
		cin >> pass;
		while (!(Validation::password(pass))) {
			cout << "Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)" << endl;
			cout << "Password :  ";
			cin >> pass;;
		}
		return pass;
	}

	static string inputGender() {
		cout << "Gender :  ";
		string gender;
		int num;
		cout << "1) Male    2) Female   ";
		cin >> num;
		while (num != 1 && num != 2) {
			cout << "Invalid Gender Choice !!" << endl;
			cout << "1) Male    2) Female   ";
			cin >> num;
		}
		if (num == 1)
			gender = "Male";
		else if (num == 2)
			gender = "Female";
		return gender;
	}

	static string inputPhone() {
		cout << "Phone Number :  ";
		string phone;
		cin >> phone;
		while (!Validation::phone(phone)) {
			cout << "Invalid phone number !!" << endl;
			cout << "Phone Number :  ";
			cin >> phone;
		}
		return phone;
	}

	static string inputEmail() {
		int choice;
		string email;
		cout << "Do you have an email to receive messages and updates? ";
		cout << "1 - Yes  2 - No  ";
		cin >> choice;
		while (choice != 1 && choice != 2) {
			cout << "Invalid Choice !!" << endl;
			cout << "1 - Yes  2 - No   ";
			cin >> choice;
		}
		if (choice == 1) {
			cout << "Email :  ";
			cin >> email;
			while (!Validation::email(email)) {
				cout << "Invalid Email Address !!" << endl;
				cout << "Email :  ";
				cin >> email;
			}
		}
		return email;
	}

	static double inputBalance() {
		cout << "Start Balance\"at least 1500 EGP\" :  ";
		double balance;
		cin >> balance;
		while (!Validation::balance(balance)) {
			cout << "Invalid Start Balance !!" << endl;
			cout << "Start Balance :  ";
			cin >> balance;
		}
		return balance;
	}

	static double inputSalary() {
		cout << "Salary\"at least 5000 EGP\" :  ";
		double salary;
		cin >> salary;
		while (!Validation::salary(salary)) {
			cout << "Invalid Start Balance !!" << endl;
			cout << "Start Balance :  ";
			cin >> salary;
		}
		return salary;
	}

	/*static Client inputClient() {
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
		return c;
	}*/
};

#endif // GLOBALMETHODS_H

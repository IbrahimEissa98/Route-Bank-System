#pragma once
#include <sstream>
#include <vector>
#include "Validation.h"
#include <fstream>


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

static Date dateOfAppointmentGetter() {  //Year & month
	auto now = system_clock::now();
	time_t now_c = system_clock::to_time_t(now);
	tm now_tm;
	localtime_s(&now_tm, &now_c);
	int currentYear = 1900 + now_tm.tm_year;
	int currentMonth = now_tm.tm_mon;
	int currentDay = now_tm.tm_mday;

	return Date(currentDay, currentMonth + 1, currentYear);
}

static string realTime() {  //Year & month
	auto now = system_clock::now();
	time_t now_c = system_clock::to_time_t(now);
	tm now_tm;
	localtime_s(&now_tm, &now_c);
	int currenthour = now_tm.tm_hour;
	int currentmin = now_tm.tm_min;

	return (to_string(currenthour) + ":" + to_string(currentmin));
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
	cout << "\nNational ID :  ";
	string nationalId;
	cin >> nationalId;
	while (!(Validation::nationalId(nationalId))) {
		cout << red << "Invalid National ID !" << resetColor << endl;
		cout << "National ID :  ";
		cin >> nationalId;
	}
	return nationalId;
}

static string inputName() {
	cout << "\nName :  ";
	string name;
	getline(cin >> ws, name);
	while (!(Validation::name(name))) {
		cout << red << "Invalid Name !!" << resetColor << endl;
		cout << "Name :  ";
		getline(cin >> ws, name);
	}
	return name;
}

static string inputPassword() {
	cout << "\nPassword :  ";
	string pass;
	cin >> pass;
	while (!(Validation::password(pass))) {
		cout << red << "Invalid Password ID !!\nPlease use Capital and small letters and at least 1 number and symbol :)" << resetColor << endl;
		cout << "Password :  ";
		cin >> pass;;
	}
	return pass;
}

static string inputGender() {
	cout << "\nGender :  ";
	string gender;
	int num;
	cout << "1) Male    2) Female   ";
	cin >> num;
	while (num != 1 && num != 2) {
		cout << red << "Invalid Gender Choice !!" << resetColor << endl;
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
	cout << "\nPhone Number :  ";
	string phone;
	cin >> phone;
	while (!Validation::phone(phone)) {
		cout << red << "Invalid phone number !!" << resetColor << endl;
		cout << "Phone Number :  ";
		cin >> phone;
	}
	return phone;
}

static string inputEmail() {
	int choice;
	string email;
	cout << "\nDo you have an email to receive messages and updates? ";
	cout << "1 - Yes  2 - No  ";
	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << red << "Invalid Choice !!" << resetColor << endl;
		cout << "1 - Yes  2 - No   ";
		cin >> choice;
	}
	if (choice == 1) {
		cout << "\nEmail :  ";
		cin >> email;
		while (!Validation::email(email)) {
			cout << red << "Invalid Email Address !!" << resetColor << endl;
			cout << "Email :  ";
			cin >> email;
		}
	}
	return email;
}

static double inputBalance() {
	cout << "\nStart Balance \"at least 1500 EGP\" :  ";
	double balance;
	cin >> balance;
	while (!Validation::balance(balance)) {
		cout << red << "Invalid Start Balance !!" << resetColor << endl;
		cout << "Start Balance :  ";
		cin >> balance;
	}
	return balance;
}

static double inputSalary() {
	cout << "\nSalary \"at least 5000 EGP\" :  ";
	double salary;
	cin >> salary;
	while (!Validation::salary(salary)) {
		cout << red << "Invalid Salary !!" << resetColor << endl;
		cout << "Salary :  ";
		cin >> salary;
	}
	return salary;
}

static vector<string> inputAdminData() {
	vector<string> v;
	cout << headColor << "\nAdding Admin -->>\n\n" << resetHead << endl;

	string id = inputID();
	if (Validation::calculateAge(Validation::getBirthDateFromId(id)) < 21) {
		return v;
	}
	string name = inputName();
	string pass = inputPassword();
	string gender = inputGender();
	string phone = inputPhone();
	string email = inputEmail();
	double salary = inputSalary();

	v = { id,name,pass,gender,phone,email,to_string(salary) };
	return v;
}



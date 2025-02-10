#include "Functions.h"

void WelcomePage() {
	string welcomePage[] = {
	"                          *     *  *******  *         *****   *****    *     *  *******",
	"                          *     *  *        *       *        *     *   **   **  *      ",
	"                          *     *  *        *       *        *     *   * * * *  *      ",
	"                          *  *  *  *******  *       *        *     *   *  *  *  *******",
	"                          * * * *  *        *       *        *     *   *     *  *      ",
	"                          **   **  *        *       *        *     *   *     *  *      ",
	"                          *     *  *******  *******   *****   *****    *     *  *******",
	"",
	"",
	"                                                 *******   ***** ",
	"                                                    *     *     *",
	"                                                    *     *     *",
	"                                                    *      ***** ",
	"",
	"",
	"                                   *****     *****    *     *  *******  *******",
	"                                   *    *   *     *   *     *     *     *      ",
	"                                   *    *   *     *   *     *     *     *      ",
	"                                   *****    *     *   *     *     *     *******",
	"                                   *   *    *     *   *     *     *     *      ",
	"                                   *    *   *     *   *     *     *     *      ",
	"                                   *     *   *****     *****      *     *******",
	"",
	"                                         ******    ****   *     *  *    *",
	"                                         *     *  *    *  **    *  *   * ",
	"                                         *     *  *    *  * *   *  *  *  ",
	"                                         ******   ******  *  *  *  ***   ",
	"                                         *     *  *    *  *   * *  *  *  ",
	"                                         *     *  *    *  *    **  *   * ",
	"                                         ******   *    *  *     *  *    *"
	};

	for (int i = 0; i < 30; i++) {
		cout << welcomePage[i] << endl;
	}

	this_thread::sleep_for(chrono::milliseconds(4000));
	system("cls");
}

string inputID() {
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

string inputName() {
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

string inputPassword() {
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

string inputGender() {
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

string inputPhone() {
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

string inputEmail() {
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

double inputBalance() {
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

double inputSalary() {
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

void addClient() {
	cout << "\nAdding Client -->>" << endl;
	string id = inputID();
	string name = inputName();
	string pass = inputPassword();
	string gender = inputGender();
	string phone = inputPhone();
	string email = inputEmail();
	double balance = inputBalance();
	Client c(id, name, pass, gender, phone, email, balance);
	c.displayInfo();

}


void addEmployee() {
	cout << endl;
	cout << "Adding Employee -->>" << endl;

	string id = inputID();
	string name = inputName();
	string pass = inputPassword();
	string gender = inputGender();
	string phone = inputPhone();
	string email = inputEmail();
	double salary = inputSalary();


	Employee e(id, name, pass, gender, phone, email, salary);
	e.displayInfo();
}

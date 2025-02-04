#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>
#include <regex>
using namespace std;

class Validation {
public:
	/*static bool nationalId(string id) {
		if (id[0] != '2' && id[0] != '3') {
			return false;
		}
		if (id.length() != 14) {
			return false;
		}
		for (short i = 0; i < id.length(); i++) {
			if (id[i] < '0' || id[i]>'9') {
				return false;
			}
		}
		string date = id.substr(0, 7);
		int nDate = stoi(date);
		int arr[7]{};
		for (int i = 6; i >= 0; i--) {
			arr[i] = nDate % 10;
			nDate /= 10;
		}
		int day{}, month{}, year{};
		day = arr[5] * 10 + arr[6];
		if (day > 31)return false;
		month = arr[3] * 10 + arr[4];
		if (month > 12 || month < 1)return false;
		if (arr[0] == 2) {
			year = 1900 + arr[1] * 10 + arr[2];
		}
		else if (arr[0] == 3) {
			year = 2000 + arr[1] * 10 + arr[2];
		}
		if (year < 1930)return false;

		return true;
	}*/
	static bool nationalId(string ID) {
		regex pattern("^[23]\\d{2}(0[1-9]|1[0-2])(0[1-9]|[12]\\d|3[01])\\d{7}$"); // ID num must be 14 nums only
		return regex_match(ID, pattern);
	}

	/*static bool name(string name) {
		if (name.length() < 5 || name.length() > 20) {
			return false;
		}
		for (short i = 0; i < name.length(); i++) {
			if (!(name[i] >= 'a' && name[i] <= 'z')
				&& !(name[i] >= 'A' && name[i] <= 'Z')
				&& name[i] != ' ') {
				return false;
			}
		}
		return true;
	}*/
	static bool name(string name) {
		regex pattern("^[A-Za-z ].{5,20}$"); // allow capital letters and spaces only and max of 5 to 20 letter
		return regex_match(name, pattern);
	}

	/*static bool password(string password) {
		short numCount{}, capCount{}, smallCount{}, symbCount{};
		if (password.length() < 8 || password.length() > 20) {
			return false;
		}
		for (short i = 0; i < password.length(); i++) {
			if (password[i] >= 'a' && password[i] <= 'z') {
				smallCount++;
			}
			else if (password[i] >= 'A' && password[i] <= 'Z') {
				capCount++;
			}
			else if (password[i] >= '0' && password[i] <= '9') {
				numCount++;
			}
			else if ((password[i] >= '!' && password[i] <= '/')
				|| (password[i] >= ':' && password[i] <= '@')
				|| (password[i] >= '[' && password[i] <= '_')) {
				symbCount++;
			}
			else if (password[i] == ' ') {
				return false;
			}
		}
		if (numCount == 0 || capCount == 0 || smallCount == 0 || symbCount == 0) {
			return false;
		}
		return true;
	}*/
	static bool password(string password) {
		regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[!-\\/:-@\\[-_])[^\\s]{8,20}$");
		return regex_match(password, pattern);
	}

	static bool email(string email) {
		regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
		return regex_match(email, pattern);
	}

	static bool phone(string phone) {
		regex pattern("^0[1][0125]\\d{8}$"); // only num consist of 10 to 15 num
		return regex_match(phone, pattern);
	}

	static bool balance(double balance) {
		if (balance < 1500) {
			return false;
		}
		return true;
	}

	static bool salary(double salary) {
		if (salary < 5000) {
			return false;
		}
		return true;
	}
};

#endif // VALIDATION_H

#pragma once
#include "Date.h"
#include <regex>
#include <thread>
#include <chrono>
using namespace std::chrono;

class Validation
{
public:
	
	static bool nationalId(string ID) {
		regex pattern("^[23]\\d{2}(0[1-9]|1[0-2])(0[1-9]|[12]\\d|3[01])\\d{7}$"); // ID num must be 14 nums only
		return regex_match(ID, pattern);
	}

	static bool name(string name) {
		regex pattern("^(?=.{5,20}$)[A-Za-z ]+$"); // allow capital letters and spacesonly and max of 5 to 20 letter
		return regex_match(name, pattern);
	}

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
		else
			return true;
	}

	static bool salary(double salary) {
		if (salary < 5000) {
			return false;
		}
		else
			return true;
	}
	
	static int calculateAge(Date dob) {
		int birthYear = dob.getYear();

		// to get current year
		auto now = system_clock::now();
		time_t now_c = system_clock::to_time_t(now);
		tm now_tm;
		localtime_s(&now_tm, &now_c);
		int currentYear = 1900 + now_tm.tm_year;
		int ageC = currentYear - birthYear;
		if (ageC >= 21) {
			return ageC;
		}
		else {
			throw exception("\n\n\033[31mUnable to create account, you are under 21...!\033[39m\n\n");
		}
	}

	static Date getBirthDateFromId(string nationalID) {
		if (Validation::nationalId(nationalID)) {
			string nationalId = nationalID;
			string date = nationalId.substr(0, 7);
			int nDate = stoi(date);
			int arr[7]{};
			for (int i = 6; i >= 0; i--)
			{
				arr[i] = nDate % 10;
				nDate /= 10;
			}
			int day{}, month{}, year{};
			day = arr[5] * 10 + arr[6];
			month = arr[3] * 10 + arr[4];
			if (arr[0] == 2) {
				year = 1900 + arr[1] * 10 + arr[2];
			}
			else if (arr[0] == 3) {
				year = 2000 + arr[1] * 10 + arr[2];
			}
			return Date(day, month, year);
		}
		return Date();
	}
};


#pragma once
#include "FileManager.h"
#include "Header.h"

class ClientManager
{
public:
	static void printClientMenu() {
		headerBankName();
		cout << headColor << "WELCOME -->    " << resetHead << blue << clIt->getName() << resetColor <<"\n\n";
		cout << "< 1 > Display my informations\n" << endl;
		cout << "< 2 > Change password\n" << endl;
		cout << "< 3 > View account balance\n" << endl;
		cout << "< 4 > Deposit\n" << endl;
		cout << "< 5 > Withdraw\n" << endl;
		cout << "< 6 > Transfer an amount to another client\n" << endl;
		cout << "< 7 > Account Activity\n" << endl;
		cout << "< 0 > Logout\n" << endl;
	}

	static void updatePassword(Person* person) {
		updatePassFunc(person);
	}

	static Client* login(string id, string password) {
		return loginClientFunc(id, password);
	}

	static bool clientOptions(Client* client) {
		while (true) {
			printClientMenu();
			char choice{};
			while (true) {
				cout << "\nEnter your choice :  ";
				cin >> choice;
				if (choice < '0' || choice > '7') {
					cout << red << "Unknown Choice...!" << resetColor << endl;
					system("pause");
					break;
				}
				else {
					break;
				}
			}

			switch (choice) {
			case '1':
				headerBankName();
				client->displayInfo();
				system("pause");
				break;

			case '2':
				headerBankName();
				updatePassword(client);
				FileManager::updateClients();
				break;

			case '3':
				headerBankName();
				client->checkBalance();
				system("pause");
				break;

			case '4': {
				headerBankName();
				cout << headColor << "Deposit ==>\n\n" << resetHead;
				client->checkBalance();
				cout << "\nEnter amount :  ";
				double amout{};
				cin >> amout;
				client->deposit(amout);
				system("pause");
				FileManager::updateClients();
			}
				break;

			case '5': {
				headerBankName();
				cout << headColor << "Withdraw ==>\n\n" << resetHead;
				client->checkBalance();
				cout << "\nEnter amount :  ";
				double amout{};
				cin >> amout;
				client->withdraw(amout);
				system("pause");
				FileManager::updateClients();
			}
				break;

			case '6': {
				headerBankName();
				cout << headColor << "Transfer an amount to another client ==>\n\n" << resetHead;
				client->checkBalance();
				cout << "\nEnter amount :  ";
				double amout{};
				cin >> amout;
				cout << "\nEnter recipient national ID :  ";
				string id;
				cin >> id;
				for (searchClIt = AllClients.begin(); searchClIt != AllClients.end(); searchClIt++) {
					if (searchClIt->getNationalID() == id && id != client->getNationalID()) {
						client->trnsferTo(amout,*searchClIt);
						FileManager::updateClients();
						system("pause");
						break;
					}
				}
				if (searchClIt == AllClients.end()) {
					cout << red << "\n\nAmount transfer failed...!\n\n" << resetColor;
					system("pause");
				}
			}
				break;

			case '7':
				headerBankName();
				cout << headColor << "All Transactions for : " << resetHead << blue << client->getName() << resetColor << "\n\n";
				client->getTransactions().displayAllTransactions();
				system("pause");
				break;

			case '0':
				//Screens::logout();
				return false;

			default:
				break;
			}
		}
	}
};


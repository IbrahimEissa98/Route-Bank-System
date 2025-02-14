// Route Bank System
// Created by : Ibrahim Eissa - Nada Agamy - Mohamed Hany - Sara Salem - Qamar Emad
// C-22 Sun/Tues 3 - 6 PM
//======================================================

//#include "Functions.h"
//#include "Parser.h"
//#include "FilesHelper.h"
#include "FileManager.h"


double Person::dollar = 50.54;
int Client::staticAccountNumber = FilesHelper::getLastAccountNumber();
int Client::staticClientBankId = FilesHelper::getLastClientId();
int Employee::staticEmployeeBankId = FilesHelper::getLastEmployeeId();

int main()
{
    //WelcomePage();
    FilesHelper::importClientsData();
    FilesHelper::importEmployesData();
    FilesHelper::importAdminData();
    cout << AllClients.size();
    //cout << AllEmployes.size();
    /*for (int i = 0; i < AllEmployes.size(); i++)
    {
        AllEmployes[i].displayInfo();
    }*/
    //FilesHelper::getClientsData();
    //FilesHelper::clearClients();
    //FileManager::getAllEmployes();
    //cout << AllClients.size();
    FilesHelper::getClientsData();

    //Client c("25412231231233", "Ibrahim Eissa", "Hshd!7567", "male", "01012345678", 2000);
    //c.displayInfo();
    Employee c("25412231231233", "Ibrahim Eissa", "Hshd!7567", "male", "01012345678", 6000);
    c.addClient();
    string i;
    cin >> i;
    //c.searchClient(i);
    FilesHelper::getClientsData();

    //system("pause>0");
    //addClient();
    //Client c (Parser::ParseToClient("Route20250211001|C1000000001|25003151234567|hshkjsd sdjbgk|hsdgG$jk45|Male|01212345678|Not Available|1862.000000"));
    //string line = "Route20250211001|C1000000001|25003151234567|hshkjsd sdjbgk|hsdgG$jk45|Male|01212345678|Not Available|1862.000000";
    //AllClients.push_back(Parser::ParseToClient(line));
    //AllClients[0].displayInfo();
    //cout<<AllClients.size();


    //addClient();
    //addClient();
    //cout << FilesHelper::getLastAccountNumber() << endl;

    //c.displayInfo();
    //addEmployee();
    //addEmployee();

}

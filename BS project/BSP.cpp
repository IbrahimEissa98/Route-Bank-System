// BSP.cpp 

#include "Screens.h"


double Person::dollar = 50;
int Client::staticAccountNumber = FilesHelper::getLastAccountNumber();
int Client::staticClientBankId = FilesHelper::getLastClientId();
int Employee::staticEmployeeBankId = FilesHelper::getLastEmployeeId();
Admin* Admin::sysAdmin = nullptr;

int main()
{

    Screens::runApp();

}


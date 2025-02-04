// Route Bank System
// Created by : Ibrahim Eissa - Nada Agamy - Mohamed Hany - Sara Salem - Qamar Emad
// C-22 Sun/Tues 3 - 6 PM
//======================================================

#include <iostream>
#include <string>
#include <exception>
#include <Windows.h>
#include <cstdlib>
#include <cmath>
#include "Functions.h"
//#include "Person.h"
#include "Client.h"
//#include "Date.h"
#include "Validation.h"
using namespace std;

double Person::dollar = 50.54;
int Person::staticBankId = 1000000000;

int main()
{

    WelcomePage();

    Client c("25436231231233", "Ibrahim Eissa", "Hshd!7567", "male", "01012345678", 2000);
    c.displayInfo();

    addClient();

    addEmployee();
}

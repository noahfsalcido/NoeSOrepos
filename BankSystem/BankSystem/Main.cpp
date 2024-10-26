#include "stdafx.h"
#include <iostream>
#include "Main_Menu.h"
#include <string>
using namespace std;

int Option(string situation);

int main()
{
   int option;
   system("cls");
   string situation = "NULL";
   cout << "Please enter if Employee, ATM, or Exit to quit the system \n";
   cin >> situation;
   option = Option(situation);
   if (option != 3)
   {
      MainMenu::MenuAccess(option);
      main();
   }
}

int Option(string situation)
{
   int Option = 0;
   if ((situation == "Employee")||
      (situation == "employee"))
   {
      Option = 1;
   }
   else if ((situation == "ATM") ||
      (situation == "atm"))
   {
      Option = 2;
   }
   else if ((situation == "EXIT") ||
      (situation == "exit") ||
      (situation == "e"))
   {
      Option = 3;
   }
   else
   {
      Option = 0;
   }
   return Option;
}

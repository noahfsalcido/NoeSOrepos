// Application1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Main_Menu.h"
#include "Executive.h"
#include "DataFiles.h"
#include "Clients.h"
#include <string>
#include "math.h"
using namespace std;

namespace MainMenu
{
   Executive Exe_Class;
   Clients_Class Cli_Class;

   void MenuAccess(int Option)
   {
      int ID = -1;
      int failcount = 0;
      switch (Option)
      {
         case 1://Executive
         {
            while (failcount < 3)
            {
               string input;
               ID = -1;
               while (getline(cin, input))
               {
                  stringstream ss(input);
                  if (ss >> ID)
                  {
                     if(ss.eof())
                     {
                        failcount++;
                        break;
                     }
                  }
                  cout << "\nEnter your employee ID or '0' to exit\n";
               }
               if (Exe_Class.Search_ID(ID))
               {
                  MainMenu::ExecutiveMenu();
               }
               else if(ID == 0)
               {
                  break;
               }
               else
               {
                  failcount++;
               }
            }
            break;
         }
         case 2://ATM
         {
            while (failcount < 3)
            {
               string input;
               int clientID = -1;
               ID = -1;
               while (getline(cin, input))
               {
                  stringstream ss(input);
                  if (ss >> ID)
                  {
                     if (ss.eof())
                     {
                        failcount++;
                        break;
                     }
                  }
                  cout << "\nEnter your client ID or '0' to exit\n" << endl;
               }
               clientID = Cli_Class.Search_Client_ID(ID);
               if (clientID > -1)
               {
                  MainMenu::ATMClientMenu(clientID);
               }
               else if (ID == 0)
               {
                  break;
               }
               else
               {
                  cout << "\nERROR" << endl;
                  failcount++;
               }
            }
            break;
         }
         case 0:
         {
            break;
         }
         default:
         {
         //TODO
            break;
         }
      }
   }


   void ExecutiveMenu()
   {
      string name;
      string lastname;
      int c = 0;
      system("cls");
      printf("\nSelect your operation:"
         "\nPress 1 to Open a Client account"
         "\nPress 2 to Request a New Debit card"
         "\nPress 3 to Request a Client Loan"
         "\nPress 4 to Request a Credit Card for Client"
         "\nPress 5 to request a New Credit Card"
         "\nPress 6 to Exit\n");
      cin >> c;
      switch (c)
      {
         case 1://Open account
         {
            Exe_Class.OpenAccount();
            ExecutiveMenu();
         }
         case 2://Request a new card
         {
            Exe_Class.NewCard();
            system("pause");
            ExecutiveMenu();
            break;
         }
         case 3://Loan
         {
            int pointertoloan;
            system("cls");
            cout << "Enter Name who requests" << endl;
            cin >> name;
            cin >> lastname;
            if (Cli_Class.Search_Client_Name(name, lastname))
            {
               pointertoloan = Cli_Class.Clientnametogetarray(name, lastname);
               if(Exe_Class.CreditAccept(pointertoloan) == false)
               {
                  Exe_Class.LoanProcess(pointertoloan);
                  cout << "\nLoan was successfully complete\nnow you have a new loan" << endl;
               }
               else
               {
                  cout << "\nLoan rejected\n" << endl;
               }
            }
            cout << "Process finished successfully.\n" << endl;
            system("pause");
            ExecutiveMenu();
            break;
         }
         case 4://Credit Card
         {
            int pointertoloan;
            int cardnumber;
            system("cls");
            cout << "Enter Name who requests" << endl;
            cin >> name;
            cin >> lastname;
            if (Cli_Class.Search_Client_Name(name, lastname))
            {
               pointertoloan = Cli_Class.Clientnametogetarray(name, lastname);
               if (Exe_Class.CreditAccept(pointertoloan) == false)
               {
                  cout << "\nAccepted\n\nGenerating new credentials to credit\n" << endl;
                  cardnumber = Exe_Class.ProvideCreditCard(pointertoloan);
                  cout << "Credit Card Number: " << cardnumber << endl;
               }
               else
               {
                  cout << "\nREJECTED!" << endl;
               }
            }
            cout << "\nProcess finished successfully." << endl;
            system("pause");
            ExecutiveMenu();
            break;
         }
         case 5://Request a New Credit Card
         {
            int pointertoarray;
            int cardnumber;
            system("cls");
            cout << "Enter Name who requests" << endl;
            cin >> name;
            cin >> lastname;
            if (Cli_Class.Search_Client_Name(name, lastname))
            {
               pointertoarray = Cli_Class.Clientnametogetarray(name, lastname);
               cout << "\nRequesting New Card . . . .\n\n Please wait . . . " << endl;
               cardnumber = Exe_Class.ProvideandDeleteCreditCard(pointertoarray);
               cout << "\nNew Card Number: " << cardnumber << endl;
            }
            else
            {
               cout << "Unable to request new card" << endl;
               system("pause");
               ExecutiveMenu();
            }
            cout << "Process finished successfully.\n" << endl;
            system("pause");
            ExecutiveMenu();
            break;
         }
         case 6://Exit
         {
            break;
         }
      }
   }


   void ATMClientMenu(int clientID)
   {
      string clientname;
      int c = 0;
      clientname = Cli_Class.Search_Client_With_ID(clientID);
      system("cls");
      cout << "Hello " << clientname << "!" << endl;
      printf("\nWhat do you want to do?"
         "\nPress 1 to Retire money from account"
         "\nPress 2 to check money balance"
         "\nPress 3 to Deposit in own account"
         "\nPress 4 to Deposit in another account"
         "\nPress 5 to Pay loan"
         "\nPress 6 to Transfer money from account to another account"
         "\nPress 7 to Exit\n");
      cin >> c;
      switch (c)
      {
         case 1://Retire money
         {
            Cli_Class.Retiremoney(clientID);
            system("pause");
            MainMenu::ATMClientMenu(clientID);
            break;
         }
         case 2://check money balance
         {
            Cli_Class.CheckBalance(clientID);
            system("pause");
            MainMenu::ATMClientMenu(clientID);
            break;
         }
         case 3://Deposit in own account
         {
            int newbalance;
            newbalance = Cli_Class.Deposit(clientID);
            cout << "\nNow you have " << newbalance << " available\n" << endl;
            system("pause");
            MainMenu::ATMClientMenu(clientID);
            break;
         }
         case 4://Deposite in another account
         {
            int Otheraccount;
            cout << "\nEnter the account where you want to deposit " << endl;
            cin >> Otheraccount;
            Cli_Class.Deposit(Cli_Class.Search_Client_ID(Otheraccount));
            cout << "\nRequest completed . . ." << endl;
            system("pause");
            MainMenu::ATMClientMenu(clientID);
            break;
         }
         case 5://Pay loan
         {
            Cli_Class.PayLoan(clientID);
            system("pause");
            MainMenu::ATMClientMenu(clientID);
            break;
         }
         case 6://transfer money to other account
         {
            int account;
            int pointer;
            string decision;
            string clientodeposit;
            cout << "\nEnter the account where you want to transfer money" << endl;
            cin >> account;
            pointer = Cli_Class.Search_Client_ID(account);
            clientodeposit = Cli_Class.Search_Client_With_ID(pointer);
            cout << "\nClient found as " << clientodeposit << "\ndo you want to continue (Y/N)?" << endl;
            cin >> decision;
            if (decision == "n")
            {
               MainMenu::ATMClientMenu(clientID);
            }
            Cli_Class.transfer(clientID, pointer);
            cout << "\nRequest completed . . .\n" << endl;
            system("pause");
            MainMenu::ATMClientMenu(clientID);
            break;
         }
      }
   }
}
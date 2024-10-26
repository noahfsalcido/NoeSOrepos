#include "stdafx.h"
#include "Clients.h"
#include "DataFiles.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

Clients_Class::Clients_Class()
{
}

Clients_Class::~Clients_Class()
{
}


bool Clients_Class::Search_Client_Name(string name, string lastname)
{
   vector<string> NamesofClients;
   bool Found = false;
   string completename = name + " " + lastname;
   NamesofClients = DataFiles::GetClientList();
   int sizeref = NamesofClients.size();
   for (int i = 0; i < sizeref; i++)
   {
      if (completename == NamesofClients[i])
      {
         vector<int> ClientsID;
         cout << "Client " << NamesofClients[i];
         ClientsID = DataFiles::GetIDClient();
         cout << " Found With ID Number: " << ClientsID[i] << endl;
         Found = true;
         break;
      }
   }
   return Found;
}

int Clients_Class::Clientnametogetarray(string name, string lastname)
{
   vector<string> NamesofClients;
   int ID = NULL;
   string completename = name + " " + lastname;
   NamesofClients = DataFiles::GetClientList();
   int sizeref = NamesofClients.size();
   for (int i = 0; i < sizeref; i++)
   {
      if (completename == NamesofClients[i])
      {
         ID = i;
         break;
      }
   }
   return ID;
}


int Clients_Class::Search_Client_ID(int ID)
{
   vector<int> IDClients;
   IDClients = DataFiles::GetIDClient();
   int IDfound = -1;
   int sizeref = IDClients.size();
   for (int i = 0; i < sizeref; i++)
   {
      if (ID == IDClients[i])
      {
         IDfound = i;
         break;
      }
   }
   return IDfound;
}

string Clients_Class::Search_Client_With_ID(int ID)
{
   vector<string> Clients;
   string Client;
   Clients = DataFiles::GetClientList();
   Client = Clients[ID];
   return Client;
}


int Clients_Class::Generate_ID()
{
   int newID;
   vector<int> IDClients;
   system("cls");
   cout << "Generating credentials for new client . . . \nPlease wait . . .\n";
   IDClients = DataFiles::GetIDClient();
   newID = (IDClients[(IDClients.size() - 1)]) + 1;
   IDClients.push_back(newID);
   //TODO: Put on file
   DataFiles::InsertID(IDClients);
   return newID;
}

void Clients_Class::Retiremoney(int pointer)
{
   vector<int> Moneylist;
   int Newbalance = 0;
   int ammount = 0;
   cout << "\nEnter the amount to retire\n" << endl;
   cin >> ammount;
   Moneylist = DataFiles::GetMoneyList();
   Newbalance = Moneylist[pointer] - ammount;
   if (Newbalance < 0)
   {
      system("cls");
      cout << "\nYour balance is not enough to continue with operation\n\n";
      system("pause");
      Retiremoney(pointer);
   }
   else
   {
      Moneylist[pointer] = Newbalance;
      std::ofstream ofile("MoneyDataBase.txt");
      if (ofile.is_open())
      {
         int sizeref = Moneylist.size();
         for (int i = 0; i < sizeref; i++)
         {
            ofile << Moneylist[i] << endl;
         }
         ofile.close();
      }
      else
      {
         cout << "Can't reach database for Clients Money";
      }
      cout << "\nNow you have " << Newbalance << " available\n" << endl;
   }
}


void Clients_Class::CheckBalance(int pointer)
{
   vector<int> Moneylist;
   Moneylist = DataFiles::GetMoneyList();
   cout << "\nYour current balance is " << Moneylist[pointer] << endl;
}


int Clients_Class::Deposit(int pointer)
{
   vector<int> Moneylist;
   int Newmoney = 0;
   Moneylist = DataFiles::GetMoneyList();
   cout << "\nEnter the money that you want to deposit in account. " << endl;
   cin >> Newmoney;
   Moneylist = DataFiles::GetMoneyList();
   Moneylist[pointer] = Moneylist[pointer] + Newmoney;
   std::ofstream ofile("MoneyDataBase.txt");
   if (ofile.is_open())
   {
      int sizeref = Moneylist.size();
      for (int i = 0; i < sizeref; i++)
      {
         ofile << Moneylist[i] << endl;
      }
      ofile.close();
   }
   else
   {
      cout << "Can't reach database for Clients Money";
   }
   return Moneylist[pointer];
}


void Clients_Class::PayLoan(int pointer)
{
   int option = 0;
   vector<int> Loans;
   int payment;
   system("cls");
   cout << "\nPress 1 to pay from physical money\nPress 2 to pay from account" << endl;
   cin >> option;
   Loans = DataFiles::GetLoansList();
   if (Loans[pointer] == 0)
   {
      cout << "You don't have any loan to pay" << endl;
   }
   else
   {
      cout << "Enter the amount to pay" << endl;
      cin >> payment;
      if (payment > Loans[pointer])
      {
         payment = Loans[pointer];
         cout << "You exceeded the Loan, enter " << payment << "to continue\n" << endl;
      }
      switch (option)
      {
         case 1://Money
         {
            system("pause");
            Loans[pointer] = Loans[pointer] - payment;
            cout << "Your current loan is " << Loans[pointer] << endl;
            if (Loans[pointer] == 0)
            {
               cout << "\nCongratulations, you liquidated your loan" << endl;
            }
            DataFiles::InsertLoansList(Loans);
            break;
         }
         case 2://account
         {
            system("pause");
            vector<int> Balance;
            Balance = DataFiles::GetMoneyList();
            Loans[pointer] = Loans[pointer] - payment;
            Balance[pointer] = Balance[pointer] - payment;
            cout << "Your current loan is " << Loans[pointer] << endl;
            cout << "Your current balance is " << Balance[pointer] << endl;
            if (Loans[pointer] == 0)
            {
               cout << "\nCongratulations, you liquidated your loan" << endl;
            }
            DataFiles::InsertLoansList(Loans);
            DataFiles::InsertMoneylist(Balance);
            break;
         }
      }
   }
}


bool Clients_Class::transfer(int from, int to)
{
   vector<int> Moneylist;
   int Newmoney = 0;
   Moneylist = DataFiles::GetMoneyList();
   cout << "\nEnter the money that you want to deposit in account. " << endl;
   cin >> Newmoney;
   Moneylist = DataFiles::GetMoneyList();
   Moneylist[to] = Moneylist[to] + Newmoney;
   Moneylist[from] = Moneylist[from] - Newmoney;
   std::ofstream ofile("MoneyDataBase.txt");
   if (ofile.is_open())
   {
      int sizeref = Moneylist.size();
      for (int i = 0; i < sizeref; i++)
      {
         ofile << Moneylist[i] << endl;
      }
      ofile.close();
      return true;
   }
   else
   {
      cout << "Can't reach database for Clients Money";
      return false;
   }
}

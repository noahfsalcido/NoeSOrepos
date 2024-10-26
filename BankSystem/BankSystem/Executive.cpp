#include "stdafx.h"
#include "Executive.h"
#include "Clients.h"
#include "DataFiles.h"
#include "Main_Menu.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

Executive::Executive()
{
}

Executive::~Executive()
{
}

bool Executive::Search_ID(int ID)
{
   int EmployeesIDs[] = { 57128, 59128, 51923, 50912 };
   bool IDfound = false;
   for (int ite = 0; ite < sizeof(EmployeesIDs)/sizeof(*EmployeesIDs); ite++)
   {
      if (ID == EmployeesIDs[ite])
      {
         IDfound = true;
         break;
      }
   }
   return IDfound;
}

void Executive::OpenAccount()
{
   Clients_Class Client;
   int NewID = NULL;
   int DebitCard = NULL;
   string name;
   string lastname;
   int initialmoney = 0;
   cout << "\nEnter client's first name\n" << endl;
   cin >> name;
   if (name == "c")
   {
      MainMenu::ExecutiveMenu();
   }
   cout << "\nEnter client's last name\n" << endl;
   cin >> lastname;
   if (lastname == "c")
   {
      MainMenu::ExecutiveMenu();
   }
   cout << "\nEnter the money to open account\n" << endl;
   cin >> initialmoney;
   if (initialmoney == 0)
   {
      system("cls");
      cout << "Operation Cancelled\n" << endl;
      system("pause");
      MainMenu::ExecutiveMenu();
   }
   if (!Client.Search_Client_Name(name, lastname))
   {
      NewID = Client.Generate_ID();
      DataFiles::InsertClient(name, lastname);
      DataFiles::InsertMoney(initialmoney);
      DebitCard = ProvideCard();
      cout << "\nAccount successfully opened with number: " << NewID;
      cout << "\nOwner name: " << name << " " << lastname;
      cout << "\nDebit Card number: " << DebitCard;
      cout << "\nMoney to open account: " << initialmoney << "\n\n";
   }
   system("pause");
}

void Executive::NewCard()
{
   Clients_Class Client;
   string clientname;
   int accountnum;
   int indexfound;
   int newcard;
   cout << "\nEnter Account Number\n" << endl;
   cin >> accountnum;
   indexfound = Client.Search_Client_ID(accountnum);
   if (indexfound == NULL)
   {
      system("cls");
      cout << "\n\nClient not found, please verify\n";
      NewCard();
   }
   clientname = Client.Search_Client_With_ID(indexfound);
   system("cls");
   cout << "Client Found\n\nOwner name " << clientname << endl;
   cout << "Account number: " << accountnum << "\n" << endl;
   system("pause");
   newcard = ProvideandDeleteCard(indexfound);
   cout << "\n\nCard replaced by " << newcard << "\n\n" << endl;
}


int Executive::ProvideCard()
{
   vector<int> Cards;
   int Getting;
   int PossibleCard = 0;
   Cards = DataFiles::GetDebitCardList();
   Getting = Cards[Cards.size() - 1];
   PossibleCard = Getting + 1;
   while (!ValidatingCard(PossibleCard))
   {
      PossibleCard++;
   }
   Cards.push_back(PossibleCard);
   DataFiles::InsertCardonList(Cards);
   return PossibleCard;
}

int Executive::ProvideCreditCard(int pointer)
{
   vector<int> Cards;
   int Getting;
   int PossibleCard = 0;
   Cards = DataFiles::GetCreditCardList();
   Getting = Cards[pointer];
   PossibleCard = Getting + 1;
   while (PossibleCard < 9999999)
   {
      PossibleCard++;
   }
   while (!ValidatingCard(PossibleCard))
   {
      PossibleCard++;
   }
   Cards[pointer] = PossibleCard;
   DataFiles::InsertCreditCardonList(Cards);
   return PossibleCard;
}


int Executive::ProvideandDeleteCard(int index)
{
   vector<int> Cards;
   int oldcard;
   int newcard;
   int reference;
   Cards = DataFiles::GetDebitCardList();
   oldcard = Cards[index];
   cout << "\n\n\nReplacing Card number: " << oldcard;
   reference = Cards[Cards.size() - 1];
   newcard = reference + 1;
   while (!ValidatingCard(newcard))
   {
      newcard++;
   }
   replace(Cards.begin(), Cards.end(), oldcard, newcard);
   DataFiles::InsertCardonList(Cards);
   return newcard;
}

int Executive::ProvideandDeleteCreditCard(int index)
{
   vector<int> Cards;
   int oldcard;
   int newcard;
   Cards = DataFiles::GetCreditCardList();
   oldcard = Cards[index];
   cout << "\n\n\nReplacing Card number: " << oldcard;
   newcard = oldcard + 1;
   while (newcard < 9999999)
   {
      newcard++;
   }
   while (!ValidatingCard(newcard))
   {
      newcard++;
   }
   Cards[index] = newcard;
   DataFiles::InsertCreditCardonList(Cards);
   return newcard;
}


bool Executive::ValidatingCard(int NewCard) // suma = 32
{
   vector<int> Cards;
   vector<int> CreditCards;
   int numstr[8];
   int sum = 0;
   bool proceed = true;
   Cards = DataFiles::GetDebitCardList();
   CreditCards = DataFiles::GetCreditCardList();
   int size = Cards.size();
   for (int i = 0; i < (size - 1); i++)
   {
      if ((NewCard == Cards[i]) || (NewCard == CreditCards[i]))
      {
         proceed = false;
         return false;
         break;
      }
   }
   for (int i = 7; i >= 0; i--)
   {
      numstr[i] = NewCard % 10;
      NewCard /= 10;
   }
   for (int i = 7; i >= 0; i--)
   {
      int n;
      n = numstr[i];
      if ((i % 2) == 0)
      {
         n = n * 2;
         if (n >= 10)
         {
            n = n - 9;
         }
      }
      sum = sum + n;
   }
   if (sum == 32 && proceed == true)
   {
      return true;
   }
   return false;
}


void Executive::LoanProcess(int pointer)
{
   vector<int> Loans;
   int NewLoan = 0;
   Loans = DataFiles::GetLoansList();
   cout << "\nEnter requested ammount" << endl;
   cin >> NewLoan;
   Loans[pointer] = Loans[pointer] + NewLoan;
   DataFiles::InsertLoansList(Loans);
}


bool Executive::CreditAccept(int pointer)
{
   bool rejected = false;
   vector<int> Loans;
   vector<int> Money;
   Loans = DataFiles::GetLoansList();
   Money = DataFiles::GetMoneyList();
   if ((Loans[pointer] > 3000) || (Money[pointer] < 5000))
   {
      rejected = true;
   }
   return rejected;
}

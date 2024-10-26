#pragma once
#include "stdafx.h"
#include <string>
#include <vector>
using namespace std;


namespace DataFiles
{
   extern vector<string> GetClientList();
   extern vector<int> GetIDClient();
   extern void InsertID(vector<int> IdsArr);
   extern void InsertClient(string name, string lastname);
   extern vector<int> GetMoneyList();
   extern void InsertMoney(int money);
   extern vector<int> GetDebitCardList();
   extern vector<int> GetCreditCardList();
   extern void InsertCardonList(vector<int> Listofcards);
   extern void InsertCreditCardonList(vector<int> Listofcards);
   extern vector<int> GetLoansList();
   extern void InsertLoansList(vector<int> Loans);
   extern void InsertMoneylist(vector<int> Money);
};
#pragma once
#include "stdafx.h"
#include <string>
using namespace std;


class Clients_Class
{
public:
   Clients_Class();
   ~Clients_Class();
   bool Search_Client_Name(string name, string lastname);
   int Clientnametogetarray(string name, string lastname);
   int Search_Client_ID(int ID);
   string Search_Client_With_ID(int ID);
   int Generate_ID();
   void Retiremoney(int pointer);
   void CheckBalance(int pointer);
   int Deposit(int pointer);
   void PayLoan(int pointer);
   bool transfer(int from, int to);
};

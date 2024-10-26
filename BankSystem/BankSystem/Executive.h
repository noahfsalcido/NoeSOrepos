#pragma once
#include "stdafx.h"
using namespace std;


class Executive
{
public:
   Executive();
   ~Executive();
   bool Search_ID(int ID);
   void OpenAccount();
   void NewCard();
   int ProvideCard();
   int ProvideCreditCard(int pointer);
   int ProvideandDeleteCard(int index);
   int ProvideandDeleteCreditCard(int index);
   bool ValidatingCard(int NewCard);
   void LoanProcess(int pointer);
   bool CreditAccept(int pointer);

};
// Application1.cpp : Defines the entry point for the console application.
//

#include "BankSystem.h"
#include "stdafx.h"
#include "math.h"



int EmployeesIDs[] = { 12346, 13876, 19829 };
int CliendIDs[] = { 99593, 93124, 91245 };

void MenuAccess()
{
   
   int ID = NULL;
   int Option = 0;
   printf("Enter your case");
   scanf("%d", &Option);
   switch (Option)
   {
      int failcount = 0;
      case 1://Executive
      {
         while (failcount < 3)
         {
            printf("Enter your employee ID");
            scanf("%d", &ID);
            if (SearchID(ID))
            {
               bool accept = true;
               //TODO
            }
            else
            {
               printf("ID not found");
               failcount++;
            }
         }

         //TODO
         break;
      }
      case 2://Teller
      {
         //TODO
         break;
      }
      case 3://ATM
      {
         //TODO
         break;
      }
      case 4://HR
      {
         //TODO
         break;
      }
   }
}

bool SearchID(int ID)
{
   for (int ite = 0; ite < sizeof(EmployeesIDs); ite++)
   {
      if (ID == EmployeesIDs[ite])
      {
         return true;
         break;
      }
      else
      {
         return false;
      }
   }
}
//switch (c)
//{
//case 1://Open account
//{
//   break
//}
//case 2://Request a new card
//{
//   break
//}
//case 3://Loan
//{
//   break
//}


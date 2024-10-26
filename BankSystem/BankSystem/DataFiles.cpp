#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string>
#include <fstream>
#include "DataFiles.h"

namespace DataFiles
{
   vector<string> GetClientList()
   {
      string line;
      vector<string> v;
      bool Found = false;
      std::ifstream ifile("ClientsDataBase.txt");
      std::stringstream buff;
      buff << ifile.rdbuf();
      std::string test = buff.str();
      for (auto n : test)
      {
         if (n != '\n') line += n; else
            if (n == '\n' && line != "")
            {
               v.push_back(line);
               line = "";
            }
      }
      if (line != "") v.push_back(line);
      return v;
   }


   vector<int> GetIDClient()
   {
      string line;
      vector<string> v;
      vector<int> IDClientArray;
      std::ifstream ifile("IDClientDataBase.txt");
      std::stringstream buff;
      buff << ifile.rdbuf();
      std::string test = buff.str();
      for (auto n : test)
      {
         if (n != '\n') line += n; else
            if (n == '\n' && line != "")
            {
               v.push_back(line);
               line = "";
            }
      }
      if (line != "") v.push_back(line);
      int sizeref = v.size();
      for (int i = 0; i <= (sizeref - 1); i++)
      {
         int num = atoi(v.at(i).c_str());
         IDClientArray.push_back(num);
      }
      return IDClientArray;
   }


   void InsertID(vector<int> IdsArr)
   {
      std::ofstream ofile("IDClientDataBase.txt");
      if (ofile.is_open())
      {
         int sizeref = IdsArr.size();
         for(int i = 0; i < sizeref; i++)
         { 
            ofile << IdsArr[i] << endl;
         }
         ofile.close();
      }
      else
      {
         cout << "Can't reach database for ID's";
      }
   }


   void InsertClient(string name, string lastname)
   {
      string completename = name + " " + lastname;
      vector<string> Clients = DataFiles::GetClientList();
      Clients.push_back(completename);
      std::ofstream ofile("ClientsDataBase.txt");
      if (ofile.is_open())
      {
         int sizeref = Clients.size();
         for (int i = 0; i < sizeref; i++)
         {
            ofile << Clients[i] << endl;
         }
         ofile.close();
      }
      else
      {
         cout << "Can't reach database for Clients Name";
      }
   }


   vector<int> GetMoneyList()
   {
      string line;
      vector<string> v;
      vector<int> MoneyArray;
      std::ifstream ifile("MoneyDataBase.txt");
      std::stringstream buff;
      buff << ifile.rdbuf();
      std::string test = buff.str();
      for (auto n : test)
      {
         if (n != '\n') line += n; else
            if (n == '\n' && line != "")
            {
               v.push_back(line);
               line = "";
            }
      }
      if (line != "") v.push_back(line);
      int sizeref = v.size();
      for (int i = 0; i <= (sizeref - 1); i++)
      {
         int num = atoi(v.at(i).c_str());
         MoneyArray.push_back(num);
      }
      return MoneyArray;
   }


   void InsertMoney(int money)
   {
      vector<int> MoneyArray;
      MoneyArray = DataFiles::GetMoneyList();
      MoneyArray.push_back(money);
      std::ofstream ofile("MoneyDataBase.txt");
      if (ofile.is_open())
      {
         int sizeref = MoneyArray.size();
         for (int i = 0; i < sizeref; i++)
         {
            ofile << MoneyArray[i] << endl;
         }
         ofile.close();
      }
      else
      {
         cout << "Can't reach database for Clients Name";
      }
   }


   vector<int> GetDebitCardList()
   {
      string line;
      vector<string> v;
      vector<int> CardArray;
      std::ifstream ifile("DebitCardDataBase.txt");
      std::stringstream buff;
      buff << ifile.rdbuf();
      std::string test = buff.str();
      for (auto n : test)
      {
         if (n != '\n') line += n; else
            if (n == '\n' && line != "")
            {
               v.push_back(line);
               line = "";
            }
      }
      if (line != "") v.push_back(line);
      int sizeref = v.size();
      for (int i = 0; i <= (sizeref - 1); i++)
      {
         int num = atoi(v.at(i).c_str());
         CardArray.push_back(num);
      }
      return CardArray;
   }


   vector<int> GetCreditCardList()
   {
      string line;
      vector<string> v;
      vector<int> CardArray;
      std::ifstream ifile("CreditCardDataBase.txt");
      std::stringstream buff;
      buff << ifile.rdbuf();
      std::string test = buff.str();
      for (auto n : test)
      {
         if (n != '\n') line += n; else
            if (n == '\n' && line != "")
            {
               v.push_back(line);
               line = "";
            }
      }
      if (line != "") v.push_back(line);
      int sizeref = v.size();
      for (int i = 0; i <= (sizeref - 1); i++)
      {
         int num = atoi(v.at(i).c_str());
         CardArray.push_back(num);
      }
      return CardArray;
   }


   void InsertCardonList(vector<int> Listofcards)
   {
      std::ofstream ofile("DebitCardDataBase.txt");
      if (ofile.is_open())
      {
         int sizeref = Listofcards.size();
         for (int i = 0; i < sizeref; i++)
         {
            ofile << Listofcards[i] << endl;
         }
         ofile.close();
      }
      else
      {
         cout << "Can't reach database for Clients Name";
      }
   }

   void InsertCreditCardonList(vector<int> Listofcards)
   {
      std::ofstream ofile("CreditCardDataBase.txt");
      if (ofile.is_open())
      {
         int sizeref = Listofcards.size();
         for (int i = 0; i < sizeref; i++)
         {
            ofile << Listofcards[i] << endl;
         }
         ofile.close();
      }
      else
      {
         cout << "Can't reach database for Clients Name";
      }
   }


   vector<int> GetLoansList()
   {
      string line;
      vector<string> v;
      vector<int> LoansArray;
      std::ifstream ifile("Loans.txt");
      std::stringstream buff;
      buff << ifile.rdbuf();
      std::string test = buff.str();
      for (auto n : test)
      {
         if (n != '\n') line += n; else
            if (n == '\n' && line != "")
            {
               v.push_back(line);
               line = "";
            }
      }
      if (line != "") v.push_back(line);
      int sizeref = v.size();
      for (int i = 0; i <= (sizeref - 1); i++)
      {
         int num = atoi(v.at(i).c_str());
         LoansArray.push_back(num);
      }
      return LoansArray;
   }


   void InsertLoansList(vector<int> Loans)
   {
      std::ofstream ofile("Loans.txt");
      if (ofile.is_open())
      {
         int sizeref = Loans.size();
         for (int i = 0; i < sizeref; i++)
         {
            ofile << Loans[i] << endl;
         }
         ofile.close();
      }
      else
      {
         cout << "Can't reach database for Clients Name";
      }
   }


   void InsertMoneylist(vector<int> Money)
   {
      std::ofstream ofile("MoneyDataBase.txt");
      if (ofile.is_open())
      {
         int sizeref = Money.size();
         for (int i = 0; i < sizeref; i++)
         {
            ofile << Money[i] << endl;
         }
         ofile.close();
      }
      else
      {
         cout << "Can't reach database for Clients Name";
      }
   }
}

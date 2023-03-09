//***************************************************************************
// File name:   main.cpp
// Author:      Cayden Wagner
// Date:        March 8, 2023
// Class:       AOO - CS485
// Assignment:  Bank
// Purpose:     Practice my Object Oriented Design Skills. Practice my UML
//              design skills. Practice new C++ syntax and idioms.
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include <memory>

#include "Bank.h"
#include "FileAccountReader.h"


//***************************************************************************
// Function:    main
//
// Description: Initializes a Bank object and starts the Bank Operations
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main()
{
  const std::string ACCOUNTS_FILE = "data/Accounts.txt";

  std::shared_ptr<IAccountReader> cReader(new FileAccountReader(ACCOUNTS_FILE));
  Bank* cTheBank(new Bank(cReader));

  cTheBank->printAll();
  cTheBank->updateMonth();
  cTheBank->printAll();
  cTheBank->withdraw(1, 10);
  cTheBank->withdraw(2, 10);
  cTheBank->printAll();
  cTheBank->deposit(1, 10);
  cTheBank->deposit(2, 10);
  cTheBank->printAll();
  cTheBank->withdraw(2, 960);
  cTheBank->printAll();
  cTheBank->withdraw(1, 900);
  cTheBank->printAll();
  cTheBank->updateMonth();
  cTheBank->printAll();
  cTheBank->updateMonth();
  cTheBank->printAll();

  return EXIT_SUCCESS;
}

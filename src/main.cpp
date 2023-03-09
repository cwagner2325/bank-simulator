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
#include "IAccountReader.h"
#include "FileAccountReader.h"
#include "ICommandReader.h"
#include "FileCommandReader.h"

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
  const std::string COMMANDS_FILE = "data/Commands.txt";

  std::shared_ptr<IAccountReader> pcAccountReader(new FileAccountReader(ACCOUNTS_FILE));
  std::shared_ptr<ICommandReader> pcCommandReader(new FileCommandReader(COMMANDS_FILE));
  std::shared_ptr<Bank> pcTheBank(new Bank(pcAccountReader));
  

  // pcTheBank->printAll();
  // pcTheBank->updateMonth();
  // pcTheBank->printAll();
  // pcTheBank->withdraw(1, 10);
  // pcTheBank->withdraw(2, 10);
  // pcTheBank->printAll();
  // pcTheBank->deposit(1, 10);
  // pcTheBank->deposit(2, 10);
  // pcTheBank->printAll();
  // pcTheBank->withdraw(2, 960);
  // pcTheBank->printAll();
  // pcTheBank->withdraw(1, 900);
  // pcTheBank->printAll();
  // pcTheBank->updateMonth();
  // pcTheBank->printAll();
  // pcTheBank->updateMonth();
  // pcTheBank->printAll();

  return EXIT_SUCCESS;
}

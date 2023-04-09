//********************************************************
// File name:  Bank.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the Bank
//********************************************************

#include <memory>
#include <vector>
#include <exception>

#include "IAccountReader.h"
#include "IBankAccount.h"
#include "Bank.h"

//***************************************************************************
// Constructor:    Bank
//
// Description:    Reads in all accounts from the account reader and stores 
//                 them in its member variable mapcAccount
//
// Parameters:     rcReader - a reference to an account reader
//***************************************************************************
Bank::Bank(std::shared_ptr<IAccountReader> pcReader,
           std::shared_ptr<IAccountContainer> pcContainer)
{
  std::shared_ptr<IBankAccount> pcAccount;

  mapcAccounts = pcContainer;
  
  while (nullptr != (pcAccount = pcReader->readNext()))
  {
    mapcAccounts->insert(pcAccount);
  }
}

//***************************************************************************
// Destructor:    Bank
//
// Description:   the destructor for the Bank class
//***************************************************************************
Bank::~Bank() {}

//***************************************************************************
// Function:    executeCommands
//
// Description: executes a set of commands
//
// Parameters:  acCommands - a reference to a vector containing commands
//
// Returned:    none
//***************************************************************************
void Bank::executeCommands(std::vector<std::shared_ptr<ICommand>> acCommands)
{
  for (int i = 0; i < static_cast<int> (acCommands.size()); i++) 
  {
    try 
    {
      acCommands.at(i)->execute();
    }
    catch (std::out_of_range& err)
    {
      std::cout << std::endl << "Bank::executeCommands failed: " << err.what()
                << std::endl << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

//***************************************************************************
// Function:    printAll
//
// Description: prints all the accounts in the vector to the terminal
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void Bank::printAll()
{
  const int NUM_CHARS = 13;
  const char BORDER_CHAR = '-';

  std::shared_ptr<IBankAccount> pcAccount;

  for (int i = 0; i < NUM_CHARS; i++) 
  {
    std::cout << BORDER_CHAR;
  }

  std::cout << std::endl;

  while (nullptr != (pcAccount = mapcAccounts->getNext()))
  {
    std::cout << *pcAccount << std::endl;
  }

  for (int i = 0; i < NUM_CHARS; i++) 
  {
    std::cout << BORDER_CHAR;
  }

  std::cout << std::endl;
}

//***************************************************************************
// Function:    updateMonth
//
// Description: iterates through the vector and calls updateMonth on each account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void Bank::updateMonth()
{
  std::shared_ptr<IBankAccount> pcAccount;

  while (nullptr != (pcAccount = mapcAccounts->getNext()))
  {
    pcAccount->updateMonth();
  }
}

//***************************************************************************
// Function:    deposit
//
// Description: finds an account based on an account number and deposits an
//              amount if the account is found
//
// Parameters:  accountNumber - the key of an account that is searched for
//              depositAmount - the amount deposited into the found account
//
// Returned:    none
//***************************************************************************
void Bank::deposit(int accountNumber, const Money& depositAmount)
{
  try 
  {
    std::shared_ptr<IBankAccount> pcAccount = mapcAccounts->find(accountNumber);
    pcAccount->deposit(depositAmount);
  }
  catch (std::out_of_range& err)
  {
    throw err;
  }
}

//***************************************************************************
// Function:    withdraw
//
// Description: finds an account based on an account number and withdraws an
//              amount if the account is found
//
// Parameters:  accountNumber  - the key of an account that is searched for
//              withdrawAmount - the amount withdrawn from the found account
//
// Returned:    none
//***************************************************************************
void Bank::withdraw(int accountNumber, const Money& withdrawAmount)
{
  try 
  {
    std::shared_ptr<IBankAccount> pcAccount = mapcAccounts->find(accountNumber);
    pcAccount->withdraw(withdrawAmount);
  }
  catch (std::out_of_range& err)
  {
    throw err;
  }
}
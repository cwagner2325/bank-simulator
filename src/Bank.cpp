//********************************************************
// File name:  Bank.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the Bank
//********************************************************

#include "memory"
#include "vector"

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
Bank::Bank(std::shared_ptr<IAccountReader>& rcReader)
{
  rcReader->readAll(mapcAccounts);
}

//***************************************************************************
// Destructor:    Bank
//
// Description:   the destructor for the Bank class
//***************************************************************************
Bank::~Bank() {}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
// void Bank::doBankOperations(std::shared_ptr<ICommandReader>& rcReader)
// {
//   std::vector<std::shared_ptr<ICommand>> acCommands;

//   rcReader->readAll(acCommands);

//   for (int i = 0; i < static_cast<int> (acCommands.size()); i++) 
//   {
//     //acCommands.at(i)->execute(this);
//   }
// }
//***************************************************************************
// Function:    findAccount
//
// Description: finds an account in the account vector based on an account number
//
// Parameters:  key - the account number that is searched for
//
// Returned:    a shared pointer to the account if found, else nullptr
//***************************************************************************
std::shared_ptr<IBankAccount> Bank::findAccount(int key)
{
  for (int i = 0; i < static_cast<int> (mapcAccounts.size()); i++)
  {
    if (mapcAccounts.at(i)->equals(key))
    {
      return mapcAccounts.at(i);
    }
  }
  return nullptr;
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

  for (int i = 0; i < NUM_CHARS; i++) 
  {
    std::cout << BORDER_CHAR;
  }

  std::cout << std::endl;

  for (int i = 0; i < static_cast<int> (mapcAccounts.size()); i++)
  {
   std::cout << *mapcAccounts.at(i) << std::endl;
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
  for (int i = 0; i < static_cast<int> (mapcAccounts.size()); i++)
  {
    mapcAccounts.at(i)->updateMonth();
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
void Bank::deposit(int accountNumber, long long depositAmount)
{
  std::shared_ptr<IBankAccount> pcAccount = findAccount(accountNumber);

  if (nullptr != pcAccount)
  {
    pcAccount->deposit(depositAmount);
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
void Bank::withdraw(int accountNumber, long long withdrawAmount)
{
  std::shared_ptr<IBankAccount> pcAccount = findAccount(accountNumber);

  if (nullptr != pcAccount)
  {
    pcAccount->withdraw(withdrawAmount);
  }
}
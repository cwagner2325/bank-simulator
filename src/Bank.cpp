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
// Constructor:    
//
// Description: 
//
// Parameters:  
//***************************************************************************
Bank::Bank(std::shared_ptr<IAccountReader>& rcReader)
{
  rcReader->readAll(mapcAccounts);
}

//***************************************************************************
// Destructor:    
//
// Description: 
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
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
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
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void Bank::updateMonth()
{
  for (int i = 0; i < static_cast<int> (mapcAccounts.size()); i++)
  {
    mapcAccounts.at(i)->updateMonth();
  }
}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
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
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void Bank::withdraw(int accountNumber, long long withdrawAmount)
{
  std::shared_ptr<IBankAccount> pcAccount = findAccount(accountNumber);

  if (nullptr != pcAccount)
  {
    pcAccount->withdraw(withdrawAmount);
  }
}
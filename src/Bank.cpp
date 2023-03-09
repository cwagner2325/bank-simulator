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
Bank::Bank(IAccountReader& rcReader)
{
  rcReader.readAll(mapcAccounts);
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
  for (int i = 0; i < static_cast<int> (mapcAccounts.size()); i++)
  {
    std::cout << mapcAccounts.at(i)->toString() << std::endl;
  }
}

// virtual void updateMonth();

// virtual void deposit(int, long long);
// virtual void withdraw(int, long long);
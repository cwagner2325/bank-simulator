//********************************************************
// File name:  CheckingAccount.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the CheckingAccount 
//********************************************************

#include <string>
#include "IBankAccount.h"
#include "CheckingAccount.h"

//***************************************************************************
// Constructor:    
//
// Description: 
//
// Parameters:  
//***************************************************************************
CheckingAccount::CheckingAccount(int accNumber, long long balance, double intRate, long long minBalance, long long minBalanceFee) : IBankAccount(accNumber, balance, intRate)
{
  mMinBalance = minBalance;
  mMinBalanceFee = minBalanceFee;
}

//***************************************************************************
// Destructor:    
//
// Description: 
//***************************************************************************
CheckingAccount::~CheckingAccount() {}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void CheckingAccount::deposit(long long depositAmount)
{
  IBankAccount::deposit(depositAmount);

  if (isBelow(mMinBalance)) 
  {
    IBankAccount::withdraw(mMinBalanceFee);
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
void CheckingAccount::withdraw(long long withdrawAmount)
{
  IBankAccount::withdraw(withdrawAmount);

  if (isBelow(mMinBalance)) 
  {
    IBankAccount::withdraw(mMinBalanceFee);
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
void CheckingAccount::updateMonth()
{
  addInterest();
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
std::string CheckingAccount::toString() const
{
  return IBankAccount::toString() + ", " + std::to_string(mMinBalance) + 
         ", " + std::to_string(mMinBalanceFee);
}
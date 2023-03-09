//********************************************************
// File name:  IBankAccount.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    Implementation for IBankAccount
//********************************************************

#include "IBankAccount.h"
#include <string>
#include <iostream>

//***************************************************************************
// Constructor:    
//
// Description: 
//
// Parameters:  
//***************************************************************************
IBankAccount::IBankAccount(int accountNumber, long long balance, double interestRate)
{
  mAccountNumber = accountNumber;
  mBalance = balance;
  mInterestRate = interestRate;
}

//***************************************************************************
// Destructor:    
//
// Description: 
//***************************************************************************
IBankAccount::~IBankAccount() {}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void IBankAccount::deposit(long long depositAmount)
{
  mBalance += depositAmount;
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
void IBankAccount::withdraw(long long withdrawAmount)
{
  mBalance -= withdrawAmount;
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
std::string IBankAccount::toString() const
{
  return mAccountNumber + ", $" + std::to_string(mBalance) + ", " +
         std::to_string(mInterestRate) + "%";
}

bool IBankAccount::equals(int otherAccount)
{
  return mAccountNumber == otherAccount;
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
std::ostream& operator<<(std::ostream& rcOut, const IBankAccount& rcAccount)
{
  rcOut << rcAccount.toString();

  return rcOut;
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
bool IBankAccount::isBelow(long long amount)
{
  return mBalance < amount;
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
void IBankAccount::addInterest()
{
  if (!isBelow(0))
  {
    mBalance += mBalance * mInterestRate;
  }
}
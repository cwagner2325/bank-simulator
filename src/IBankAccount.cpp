//********************************************************
// File name:  IBankAccount.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    Implementation for IBankAccount
//********************************************************

#include <string>
#include <iostream>
#include <iomanip>

#include "IBankAccount.h"


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
std::ostream& IBankAccount::print(std::ostream& rcOut) const
{
  const double DECIMAL = 100;

  rcOut << mAccountNumber << ", $" << std::fixed << std::setprecision(2) 
        << mBalance / DECIMAL << ", " << (mInterestRate * DECIMAL) << "%";

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
  rcAccount.print(rcOut);

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
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
#include <memory>
#include <math.h>

#include "IBankAccount.h"


//***************************************************************************
// Constructor:    IBankAccount
//
// Description:    Initalizes a IBankAccount object by setting member variables
//
// Parameters:     accountNumber - the account number for the new bank account
//                 balance       - the inital balance for the new account
//                 interestRate  - the interest rate for the new account
//***************************************************************************
IBankAccount::IBankAccount() {};

//***************************************************************************
// Destructor:    IBankAccount
//
// Description:   Destructor for IBankAccount
//***************************************************************************
IBankAccount::~IBankAccount() {};

//***************************************************************************
// Function:      deposit
//
// Description:   Adds a deposit amount to the account balance
//
// Parameters:    depositAmount - the amount added to the account balance
//
// Returned:      none
//***************************************************************************
void IBankAccount::deposit(long long depositAmount)
{
  mBalance += std::trunc(depositAmount);
}

//***************************************************************************
// Function:      withdraw
//
// Description:   Subtracts a withdraw amount from the account balance
//
// Parameters:    withdrawAmount - the amount subtracted from the account balance
//
// Returned:      none
//***************************************************************************
void IBankAccount::withdraw(long long withdrawAmount)
{
  mBalance -= std::trunc(withdrawAmount);
}
//***************************************************************************
// Function:    primt
//
// Description: prints the account information to a stream
//
// Parameters:  rcOut - the stream to which the information is printed
//
// Returned:    a reference to the ostream object to allow chaining
//***************************************************************************
std::ostream& IBankAccount::print(std::ostream& rcOut) const
{
  const double DECIMAL = 100;

  rcOut << mAccountNumber << ", $" << std::fixed << std::setprecision(2) 
        << mBalance / DECIMAL << ", " << (mInterestRate * DECIMAL) << "%";

  return rcOut;
}

//***************************************************************************
// Function:    equals
//
// Description: determines if an an integer matches the account number
//
// Parameters:  otherAccount - an integer that is checked for equality
//
// Returned:    true if there is a match, else false
//***************************************************************************
bool IBankAccount::equals(int otherAccount)
{
  return mAccountNumber == otherAccount;
}

//***************************************************************************
// Operator:    <<
//
// Description: Calls print polymorhpically on a base IBankAccount object
//
// Parameters:  rcOut     - the stream to which the account is printed
//              rcAccount - the account that is printed
//
// Returned:    a reference to the ostream object to allow chaining
//***************************************************************************
std::ostream& operator<<(std::ostream& rcOut, const IBankAccount& rcAccount)
{
  return rcAccount.print(rcOut);
}

//***************************************************************************
// Function:    isBelow
//
// Description: determines if the account balance is below a given amount
//
// Parameters:  amount - the amount that is compared against
//
// Returned:    true if the account balance is below the argument, else false
//***************************************************************************
bool IBankAccount::isBelow(long long amount)
{
  return mBalance < amount;
}

//***************************************************************************
// Function:    addInterest
//
// Description: adds interest to an account if that account has a positive balance
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void IBankAccount::addInterest()
{
  if (!isBelow(0))
  {
    mBalance += std::trunc(mBalance * mInterestRate);
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
std::istream& IBankAccount::read(std::istream& rcIn)
{
  rcIn >> mAccountNumber >> mBalance >> mInterestRate;
  return rcIn;
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
std::istream& operator>>(std::istream& rcIn, std::shared_ptr<IBankAccount> pcBank)
{
  return pcBank->read(rcIn);
}
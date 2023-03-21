//********************************************************
// File name:  SavingsAccount.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement SavingsAccount 
//********************************************************

#include "IBankAccount.h"
#include "SavingsAccount.h"
#include "Money.h"

//***************************************************************************
// Constructor:     SavingsAccount
//
// Description:     Constructor for Savings Account
//
// Parameters:      None
//***************************************************************************
SavingsAccount::SavingsAccount() {};

//***************************************************************************
// Destructor:    SavingsAccount
//
// Description:   Destructor for the SavingsAccount class
//***************************************************************************
SavingsAccount::~SavingsAccount() {};

//***************************************************************************
// Function:    withdraw
//
// Description: Subtracts the withdrawAmount from the balance then checks to 
//              make sure the current balance is not below the minimumBalance
//
// Parameters:  withdrawAmount - the amount subtracted from the account balance
//
// Returned:    none
//***************************************************************************
void SavingsAccount::withdraw(Money withdrawAmount)
{
  IBankAccount::withdraw(withdrawAmount);

  if (isBelow(mMinMonthlyBalance))
  {
    mbMonthlyFeeReached = true;
  }
}

//***************************************************************************
// Function:    updateMonth
//
// Description: checks if a fee has incurred for the month then adds interest
//              to the account by calling the super class function. Lastly, 
//              checks if the account remains below the minimum balance
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void SavingsAccount::updateMonth()
{
  if (mbMonthlyFeeReached) 
  {
    IBankAccount::withdraw(mMonthlyFee);
  }

  addInterest();

  mbMonthlyFeeReached = isBelow(mMinMonthlyBalance);
}

//***************************************************************************
// Function:    print
//
// Description: prints the account information to a stream
//
// Parameters:  rcOut - the stream to where the information is printed
//
// Returned:    a reference to the ostream object for chaining
//***************************************************************************
std::ostream& SavingsAccount::print(std::ostream& rcOut) const
{
  IBankAccount::print(rcOut);
  rcOut << ", " << mMonthlyFee << ", " << mMinMonthlyBalance;

  return rcOut;
}

//***************************************************************************
// Function:    read
//
// Description: reads in a savings account object from a stream
//
// Parameters:  rcIn - the stream that is read from
//
// Returned:    a reference to the stream
//***************************************************************************
std::istream& SavingsAccount::read(std::istream& rcIn)
{
  IBankAccount::read(rcIn);
  rcIn >> mMonthlyFee >> mMinMonthlyBalance;
  return rcIn;
}
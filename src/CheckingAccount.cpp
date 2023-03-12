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
// Constructor:    CheckingAccount
//
// Description:     Calls the super class constructor and then sets its own 
//                  mebmber variables to initalize a checking account object
//
// Parameters:      accNumber     - The account number of the new account
//                  balance       - The initial balance of the new account
//                  intRate       - The interest rate of the new account
//                  minBalance    - The minimum balance of the account before 
//                                  a fee incurs
//                  minBalanceFee - The fee charged if the minimum is reached
//***************************************************************************
CheckingAccount::CheckingAccount(int accNumber, long long balance, double intRate,
                                 long long minBalance, long long minBalanceFee)
                                  : IBankAccount(accNumber, balance, intRate)
{
  mMinBalance = minBalance;
  mMinBalanceFee = minBalanceFee;
}

//***************************************************************************
// Destructor:    CheckingAccount
//
// Description:   Destructor for the CheckingAccount class
//***************************************************************************
CheckingAccount::~CheckingAccount() {}

//***************************************************************************
// Function:    deposit
//
// Description: Adds the depositAmount to the balance then checks to make sure
//              the current balance is not below the minimumBalance
//
// Parameters:  depositAmount - the amount added to the account balance
//
// Returned:    none
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
// Function:    withdraw
//
// Description: Subtracts the withdrawAmount from the balance then checks to 
//              make sure the current balance is not below the minimumBalance
//
// Parameters:  withdrawAmount - the amount subtracted from the account balance
//
// Returned:    none
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
// Function:    updateMonth
//
// Description: adds interest to the account by calling the super class function
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void CheckingAccount::updateMonth()
{
  addInterest();
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
std::ostream& CheckingAccount::print(std::ostream& rcOut) const
{
  IBankAccount::print(rcOut);
  rcOut << ", " << mMinBalance << ", " << mMinBalanceFee;

  return rcOut;
}
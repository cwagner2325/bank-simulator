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

//***************************************************************************
// Constructor:    
//
// Description: 
//
// Parameters:  
//***************************************************************************
SavingsAccount::SavingsAccount(int accNumber, long long balance, double intRate,
                long long monthlyFee, double minMonthly) : 
                IBankAccount(accNumber, balance, intRate)
{
  mMonthlyFee = monthlyFee;
  mMinMonthlyBalance = minMonthly;
  mMonthlyFeeReached = false;
}

//***************************************************************************
// Destructor:    
//
// Description: 
//***************************************************************************
SavingsAccount::~SavingsAccount() {};

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void SavingsAccount::withdraw(long long withdrawAmount)
{
  IBankAccount::withdraw(withdrawAmount);

  if (mBalance < mMinMonthlyBalance) 
  {
    mMonthlyFee = true;
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
void SavingsAccount::updateMonth()
{
  if (mMonthlyFee) 
  {
    mBalance -= mMonthlyFee;
  }

  if (mBalance > 0) 
  {
    mBalance += mBalance * mInterestRate;
  }

  mMonthlyFee = mBalance < mMinMonthlyBalance;
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
std::string SavingsAccount::toString() const
{
  return IBankAccount::toString() + ", " + std::to_string(mMonthlyFee) + 
         ", " + std::to_string(mMinMonthlyBalance);
}
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
                long long monthlyFee, long long minMonthly) : 
                IBankAccount(accNumber, balance, intRate)
{
  mMonthlyFee = monthlyFee;
  mMinMonthlyBalance = minMonthly;
  mbMonthlyFeeReached = false;
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

  if (isBelow(mMinMonthlyBalance))
  {
    mbMonthlyFeeReached = true;
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
  if (mbMonthlyFeeReached) 
  {
    IBankAccount::withdraw(mMonthlyFee);
  }

  addInterest();

  mbMonthlyFeeReached = isBelow(mMinMonthlyBalance);
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
std::ostream& SavingsAccount::print(std::ostream& rcOut) const
{
  IBankAccount::print(rcOut);
  rcOut << ", " << mMonthlyFee << ", " << mMinMonthlyBalance;
  
  return rcOut;
}
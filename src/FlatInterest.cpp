//********************************************************
// File name:  FlatInterest.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the TieredInterest
//********************************************************

#include "memory"
#include "vector"

#include "FlatInterest.h"
#include "Money.h"

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    none
//***************************************************************************
Money FlatInterest::calculateInterest(const Money& rcMoney)
{
  if (rcMoney > 0) 
  {
    return rcMoney * mInterestRate;
  }

  return 0;
}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    none
//***************************************************************************
std::istream& FlatInterest::read(std::istream& rcIn)
{
  rcIn >> mInterestRate;

  return rcIn;
}
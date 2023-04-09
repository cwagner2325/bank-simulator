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
// Function:    calculateInterest
//
// Description: calculates interest on the Money object passed in
//
// Parameters:  rcMoney - the money that interest is calculated on
//
// Returned:    A money object representing how much interest is generated
//***************************************************************************
Money FlatInterest::calculateInterest(const Money& rcMoney)
{
  if (rcMoney > Money(0, rcMoney.getCurrency())) 
  {
    return rcMoney * mInterestRate;
  }

  return Money(0, rcMoney.getCurrency());
}

//***************************************************************************
// Function:    read
//
// Description: reads in a tiered interest object from a stream
//
// Parameters:  rcIn - the stream from which an object is read
//
// Returned:    a reference to the stream
//***************************************************************************
std::istream& FlatInterest::read(std::istream& rcIn)
{
  rcIn >> mInterestRate;

  return rcIn;
}

//***************************************************************************
// Function:    print
//
// Description: prints a tiered interest object to a stream
//
// Parameters:  rcOut - the stream to which it is printed
//
// Returned:    a reference to a stream
//***************************************************************************
std::ostream& FlatInterest::print(std::ostream& rcOut) const
{
  const char FLAT_IDENT = 'F';
  const int DECIMAL = 100;

  rcOut << FLAT_IDENT << ' ' << mInterestRate * DECIMAL << '%'; 

  return rcOut;
}
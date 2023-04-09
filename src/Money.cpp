//********************************************************
// File name:  Money.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement Money 
//********************************************************

#include <iostream>
#include <iomanip>

#include "Money.h"

//***************************************************************************
// Constructor:    Money
//
// Description:    Initializes mAmount to default value of 0
//
// Parameters:     None
//***************************************************************************
Money::Money()
{
  mAmount = 0;
}

//***************************************************************************
// Constructor: Money
//
// Description: sets mAmount to a specific value
//
// Parameters:  amount - the amount that mAmount is set to
//***************************************************************************
Money::Money(long long amount, const Currency& rcCurrency)
{
  mCurrency = rcCurrency;
  mAmount = amount;
}

//***************************************************************************
// Constructor:    Money
//
// Description:    Copy constructor for Money
//
// Parameters:     rcMoney - the money object that is copied
//***************************************************************************
Money::Money(const Money& rcMoney)
{
  mCurrency = rcMoney.mCurrency;
  mAmount = rcMoney.mAmount;
}

//***************************************************************************
// Operator:    +
//
// Description: Adds two money objects together
//
// Parameters:  rcMoney - the object that is added
//
// Returned:    a money object with the new amount
//***************************************************************************
Money Money::operator+(const Money& rcMoney) const
{
  return Money(mAmount + rcMoney.mAmount, mCurrency);
}

//***************************************************************************
// Operator:    -
//
// Description: subtracts two money objects
//
// Parameters:  rcMoney - the object that is subtracted
//
// Returned:    a money object with the new amount
//***************************************************************************
Money Money::operator-(const Money& rcMoney) const
{
  return Money(mAmount - rcMoney.mAmount, mCurrency);
}

//***************************************************************************
// Operator:    =
//
// Description: copies one money into another
//
// Parameters:  rcMoney - the object that is copied from
//
// Returned:    a money object with the new amount
//***************************************************************************
Money Money::operator=(const Money& rcMoney)
{
  mAmount = rcMoney.mAmount;

  return *this;
}

//***************************************************************************
// Operator:    >
//
// Description: comapres the value of two money objects
//
// Parameters:  rcMoney - the object that is compared
//
// Returned:    true if the first money is larger, else false
//***************************************************************************
bool Money::operator>(const Money& rcMoney) const
{
  return mAmount > rcMoney.mAmount;
}

//***************************************************************************
// Operator:    +=
//
// Description: Adds two money objects together
//
// Parameters:  rcMoney - the object that is added
//
// Returned:    void
//***************************************************************************
void Money::operator+=(const Money& rcMoney)
{
  mAmount = mAmount + rcMoney.mAmount;
}

//***************************************************************************
// Operator:    -=
//
// Description: Subtracts two money objects 
//
// Parameters:  rcMoney - the object that is subtracted
//
// Returned:    void
//***************************************************************************
void Money::operator-=(const Money& rcMoney)
{
  mAmount = mAmount - rcMoney.mAmount;
}

//***************************************************************************
// Operator:    >=
//
// Description: comapres the value of two money objects
//
// Parameters:  rcMoney - the object that is compared
//
// Returned:    true if the first money is greater than or equal, else false
//***************************************************************************
bool Money::operator>=(const Money& rcMoney) const
{
  return mAmount >= rcMoney.mAmount;
}

//***************************************************************************
// Operator:    *
//
// Description: Multiplies a money and double
//
// Parameters:  interestRate - the double that is multiplied
//
// Returned:    a money object with the new amount
//***************************************************************************
Money Money::operator*(double interestRate) const
{
  return Money(mAmount * interestRate, mCurrency);
}

//***************************************************************************
// Operator:    *=
//
// Description: Multiplies a money and double
//
// Parameters:  interestRate - the double that is multiplied
//
// Returned:    void
//***************************************************************************
void Money::operator*=(double interestRate)
{
  mAmount = mAmount + (mAmount * interestRate);
}

//***************************************************************************
// operator:    <<
//
// Description: calls print to a stream polymorphically
//
// Parameters:  rcOut   - the stream that is printed to
//              rcMoney - the money object that is printed
//
// Returned:    a reference to the stream object
//***************************************************************************
std::ostream& operator<<(std::ostream& rcOut, const Money& rcMoney)
{
  const int NUM_DECIMALS = 2;
  const double DECIMAL = 100;

  rcOut << rcMoney.mCurrency.to_string() << std::fixed 
        << std::setprecision(NUM_DECIMALS) << rcMoney.mAmount / DECIMAL;

  return rcOut;
}

//***************************************************************************
// Operator:    >>
//
// Description: reads a money object from a stream by calling read polymorphically
//
// Parameters:  rcIn    - the stream that is read from
//              rcMoney - the money object that is read
//
// Returned:    a reference to the stream
//***************************************************************************
std::istream& operator>>(std::istream& rcIn, Money& rcMoney)
{ 
  std::string cTemp;

  rcIn >> cTemp;
  rcMoney.mCurrency.from_str(cTemp);

  rcIn >> rcMoney.mAmount;

  return rcIn;
}
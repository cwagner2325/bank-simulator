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
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
Money::Money()
{
  mAmount = 0;
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
Money::Money(long long amount)
{
  mAmount = amount;
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
Money::Money(const Money& rcMoney)
{
  mAmount = rcMoney.getInUSD();
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
Money Money::operator+(const Money& rcMoney)
{
  return Money(getInUSD() + rcMoney.getInUSD());
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
Money Money::operator-(const Money& rcMoney)
{
  return Money(getInUSD() - rcMoney.getInUSD());
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
Money Money::operator=(const Money& rcMoney)
{
  return Money(rcMoney);
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
bool Money::operator>(const Money& rcMoney)
{
  return getInUSD() > rcMoney.getInUSD();
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
bool Money::operator>=(const Money& rcMoney)
{
  return getInUSD() >= rcMoney.getInUSD();
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
Money Money::operator*(double interestRate)
{
  return Money(mAmount *= interestRate);
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
long long Money::getInUSD() const
{
  return mAmount;
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
std::ostream& operator<<(std::ostream& rcOut, const Money& rcMoney)
{
  return rcMoney.print(rcOut);
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
std::ostream& Money::print(std::ostream& rcOut) const
{
  const char MONEY_PREFIX = '$';
  const int NUM_DECIMALS = 2;
  const double DECIMAL = 100;

  rcOut << MONEY_PREFIX << std::fixed << std::setprecision(NUM_DECIMALS)
        << mAmount / DECIMAL;

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
std::istream& Money::read(std::istream& rcIn)
{
  rcIn >> mAmount;
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
std::istream& operator>>(std::istream& rcIn, Money& rcMoney)
{
  rcMoney.read(rcIn);
  return rcIn;
}
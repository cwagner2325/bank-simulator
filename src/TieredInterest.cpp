//********************************************************
// File name:  TieredInterest.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the TieredInterest
//********************************************************

#include "memory"
#include "vector"
#include "iostream"

#include "TieredInterest.h"
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
Money TieredInterest::calculateInterest(const Money& rcMoney)
{
  Money cInterest = 0; 

  for (int i = macTiers.size() - 1; i >= 0; i--)
  {
    if (rcMoney > macTiers.at(i).first)
    {
      cInterest = rcMoney * macTiers.at(i).second;
      break;
    }
  }

  return cInterest;
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
std::istream& TieredInterest::read(std::istream& rcIn)
{
  int numTiers;
  Money cTempMoney;
  double tempInterest;

  rcIn >> numTiers; 

  for (int i = 0; i < numTiers; i++) 
  {
    rcIn >> cTempMoney;
    macTiers.push_back(std::make_pair(cTempMoney, 0));
  }

  for (int i = 0; i < numTiers; i++) 
  {
    rcIn >> tempInterest;
    macTiers.at(i).second = tempInterest;
  }

  return rcIn;
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
std::ostream& TieredInterest::print(std::ostream& rcOut) const
{
  const char TIERED_IDENT = 'T';
  const int DECIMAL = 100;

  rcOut << TIERED_IDENT << ' ';

  for (int i = 0; i < static_cast<int> (macTiers.size()); i++) 
  {
    rcOut << macTiers.at(i).first << ' ';
  }

  for (int i = 0; i < static_cast<int> (macTiers.size()); i++) 
  {
    rcOut << macTiers.at(i).second * DECIMAL << "% ";
  }

  return rcOut;
}
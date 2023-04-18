//********************************************************
// File name:  Conversion.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement Money 
//********************************************************

#include <iostream>

#include "Conversion.h"

// double getConversionRate() const;

//***************************************************************************
// Operator:    
//
// Description: 
//
// Parameters:  
//
// Returned:     
//***************************************************************************
Conversion::Conversion()
{

}

//***************************************************************************
// Operator:    
//
// Description: 
//
// Parameters:  
//
// Returned:     
//***************************************************************************
Conversion::Conversion(Currency cFirstCurrency, Currency cSecondCurrency, 
                       double conversionRate)
{
  mcCurrencies.first = cFirstCurrency;
  mcCurrencies.second = cSecondCurrency;
  mConversionRate = conversionRate;
}

//***************************************************************************
// Operator:    
//
// Description: 
//
// Parameters:  
//
// Returned:     
//***************************************************************************
Conversion::~Conversion() {};

//***************************************************************************
// Operator:    
//
// Description: 
//
// Parameters:  
//
// Returned:     
//***************************************************************************
std::istream& operator>>(std::istream& rcIn, Conversion& rcConversion)
{
  rcIn >> rcConversion.mcCurrencies.first >> rcConversion.mcCurrencies.second
       >> rcConversion.mConversionRate;

  return rcIn;
}

//***************************************************************************
// Operator:    
//
// Description: 
//
// Parameters:  
//
// Returned:     
//***************************************************************************
bool operator==(const Conversion& rcConversionOne, const Conversion&rcConversionTwo)
{
  return rcConversionOne.mcCurrencies == rcConversionTwo.mcCurrencies;
}
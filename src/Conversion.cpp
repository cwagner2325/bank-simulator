//********************************************************
// File name:  Conversion.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement Conversion 
//********************************************************

#include <iostream>

#include "Conversion.h"

//***************************************************************************
// Constructor:    Conversion
//
// Description:    Constructor for Conversion class
//***************************************************************************
Conversion::Conversion() {};

//***************************************************************************
// Constructor:    Conversion
//
// Description:    Initializes a Conversion object with paramters
//
// Parameters:     cFirstCurrency  - the first currency in the Conversion pair
//                 cSecondCurrency - the seconds currency in the Conversion pair
//                 conversionRate  - the conversion rate from first to second
//***************************************************************************
Conversion::Conversion(Currency cFirstCurrency, Currency cSecondCurrency, 
                       double conversionRate)
{
  mcCurrencies.first = cFirstCurrency;
  mcCurrencies.second = cSecondCurrency;
  mConversionRate = conversionRate;
}

//***************************************************************************
// Destructor:    Conversion
//
// Description:   Destructor for class Conversion
//***************************************************************************
Conversion::~Conversion() {};

//***************************************************************************
// Operator:    >>
//
// Description: reads a Conversion object from a stream
//
// Parameters:  rcIn        - the stream that the object is read from
//              rConversion - the object that is read in
//
// Returned:    a reference to the stream variable
//***************************************************************************
std::istream& operator>>(std::istream& rcIn, Conversion& rConversion)
{
  rcIn >> rConversion.mcCurrencies.first >> rConversion.mcCurrencies.second
       >> rConversion.mConversionRate;

  return rcIn;
}

//***************************************************************************
// Operator:    ==
//
// Description: determines if two Conversions are equal
//
// Parameters:  rcConversionOne - the first object that is checked for equality
//              rcConversionTwo - the second object that is checked for equality
//
// Returned:    true if the first and second Conversion currencys match, else false
//***************************************************************************
bool operator==(const Conversion& rcConversionOne, const Conversion& rcConversionTwo)
{
  return rcConversionOne.mcCurrencies == rcConversionTwo.mcCurrencies;
}
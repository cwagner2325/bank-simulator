//********************************************************
// File name:  Currency.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement Currency 
//********************************************************

#include <iostream>
#include <string>

#include "Currency.h"

//***************************************************************************
// Constructor:    Currency
//
// Description:    Initalizes a currency object
//***************************************************************************
Currency::Currency() {};

//***************************************************************************
// Constructor:    Currency
//
// Description:    Initalizes a currency from a string
//
// Parameters:     cStr - the string that is converted to currency
//***************************************************************************
Currency::Currency(std::string cStr)
{
  from_str(cStr);
};

//***************************************************************************
// Constructor:    Currency
//
// Description:    Copy constructor for currency class
//
// Parameters:     rcCurr - the currency that is copied to currency
//***************************************************************************
Currency::Currency(const Currency& rcCurr)
{
  meType = rcCurr.meType;
};

//***************************************************************************
// Destructor:    Currency
//
// Description:   destructor for Currency
//***************************************************************************
Currency::~Currency() {};

//***************************************************************************
// Function:      to_string
//
// Description:   converts a currency type to a string
//
// Parameters:    none
//
// Returned:      the currency in string from
//***************************************************************************
std::string Currency::to_string() const
{
  switch(meType)
  {
    case Type::USD:
      return "USD";
    case Type::GBP:
      return "GBP";
    case Type::EUR:
      return "EUR";
    case Type::YEN:
      return "YEN";
    default:
      return "";
  }
}

//***************************************************************************
// Operator:    <<
//
// Description: prints the currency to a stream
//
// Parameters:  rcOut      - the stream that is printed to 
//              rcCurrency - the currency that is printed
//
// Returned:    a reference to the stream variable
//***************************************************************************
std::ostream& operator<<(std::ostream& rcOut, const Currency& rcCurrency)
{
  return rcOut << rcCurrency.to_string();
}

//***************************************************************************
// Operator:    >>
//
// Description: reads in a currency from a stream
//
// Parameters:  rcIn       - the stream that is read from
//              rcCurrency - the currency that is read in
//
// Returned:    a reference to the stream variable
//***************************************************************************
std::istream& operator>>(std::istream& rcIn, Currency& rcCurrency)
{
  std::string cTemp;
  rcIn >> cTemp;

  rcCurrency.from_str(cTemp);

  return rcIn;
}

//***************************************************************************
// Operator:    ==
//
// Description: compares the equality of two currency's types
//
// Parameters:  rcCurr1 - the first currency that is compared
//              rcCurr2 - the second currency that is compared
//
// Returned:    true if the currency types match, else false
//***************************************************************************
bool operator==(const Currency& rcCurr1, const Currency& rcCurr2)
{
  return rcCurr1.meType == rcCurr2.meType;
}

//***************************************************************************
// Function:    from_str
//
// Description: sets a type of currency from a string
//
// Parameters:  cStr - the string that is used to set a type
//
// Returned:    none
//***************************************************************************
void Currency::from_str(std::string cStr)
{
  if (cStr == "USD")
  {
    meType = Currency::Type::USD;
  }
  else if (cStr == "GBP")
  {
    meType = Currency::Type::GBP;
  }
  else if (cStr == "EUR")
  {
    meType = Currency::Type::EUR;
  }
  else if (cStr == "YEN")
  {
    meType = Currency::Type::YEN;
  }
}
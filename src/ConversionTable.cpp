//********************************************************
// File name:  ConversionTable.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement ConversionTable 
//********************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Conversion.h"
#include "ConversionTable.h"
#include "Money.h"
#include "CurrencyMismatchException.h"

//***************************************************************************
// Function:    getInstance
//
// Description: gets the single static copy of the ConversionTable singleton
//
// Parameters:  none
//
// Returned:    a reference to the single copy of the ConversionTable
//***************************************************************************
ConversionTable& ConversionTable::getInstance()
{
  static ConversionTable instance;

  return instance;
}

//***************************************************************************
// Function:    convert
//
// Description: converts a money to a new currency using the conversion table
//
// Parameters:  rcMoney - a reference to the money object to be converted
//              rcCurr  - the currency to be converted to 
//
// Returned:    a new Money object that has been converted to the new currency
//***************************************************************************
Money ConversionTable::convert(const Money& rcMoney, const Currency& rcCurr)
{
  Money cTempMoney;
  Conversion cNewConversion(rcMoney.getCurrency(), rcCurr, 0);
  
  for (unsigned int i = 0; i < mapcConversions.size(); i++)
  {
    if (mapcConversions.at(i) == cNewConversion)
    {
      cTempMoney = rcMoney * mapcConversions.at(i).getConversionRate();
      return Money(cTempMoney, rcCurr);
    }
  }

  std::string error = "CurrencyMismatchException: FROM: " + 
                      rcMoney.getCurrency().to_string() + " TO: " + rcCurr.to_string();

  throw CurrencyMismatchException(error);
}


//***************************************************************************
// Function:    readConversionFromFile
//
// Description: initalizes the conversion table from data in a file
//
// Parameters:  filename - the name of the file that is opened for reading
//
// Returned:    none
//***************************************************************************
void ConversionTable::readConversionFromFile(std::string fileName)
{
  std::ifstream cInFile;
  Currency cFirstCurr;
  Currency cSecondCurr;
  double conversionRate;

  cInFile.open(fileName);

  if (!(cInFile.is_open()))
  {
    exit(EXIT_FAILURE);
  }

  while (cInFile >> cFirstCurr >> cSecondCurr >> conversionRate)
  {
    mapcConversions.push_back(Conversion(cFirstCurr, cSecondCurr, conversionRate));
    mapcConversions.push_back(Conversion(cSecondCurr, cFirstCurr, 1 / conversionRate));
  }

  cInFile.close();
}
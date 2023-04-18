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
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
ConversionTable& ConversionTable::getInstance()
{
  static ConversionTable instance;

  return instance;
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

  throw CurrencyMismatchException(rcMoney.getCurrency().to_string() + "to:" 
                                  + rcCurr.to_string());
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
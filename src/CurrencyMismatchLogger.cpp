//********************************************************
// File name:  CurrencyMismatchLogger.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement CurrencyMismatchLogger 
//********************************************************

#include <iostream>

#include "CurrencyMismatchLogger.h"

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
CurrencyMismatchLogger::CurrencyMismatchLogger()
{
  const std::string FILE_NAME = "CurrencyExceptions.log";

  mOutputStream.open(FILE_NAME);

  if (!mOutputStream.is_open())
  {
    std::cout << "Cannot open file: " << FILE_NAME << std::endl;
    exit(EXIT_FAILURE);
  }
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
CurrencyMismatchLogger::~CurrencyMismatchLogger()
{
  mOutputStream.close();
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
CurrencyMismatchLogger& CurrencyMismatchLogger::getInstance()
{
  static CurrencyMismatchLogger instance;

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
void CurrencyMismatchLogger::writeToFile(std::string message)
{
  mOutputStream << message << std::endl;
}
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
// Constructor:    CurrencyMismatchLogger
//
// Description:    constructor for CurrencyMismatchLogger. opens the log stream
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
// Destructor:    CurrencyMismatchLogger
//
// Description:   destructor for CurrencyMismatchLogger. Closes the log stream
//***************************************************************************
CurrencyMismatchLogger::~CurrencyMismatchLogger()
{
  mOutputStream.close();
}

//***************************************************************************
// Function:    getInstance
//
// Description: gets the single copy of the CurrencyMismatchLogger Singleton
//
// Parameters:  none
//
// Returned:    a refence to the single copy of CurrencyMismatchLogger
//***************************************************************************
CurrencyMismatchLogger& CurrencyMismatchLogger::getInstance()
{
  static CurrencyMismatchLogger instance;

  return instance;
}

//***************************************************************************
// Function:    writeToFile
//
// Description: write a message to the file
//
// Parameters:  message - the string that is written to file
//
// Returned:    none
//***************************************************************************
void CurrencyMismatchLogger::writeToFile(std::string message)
{
  mOutputStream << message << std::endl;
}
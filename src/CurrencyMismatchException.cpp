//********************************************************
// File name:  CurrencyMismatchException.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement CurrencyMismatchException 
//********************************************************

#include <iostream>
#include <string>

#include "CurrencyMismatchException.h"

//***************************************************************************
// Constructor:    CurrencyMismatchException
//
// Description:    Initalizes a CurrencyMismatchException object
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException()
{
  mcErrorMessage = nullptr;
}

//***************************************************************************
// Constructor:    CurrencyMismatchException
//
// Description:    Initalizes a CurrencyMismatchException object from a string
//
// Parameters:     cMessage - the error message that is stored
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException(std::string cMessage)
{
  mcErrorMessage = cMessage.data();
}

//***************************************************************************
// Constructor:    CurrencyMismatchException
//
// Description:    Initalizes a CurrencyMismatchException object from another 
//                 CurrencyMismatchException object
//
// Parameters:     rcException - the object that is copied
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException
  (const CurrencyMismatchException& rcException)
{
  mcErrorMessage = rcException.mcErrorMessage;
}

//***************************************************************************
// Destructor:    CurrencyMismatchException
//
// Description:   Destructor for CurrencyMismatchException
//***************************************************************************
CurrencyMismatchException::~CurrencyMismatchException() {}

//***************************************************************************
// Operator:    =
//
// Description: returns a new CurrencyMismatchException object by copy
//
// Parameters:  rcException - the CurrencyMismatchException object that is
//                            copied
//
// Returned:    a copy of a CurrencyMismatchException object
//***************************************************************************
CurrencyMismatchException CurrencyMismatchException::operator=
  (const CurrencyMismatchException& rcException)
{
  return CurrencyMismatchException(rcException);
}

//***************************************************************************
// Function:    what
//
// Description: returns the error message
//
// Parameters:  none
//
// Returned:    a string that is the error message
//***************************************************************************
std::string CurrencyMismatchException::what()
{
  return mcErrorMessage;
}
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
// Constructor:    
//
// Description: 
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException()
{
  cErrorMessage = nullptr;
}

//***************************************************************************
// Constructor:    
//
// Description: 
//
// Parameters:  
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException(std::string cMessage)
{
  cErrorMessage = cMessage.data();
}

//***************************************************************************
// Constructor:    
//
// Description: 
//
// Parameters:  
//***************************************************************************
CurrencyMismatchException::CurrencyMismatchException
  (const CurrencyMismatchException& rcException)
{
  cErrorMessage = rcException.cErrorMessage;
}

//***************************************************************************
// Destructor:    
//
// Description: 
//
// Parameters:  
//***************************************************************************
CurrencyMismatchException::~CurrencyMismatchException() {}

//***************************************************************************
// Operator:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
CurrencyMismatchException CurrencyMismatchException::operator=
  (const CurrencyMismatchException& rcException)
{
  return CurrencyMismatchException(rcException);
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
std::string CurrencyMismatchException::what()
{
  return cErrorMessage;
}
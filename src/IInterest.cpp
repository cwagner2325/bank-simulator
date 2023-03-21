//********************************************************
// File name:  IInterest.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the TieredInterest
//********************************************************

#include "memory"
#include "iostream"

#include "IInterest.h"
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
std::istream& operator>>(std::istream& rcIn, std::shared_ptr<IInterest> rcInt)
{
  rcInt->read(rcIn);
  
  return rcIn;
}
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
// Operator:    >>
//
// Description: read an interest object polymorphically by calling read
//
// Parameters:  rcIn  - the stream from which interest is read
//              rcInt - a pointer to the pbject that is read
//
// Returned:    a reference to the stream
//***************************************************************************
std::istream& operator>>(std::istream& rcIn, std::shared_ptr<IInterest> rcInt)
{
  rcInt->read(rcIn);
  
  return rcIn;
}

//***************************************************************************
// Operator:    <<
//
// Description: print an interest object polymorphically by calling print
//
// Parameters:  rcOut - the stream to which interest is printed
//              rcInt - a pointer to the pbject that is printed
//
// Returned:    a reference to the stream
//***************************************************************************
std::ostream& operator<<(std::ostream& rcOut, std::shared_ptr<IInterest> rcInt)
{
  rcInt->print(rcOut);
  
  return rcOut;
}
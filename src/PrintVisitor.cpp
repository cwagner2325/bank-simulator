//********************************************************
// File name:  PrintVisitor.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement PrintVisitor 
//********************************************************

#include <iostream>

#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "PrintVisitor.h"

//***************************************************************************
// Function:    visit
//
// Description: performs the update month operation on a checking account
//
// Parameters:  rAccount - the account that is operated on
//
// Returned:    none
//***************************************************************************
void PrintVisitor::visit(CheckingAccount& rAccount)
{
  std::cout << rAccount;
}

//***************************************************************************
// Function:    visit
//
// Description: performs the update month operation on a savings account
//
// Parameters:  rAccount - the account that is operated on
//
// Returned:    none
//***************************************************************************
void PrintVisitor::visit(SavingsAccount& rAccount)
{
  std::cout << rAccount;
}

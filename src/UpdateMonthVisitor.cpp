//********************************************************
// File name:  UpdateMonthVisitor.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement UpdateMonthVisitor 
//********************************************************

#include <iostream>

#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "UpdateMonthVisitor.h"

//***************************************************************************
// Function:    visit
//
// Description: performs the update month operation on a checking account
//
// Parameters:  rAccount - the account that is operated on
//
// Returned:    none
//***************************************************************************
void UpdateMonthVisitor::visit(CheckingAccount& rAccount)
{
  rAccount.updateMonth();
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
void UpdateMonthVisitor::visit(SavingsAccount& rAccount)
{
  rAccount.updateMonth();
}

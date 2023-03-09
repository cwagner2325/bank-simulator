//********************************************************
// File name:  DepositCommand.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To impkement the DepositCommand 
//********************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "DepositCommand.h"

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
DepositCommand::DepositCommand(int accountNumber, long long depositAmount)
{
  mAccountNumber = accountNumber;
  mDepositAmount = depositAmount;
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
void DepositCommand::execute(Bank& rcTheBank)
{
  std::shared_ptr<IBankAccount> pcAccount = rcTheBank.findAccount(mAccountNumber);

  if (nullptr != pcAccount)
  {
    pcAccount->deposit(mDepositAmount);
  }
}

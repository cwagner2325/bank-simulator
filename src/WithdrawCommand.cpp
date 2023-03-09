//********************************************************
// File name:  WithdrawCommand.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To impkement the WithdrawCommand 
//********************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "WithdrawCommand.h"

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
WithdrawCommand::WithdrawCommand(int accountNumber, long long withdrawAmount)
{
  mAccountNumber = accountNumber;
  mWithdrawAmount = withdrawAmount;
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
void WithdrawCommand::execute(Bank& rcTheBank)
{
  std::shared_ptr<IBankAccount> pcAccount = rcTheBank.findAccount(mAccountNumber);

  if (nullptr != pcAccount)
  {
    pcAccount->withdraw(mWithdrawAmount);
  }
}

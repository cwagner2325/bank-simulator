//********************************************************
// File name:  WithdrawCommand.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To impkement the WithdrawCommand 
//********************************************************

#include <memory>

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
WithdrawCommand::WithdrawCommand(std::shared_ptr<IReceiver> pReceiver, 
                                 int accountNumber, long long withdrawAmount)
{
  mReceiver = pReceiver;
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
void WithdrawCommand::execute()
{
  mReceiver->withdraw(mAccountNumber, mWithdrawAmount);
}

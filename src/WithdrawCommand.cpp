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
#include "Money.h"

//***************************************************************************
// Constructor:    WithdrawCommand
//
// Description:    Initializes member variables 
//
// Parameters:     pReceiver      - a pointer to the receiver of the command
//                 accountNumber  - the account number of the account that 
//                                  withdraw is executed on
//                 withdrawAmount - the amount that is withdrawed
//***************************************************************************
WithdrawCommand::WithdrawCommand(std::shared_ptr<IReceiver> pReceiver, 
                                 int accountNumber, Money withdrawAmount)
{
  mReceiver = pReceiver;
  mAccountNumber = accountNumber;
  mWithdrawAmount = withdrawAmount;
}

//***************************************************************************
// Function:      execute
//
// Description:   execute the withdraw on the receiever using me=mber data
//
// Parameters:    none
//
// Returned:      none
//***************************************************************************
void WithdrawCommand::execute()
{
  try 
  {
    mReceiver->withdraw(mAccountNumber, mWithdrawAmount);
  }
  catch (std::out_of_range& err)
  {
    throw err;
  }
}

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
#include "Money.h"

#include "DepositCommand.h"

//***************************************************************************
// Constructor:    DepositCommand
//
// Description:    Initializes member variables 
//
// Parameters:     pReceiver     - a pointer to the receiver of the command
//                 accountNumber - the account number of the account that 
//                                 withdraw is executed on
//                 depositAmount - the amount that is deposited
//***************************************************************************
DepositCommand::DepositCommand(std::shared_ptr<IReceiver> pReceiver, 
                               int accountNumber, Money depositAmount)
{
  mReceiver = pReceiver;
  mAccountNumber = accountNumber;
  mDepositAmount = depositAmount;
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
void DepositCommand::execute() 
{
  mReceiver->deposit(mAccountNumber, mDepositAmount);
}

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
DepositCommand::DepositCommand(std::shared_ptr<IReceiver> pReceiver, 
                               int accountNumber, long long depositAmount)
{
  mReceiver = pReceiver;
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
void DepositCommand::execute() 
{
  mReceiver->deposit(mAccountNumber, mDepositAmount);
}

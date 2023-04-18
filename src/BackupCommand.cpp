//********************************************************
// File name:  BackupCommand.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To impkement the WithdrawCommand 
//********************************************************

#include <memory>

#include "BackupCommand.h"
#include "Money.h"

//***************************************************************************
// Constructor:    BackupCommand
//
// Description:    Initializes member variables 
//
// Parameters:     pReceiver      - 
//***************************************************************************
BackupCommand::BackupCommand(std::shared_ptr<IReceiver> pReceiver, 
                             std::string checkingFile, std::string savingsFile)
{
  mReceiver = pReceiver;
  mCheckingFile = checkingFile;
  mSavingFile = savingsFile;
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
void BackupCommand::execute()
{
  mReceiver->backupAccounts(mCheckingFile, mSavingFile);
}
//********************************************************
// File name:  BackupCommand.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the WithdrawCommand 
//********************************************************

#include <memory>

#include "BackupCommand.h"
#include "Money.h"

//***************************************************************************
// Constructor:    BackupCommand
//
// Description:    Initializes member variables 
//
// Parameters:     pReceiver    - a pointer to the receiver
//                 checkingFile - the name of the file for checking accounts
//                 savingsFile  - the name of the file for savings accounts
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
// Description:   execute the backup on the receiever using member data
//
// Parameters:    none
//
// Returned:      none
//***************************************************************************
void BackupCommand::execute()
{
  mReceiver->backupAccounts(mCheckingFile, mSavingFile);
}
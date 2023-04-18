//********************************************************
// File name:  BackupAccountsVisitor.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement BackupAccountsVisitor 
//********************************************************

#include <iostream>
#include <fstream>
#include <string>

#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "BackupAccountsVisitor.h"

//***************************************************************************
// Constructor:    BackupAccountsVisitor
//
// Description:    opens the file for writing and terminates program if not opened
//
// Parameters:     checkingFile - the name of the file opened for logging 
//                                checkings accounts
//                 savingFile   - the name of the file opened for logging 
//                                savings accounts
//***************************************************************************
BackupAccountsVisitor::BackupAccountsVisitor(std::string checkingFile, 
                                             std::string savingFile)
{
  mcrCheckingStream.open(checkingFile);
  mcrSavingStream.open(savingFile);

  if (!mcrCheckingStream.is_open())
  {
    std::cout << "Cannot open file: " << checkingFile << std::endl;
    exit(EXIT_FAILURE);
  }

  if (!mcrSavingStream.is_open())
  {
    std::cout << "Cannot open file: " << savingFile << std::endl;
    exit(EXIT_FAILURE);
  }

}

//***************************************************************************
// Destructor:    BackupAccountsVisitor
//
// Description:   closes the output stream
//***************************************************************************
BackupAccountsVisitor::~BackupAccountsVisitor()
{
  mcrCheckingStream.close();
  mcrSavingStream.close();
}

//***************************************************************************
// Function:    visit
//
// Description: performs the backup operation on a checking account
//
// Parameters:  rAccount - the account that is operated on
//
// Returned:    none
//***************************************************************************
void BackupAccountsVisitor::visit(CheckingAccount& rAccount)
{
  mcrCheckingStream << rAccount << std::endl;
}

//***************************************************************************
// Function:    visit
//
// Description: performs the backup operation on a savings account
//
// Parameters:  rAccount - the account that is operated on
//
// Returned:    none
//***************************************************************************
void BackupAccountsVisitor::visit(SavingsAccount& rAccount)
{
  mcrSavingStream << rAccount << std::endl;
}

//********************************************************
// File name:  Bank.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the Bank
//********************************************************

#include <memory>
#include <vector>
#include <exception>

#include "IAccountReader.h"
#include "IBankAccount.h"
#include "Bank.h"
#include "CurrencyMismatchException.h"
#include "IVisitor.h"
#include "PrintVisitor.h"
#include "UpdateMonthVisitor.h"
#include "BackupAccountsVisitor.h"
#include "CurrencyMismatchLogger.h"

//***************************************************************************
// Constructor:    Bank
//
// Description:    Reads in all accounts from the account reader and stores 
//                 them in its member variable mapcAccount
//
// Parameters:     rcReader - a reference to an account reader
//***************************************************************************
Bank::Bank(std::shared_ptr<IAccountReader> pcReader,
           std::shared_ptr<IAccountContainer> pcContainer)
{
  std::shared_ptr<IBankAccount> pcAccount;

  mapcAccounts = pcContainer;
  
  while (nullptr != (pcAccount = pcReader->readNext()))
  {
    mapcAccounts->insert(pcAccount);
  }
}

//***************************************************************************
// Destructor:    Bank
//
// Description:   the destructor for the Bank class
//***************************************************************************
Bank::~Bank() {}

//***************************************************************************
// Function:    executeCommands
//
// Description: executes a set of commands
//
// Parameters:  acCommands - a reference to a vector containing commands
//
// Returned:    none
//***************************************************************************
void Bank::executeCommands(std::vector<std::shared_ptr<ICommand>> acCommands)
{
  for (unsigned int i = 0; i < (acCommands.size()); i++) 
  {
    try 
    {
      acCommands.at(i)->execute();
    }
    catch (std::out_of_range& err)
    {
      std::cout << std::endl << "Bank::executeCommands failed: " << err.what()
                << std::endl << std::endl;
      exit(EXIT_FAILURE);
    }
  }
}

//***************************************************************************
// Function:    printAll
//
// Description: prints all the accounts in the vector to the terminal
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void Bank::printAll()
{
  const int NUM_CHARS = 13;
  const char BORDER_CHAR = '-';

  std::shared_ptr<IVisitor> pcVisitor (new PrintVisitor());

  for (int i = 0; i < NUM_CHARS; i++) 
  {
    std::cout << BORDER_CHAR;
  }

  std::cout << std::endl;

  mapcAccounts->accept(pcVisitor);

  for (int i = 0; i < NUM_CHARS; i++) 
  {
    std::cout << BORDER_CHAR;
  }

  std::cout << std::endl;
}

//***************************************************************************
// Function:    updateMonth
//
// Description: iterates through the vector and calls updateMonth on each account
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void Bank::updateMonth()
{
  std::shared_ptr<IVisitor> pcVisitor (new UpdateMonthVisitor());

  mapcAccounts->accept(pcVisitor);
}

//***************************************************************************
// Function:    backupAccounts
//
// Description: backups the accounts to the files using a visitor
//
// Parameters:  checkingFile - the file that checking accounts are printed to
//              savingFile   - the file that savings accounts are printed to
//
// Returned:    none
//***************************************************************************
void Bank::backupAccounts(std::string checkingFile, std::string savingFile)
{
  std::shared_ptr<IVisitor> pcVisitor 
    (new BackupAccountsVisitor(checkingFile, savingFile));

  mapcAccounts->accept(pcVisitor);
}

//***************************************************************************
// Function:    deposit
//
// Description: finds an account based on an account number and deposits an
//              amount if the account is found
//
// Parameters:  accountNumber - the key of an account that is searched for
//              depositAmount - the amount deposited into the found account
//
// Returned:    none
//***************************************************************************
void Bank::deposit(int accountNumber, const Money& depositAmount)
{
  const std::string COMMAND = "D";
  std::shared_ptr<IBankAccount> pcAccount;

  try 
  {
    pcAccount = mapcAccounts->find(accountNumber);
  }
  catch (std::out_of_range& err)
  {
    throw err;
  }

  try
  {
    pcAccount->deposit(depositAmount);
  }
  catch (CurrencyMismatchException& err)
  {
    std::string error = "COMMAND: " + COMMAND + " ACCOUNT: " 
                        + std::to_string(pcAccount->getAccountNumber()) + " ";

    CurrencyMismatchLogger::getInstance().writeToFile(error + err.what());
  }
}

//***************************************************************************
// Function:    withdraw
//
// Description: finds an account based on an account number and withdraws an
//              amount if the account is found
//
// Parameters:  accountNumber  - the key of an account that is searched for
//              withdrawAmount - the amount withdrawn from the found account
//
// Returned:    none
//***************************************************************************
void Bank::withdraw(int accountNumber, const Money& withdrawAmount)
{
  const std::string COMMAND = "W";
  std::shared_ptr<IBankAccount> pcAccount;

  try 
  {
    pcAccount = mapcAccounts->find(accountNumber);
  }
  catch (std::out_of_range& err)
  {
    throw err;
  }

  try
  {
    pcAccount->withdraw(withdrawAmount);
  }
  catch (CurrencyMismatchException& err)
  {
    std::string error = "COMMAND: " + COMMAND + " ACCOUNT: " 
                        + std::to_string(pcAccount->getAccountNumber()) + " ";

    CurrencyMismatchLogger::getInstance().writeToFile(error + err.what());
  }
}
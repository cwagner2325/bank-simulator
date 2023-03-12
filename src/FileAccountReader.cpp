//********************************************************
// File name:  FileAccountReader.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the FileAccountReader 
//********************************************************

#include <memory>
#include <iostream>
#include <vector>

#include "FileAccountReader.h"
#include "IBankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

//***************************************************************************
// Constructor:    FileAccountReader
//
// Description:    opens a file for reading from a string
//
// Parameters:     filename - the name of the file that is opened
//***************************************************************************
FileAccountReader::FileAccountReader(std::string filename)
{
  mcFile.open(filename);

  if (!mcFile.is_open()) 
  {
    std::cout << "ERROR: Invalid Account File Provided" << std::endl << std::endl;
    exit(EXIT_FAILURE);
  }
}

//***************************************************************************
// Destructor:    FileAccountReader
//
// Description:   closes the input file when the object is destroyed
//***************************************************************************
FileAccountReader::~FileAccountReader()
{
  mcFile.close();
}

//***************************************************************************
// Function:    readAccount
//  
// Description: reads an account and calls the correct constructor
//
// Parameters:  none
//
// Returned:    a shared pointer to the bank account object that is read in
//***************************************************************************
std::shared_ptr<IBankAccount> FileAccountReader::readAccount()
{
  const char SAVINGS_ACCOUNT = 'S';
  const char CHECKINGS_ACCOUNT = 'C';

  int accountNumber;
  long long initBalance;
  double interestRate;
  long long fee;
  long long minBalance;

  char accountIdentity = '.';

  mcFile >> accountIdentity;

  if (SAVINGS_ACCOUNT == accountIdentity)
  {
    mcFile >> accountNumber >> initBalance >> interestRate >> fee >> minBalance;
    std::shared_ptr<IBankAccount> pcAccount(
     new SavingsAccount(accountNumber, initBalance, interestRate, fee, minBalance));
    return pcAccount;
  }
  else if (CHECKINGS_ACCOUNT == accountIdentity)
  {
    mcFile >> accountNumber >> initBalance >> interestRate >> minBalance >> fee;
    std::shared_ptr<IBankAccount> pcAccount(
      new CheckingAccount(accountNumber, initBalance, interestRate, minBalance, fee));
    return pcAccount;
  }

  return nullptr;
}

//***************************************************************************
// Function:    readAll
//
// Description: reads all the accounts in the file and puts them into a vector
//
// Parameters:  rcAccounts - the to a reference to a vector that stores the
//                           accounts read in
//
// Returned:    none
//***************************************************************************
void FileAccountReader::readAll(std::vector<std::shared_ptr<IBankAccount>>& rcAccounts)
{
  std::shared_ptr<IBankAccount> pcAccount;

  while (nullptr != (pcAccount = readAccount()))
  {
    rcAccounts.push_back(pcAccount);
  }
}
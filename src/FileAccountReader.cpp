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

#include "FileAccountReader.h"
#include "IBankAccount.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

//***************************************************************************
// Constructor:    
//
// Description: 
//
// Parameters:   
//***************************************************************************
FileAccountReader::FileAccountReader(std::string filename)
{
  mcFile.open(filename);
}

//***************************************************************************
// Destructor:    
//
// Description: 
//***************************************************************************
FileAccountReader::~FileAccountReader()
{
  mcFile.close();
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
std::shared_ptr<IBankAccount> FileAccountReader::readAccount()
{
  const char SAVINGS_ACCOUNT = 'S';
  const char CHECKINGS_ACCOUNT = 'C';

  int accountNumber;
  long long initBalance;
  double interestRate;
  long long fee;
  long long minBalance;

  char accountIdentity;

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
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
std::shared_ptr<IBankAccount> FileAccountReader::readNext()
{
  const char SAVINGS_ACCOUNT = 'S';
  const char CHECKINGS_ACCOUNT = 'C';

  char accountIdentity = '\0';

  std::shared_ptr<IBankAccount> pcAccount = nullptr;
  
  mcFile >> accountIdentity;

  if (SAVINGS_ACCOUNT == accountIdentity)
  {
    pcAccount = std::make_shared <SavingsAccount> ();
    mcFile >> pcAccount;
  }
  else if (CHECKINGS_ACCOUNT == accountIdentity)
  {
    pcAccount = std::make_shared <CheckingAccount> ();
    mcFile >> pcAccount;
  }

  return pcAccount;
}
//********************************************************
// File name:  FileCommandReader.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the FileCommandReader 
//********************************************************

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "FileCommandReader.h"
#include "ICommand.h"
#include "PrintAllCommand.h"
#include "UpdateMonthCommand.h"
#include "DepositCommand.h"
#include "WithdrawCommand.h"
#include "IReceiver.h"

//***************************************************************************
// Constructor:    FileCommandReader
//
// Description:    Opens the file name and stores the stream in a member variable
//
// Parameters:     filename - the name of the opened input file
//***************************************************************************
FileCommandReader::FileCommandReader(std::string filename)
{
  mcInFile.open(filename);

  if (!mcInFile.is_open()) 
  {
    std::cout << "ERROR: Invalid Command File Provided" << std::endl << std::endl;
    exit(EXIT_FAILURE);
  }
}

//***************************************************************************
// Destructor:    FileCommandReader
//
// Description:   Closes the input file when the object is destroyed
//***************************************************************************
FileCommandReader::~FileCommandReader()
{
  mcInFile.close();
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
std::shared_ptr<ICommand> FileCommandReader::readCommand(std::shared_ptr<IReceiver> pReceiver)
{
  const char PRINT_ALL = 'P';
  const char UPDATE_MONTH = 'M';
  const char DEPOSIT_COMMAND = 'D';
  const char WITHDRAW_COMMAND = 'W';

  char commandIdentity = '.';
  int accountNumber = 0;
  long long amount = 0;

  std::shared_ptr<ICommand> pcCommand = nullptr;

  mcInFile >> commandIdentity;

  if (PRINT_ALL == commandIdentity) 
  {
    pcCommand = std::make_shared<PrintAllCommand> (pReceiver);
  }
  else if (UPDATE_MONTH == commandIdentity)
  {
    pcCommand = std::make_shared<UpdateMonthCommand> (pReceiver);
  }
  else if (DEPOSIT_COMMAND == commandIdentity)
  {
    mcInFile >> accountNumber >> amount;
    pcCommand = std::make_shared<DepositCommand> (pReceiver, accountNumber, amount);
  }
  else if (WITHDRAW_COMMAND == commandIdentity)
  {
    mcInFile >> accountNumber >> amount;
    pcCommand = std::make_shared<WithdrawCommand> (pReceiver, accountNumber, amount);
  }

  return pcCommand;
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
void FileCommandReader::readAll(std::shared_ptr<IReceiver> pReceiver,
                                std::vector<std::shared_ptr<ICommand>>& rcCommands)
{
  std::shared_ptr<ICommand> pcCommand;

  while (nullptr != (pcCommand = readCommand(pReceiver)))
  {
    rcCommands.push_back(pcCommand);
  }
}

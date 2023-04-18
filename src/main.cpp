//***************************************************************************
// File name:   main.cpp
// Author:      Cayden Wagner
// Date:        March 8, 2023
// Class:       AOO - CS485
// Assignment:  Bank
// Purpose:     Practice my Object Oriented Design Skills. Practice my UML
//              design skills. Practice new C++ syntax and idioms.
//***************************************************************************

#include <vector> 
#include <memory>

#include "Bank.h"
#include "IAccountReader.h"
#include "FileAccountReader.h"
#include "ICommandReader.h"
#include "FileCommandReader.h"
#include "ICommand.h"
#include "IAccountContainer.h"
#include "AccountMap.h"
#include "Money.h"

//***************************************************************************
// Function:    main
//
// Description: Initializes a Bank object and starts the Bank Operations
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main(int argc, char *argv[])
{
  const int CORRECT_NUM_COMMANDS_ARGS = 4;
  const int ACCOUNT_FILE_INDEX = 1;
  const int COMMAND_FILE_INDEX = 2;
  //const int CONVERSIONS_FILE_INDEX = 3;

  if (CORRECT_NUM_COMMANDS_ARGS != argc) 
  {
    std::cout << "ERROR: Incorrect Number of Command Line Args" << std::endl 
              << std::endl;
    return EXIT_FAILURE;
  }

  std::vector <std::shared_ptr <ICommand>> mapcCommands; 

  std::shared_ptr<IAccountReader> pcAccountReader
                          (new FileAccountReader(argv[ACCOUNT_FILE_INDEX]));
                          
  std::shared_ptr<ICommandReader> pcCommandReader
                          (new FileCommandReader(argv[COMMAND_FILE_INDEX]));

  std::shared_ptr<IAccountContainer> pcMap (new AccountMap());

  std::shared_ptr<Bank> pcTheBank(new Bank(pcAccountReader, pcMap));

  pcCommandReader->readAll(pcTheBank, mapcCommands);

  pcTheBank->executeCommands(mapcCommands);

  return EXIT_SUCCESS;
}

//********************************************************
// File name:  PrintAllCommand.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the PrintAllCommand 
//********************************************************

#include <memory>

#include "PrintAllCommand.h"

//***************************************************************************
// Constructor:    WithdrawCommand
//
// Description:    Initializes the receiver  
//
// Parameters:     pReceiver - a pointer to the receiver of the command
//***************************************************************************
PrintAllCommand::PrintAllCommand(std::shared_ptr<IReceiver> pReceiver)
{
  mReceiver = pReceiver;
}

//***************************************************************************
// Function:      execute
//
// Description:   execute the print all on the receiever using me=mber data
//
// Parameters:    none
//
// Returned:      none
//***************************************************************************
void PrintAllCommand::execute()
{
  mReceiver->printAll();
}

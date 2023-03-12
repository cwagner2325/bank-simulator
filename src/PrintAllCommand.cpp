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
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
PrintAllCommand::PrintAllCommand(std::shared_ptr<IReceiver> pReceiver)
{
  mReceiver = pReceiver;
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
void PrintAllCommand::execute()
{
  mReceiver->printAll();
}

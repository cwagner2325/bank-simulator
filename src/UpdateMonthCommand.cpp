//********************************************************
// File name:  UpdateMonthCommand.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the UpdateMonthCommand 
//********************************************************

#include <memory>

#include "UpdateMonthCommand.h"

//***************************************************************************
// Constructor:    UpdateMonthCommand
//
// Description:    Initalizes the receiver 
//
// Parameters:     pReceiver - a pointer to the receiver of the command
//***************************************************************************
UpdateMonthCommand::UpdateMonthCommand(std::shared_ptr<IReceiver> pReceiver)
{
  mReceiver = pReceiver;
}

//***************************************************************************
// Function:      execute
//
// Description:   execute the update on the receiever using me=mber data
//
// Parameters:    none
//
// Returned:      none
//***************************************************************************
void UpdateMonthCommand::execute()
{
  mReceiver->updateMonth();
}

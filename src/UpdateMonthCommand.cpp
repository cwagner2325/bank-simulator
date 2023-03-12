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
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
UpdateMonthCommand::UpdateMonthCommand(std::shared_ptr<IReceiver> pReceiver)
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
void UpdateMonthCommand::execute()
{
  mReceiver->updateMonth();
}

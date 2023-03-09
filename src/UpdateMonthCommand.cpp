//********************************************************
// File name:  UpdateMonthCommand.cpp
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement the UpdateMonthCommand 
//********************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

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
UpdateMonthCommand::UpdateMonthCommand()
{

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
void UpdateMonthCommand::execute(Bank& rcTheBank)
{
  rcTheBank.updateMonth();
}

//********************************************************
// File name:  PrintAllCommand.cpp
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
PrintAllCommand::PrintAllCommand()
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
void PrintAllCommand::execute(Bank& rcTheBank)
{
  rcTheBank.printAll();
}

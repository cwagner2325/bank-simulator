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
// virtual std::shared_ptr<ICommand> readCommand();

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
// virtual void readAll(std::vector<std::shared_ptr<ICommand>>&);

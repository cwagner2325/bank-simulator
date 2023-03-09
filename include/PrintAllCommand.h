//********************************************************
// File name:  PrintAllCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the PrintAllCommand 
//********************************************************

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "ICommand.h"

class PrintAllCommand : ICommand
{
  public:
    PrintAllCommand();
    virtual ~PrintAllCommand() {};

    virtual void execute(Bank&);

};
//********************************************************
// File name:  ICommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the ICommand 
//********************************************************

#ifndef _ICommand_H_
#define _ICommand_H_

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "Bank.h"

class ICommand
{
  public:
    virtual ~ICommand() {};

    virtual void execute(Bank&) = 0;

};

#endif
//********************************************************
// File name:  UpdateMonthCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the UpdateMonthCommand 
//********************************************************

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "ICommand.h"

class UpdateMonthCommand : ICommand
{
  public:
    UpdateMonthCommand();
    virtual ~UpdateMonthCommand() {};

    virtual void execute(Bank&);

};
//********************************************************
// File name:  ICommandReader.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the ICommandReader 
//********************************************************

#pragma once

#include <memory>
#include <vector>

#include "ICommand.h"
#include "IReceiver.h"

class ICommandReader 
{
  public:

    virtual ~ICommandReader() {};

    virtual std::shared_ptr<ICommand> readCommand(std::shared_ptr<IReceiver>) = 0;
    virtual void readAll(std::shared_ptr<IReceiver>, std::vector<std::shared_ptr<ICommand>>&) = 0;

};
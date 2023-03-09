//********************************************************
// File name:  ICommandReader.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the ICommandReader 
//********************************************************

#ifndef _ICommandReader_H_
#define _ICommandReader_H_

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "ICommand.h"

class ICommandReader 
{
  public:

    virtual ~ICommandReader() {};

    virtual std::shared_ptr<ICommand> readCommand() = 0;
    virtual void readAll(std::vector<std::shared_ptr<ICommand>>&) = 0;

};

#endif
//********************************************************
// File name:  PrintAllCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the PrintAllCommand 
//********************************************************

#pragma once

#include <memory>

#include "ICommand.h"
#include "IReceiver.h"

class PrintAllCommand : public ICommand
{
  public:
    PrintAllCommand(std::shared_ptr<IReceiver>);
    virtual ~PrintAllCommand() {};

    virtual void execute();

  private: 

    std::shared_ptr<IReceiver> mReceiver;

};
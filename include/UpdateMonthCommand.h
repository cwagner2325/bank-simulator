//********************************************************
// File name:  UpdateMonthCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the UpdateMonthCommand 
//********************************************************

#pragma once

#include <memory>

#include "ICommand.h"
#include "IReceiver.h"

class UpdateMonthCommand : public ICommand
{
  public:
    UpdateMonthCommand(std::shared_ptr<IReceiver>);
    virtual ~UpdateMonthCommand() {};

    virtual void execute();

  private:

    std::shared_ptr<IReceiver> mReceiver;

};
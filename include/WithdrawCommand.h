//********************************************************
// File name:  WithdrawCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the WithdrawCommand 
//********************************************************

#pragma once

#include <memory>

#include "ICommand.h"
#include "IReceiver.h"
#include "Money.h"

class WithdrawCommand : public ICommand
{
  public:
    WithdrawCommand(std::shared_ptr<IReceiver>, int, Money);
    virtual ~WithdrawCommand() {};

    virtual void execute();
  
  private:

    int mAccountNumber;

    Money mWithdrawAmount;

    std::shared_ptr<IReceiver> mReceiver;

};
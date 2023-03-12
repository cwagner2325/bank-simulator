//********************************************************
// File name:  DepositCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the DepositCommand 
//********************************************************

#pragma once

#include <memory>

#include "ICommand.h"
#include "Bank.h"
#include "IReceiver.h"

class DepositCommand : public ICommand
{
  public:
    DepositCommand(std::shared_ptr<IReceiver>, int, long long);
    virtual ~DepositCommand() {};

    virtual void execute();
  
  private:

    int mAccountNumber;

    long long mDepositAmount;

    std::shared_ptr<IReceiver> mReceiver;

};
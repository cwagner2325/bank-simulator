//********************************************************
// File name:  WithdrawCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the WithdrawCommand 
//********************************************************

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "ICommand.h"

class WithdrawCommand : public ICommand
{
  public:
    WithdrawCommand(int, long long);
    virtual ~WithdrawCommand() {};

    virtual void execute(Bank&);
  
  private:

    int mAccountNumber;

    long long mWithdrawAmount;

};
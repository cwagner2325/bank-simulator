//********************************************************
// File name:  DepositCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the DepositCommand 
//********************************************************

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <vector>

#include "ICommand.h"
#include "Bank.h"

class DepositCommand : public ICommand
{
  public:
    DepositCommand(int, long long);
    virtual ~DepositCommand() {};

    virtual void execute(Bank&);
  
  private:

    int mAccountNumber;

    long long mDepositAmount;

};
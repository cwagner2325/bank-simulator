//********************************************************
// File name:  Bank.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the Bank 
//********************************************************

#pragma once

#include <memory>
#include <vector>

#include "IAccountReader.h"
#include "IBankAccount.h"
#include "IReceiver.h"
#include "ICommand.h"
#include "IAccountContainer.h"
#include "Money.h"

class Bank : public IReceiver
{
  private:
    std::shared_ptr<IAccountContainer> mapcAccounts;

  public:
    Bank(std::shared_ptr<IAccountReader>, std::shared_ptr<IAccountContainer>);
    virtual ~Bank();

    virtual void executeCommands(std::vector<std::shared_ptr<ICommand>>&);

    virtual void printAll();
    virtual void updateMonth();

    virtual void deposit(int, const Money&);
    virtual void withdraw(int, const Money&);
};

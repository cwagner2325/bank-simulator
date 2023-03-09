//********************************************************
// File name:  Bank.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the Bank 
//********************************************************

#ifndef _Bank_H_
#define _Bank_H_

#include <memory>
#include <vector>

#include "IAccountReader.h"
#include "IBankAccount.h"

class Bank
{
  private:
    std::vector<std::shared_ptr<IBankAccount>> mapcAccounts;

  public:
    Bank(std::shared_ptr<IAccountReader>&);
    virtual ~Bank();

    //virtual void doBankOperations(std::shared_ptr<ICommandReader>&);

    std::shared_ptr<IBankAccount> findAccount(int);

    virtual void printAll();
    virtual void updateMonth();

    virtual void deposit(int, long long);
    virtual void withdraw(int, long long);
};

#endif

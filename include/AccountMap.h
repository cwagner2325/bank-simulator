//********************************************************
// File name:  AccountMap.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the AccountMap 
//********************************************************

#pragma once

#include <memory>
#include "IBankAccount.h"
#include "IAccountContainer.h"
#include "map"

class AccountMap : public IAccountContainer
{
  public:
    AccountMap();
    virtual ~AccountMap();

    virtual std::shared_ptr<IBankAccount> find(int);

    virtual void insert(std::shared_ptr<IBankAccount>);

    virtual std::shared_ptr<IBankAccount> getNext();

  private:
    std::map<int, std::shared_ptr <IBankAccount>> mapcTheMap;
    std::map<int, std::shared_ptr<IBankAccount>>::iterator mIter;
};
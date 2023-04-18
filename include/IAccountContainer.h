//********************************************************
// File name:  IAccountContainer.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the IAccountContainer 
//********************************************************

#pragma once

#include <memory>

#include "IBankAccount.h"
#include "IVisitor.h"

class IAccountContainer
{
  public:
    ~IAccountContainer() {};

    virtual std::shared_ptr<IBankAccount> find(int) = 0;

    virtual void insert(std::shared_ptr<IBankAccount>) = 0;

    virtual void accept(std::shared_ptr<IVisitor>) = 0;
};
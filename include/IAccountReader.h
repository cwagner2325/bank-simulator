//********************************************************
// File name:  IAccountReader.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the IAccountReader 
//********************************************************

#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include "IBankAccount.h"


class IAccountReader 
{
  public:

    virtual ~IAccountReader() {};

    virtual std::shared_ptr<IBankAccount> readAccount() = 0;
    virtual void readAll(std::vector<std::shared_ptr<IBankAccount>>&) = 0;

};
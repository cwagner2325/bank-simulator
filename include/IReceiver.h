//********************************************************
// File name:  IReceiver.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the Receiver 
//********************************************************

#pragma once

#include <memory>
#include <vector>
#include "Money.h"

class IReceiver
{
  public:
    virtual ~IReceiver() {};

    virtual void printAll() = 0;
    virtual void updateMonth() = 0;

    virtual void deposit(int, const Money&) = 0;
    virtual void withdraw(int, const Money&) = 0;
};


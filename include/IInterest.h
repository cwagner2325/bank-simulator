//********************************************************
// File name:  IInterest.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the IInterest 
//********************************************************

#pragma once

#include <memory>
#include <iostream>
#include <memory>

#include "Money.h"

class IInterest 
{
  public:
    virtual ~IInterest() {};

    virtual Money calculateInterest(const Money&) = 0;

    virtual std::istream& read(std::istream&) = 0;
    friend std::istream& operator>>(std::istream&, std::shared_ptr<IInterest>);
};
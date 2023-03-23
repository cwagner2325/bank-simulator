//********************************************************
// File name:  CheckingAccount.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the CheckingAccount 
//********************************************************

#pragma once
#include <iostream>
#include <string>
#include "IBankAccount.h"
#include "Money.h"

class CheckingAccount : public IBankAccount 
{
  private:

    Money mMinBalance;
    Money mMinBalanceFee;
      
  public:

    CheckingAccount();
    virtual ~CheckingAccount();

    virtual void deposit(const Money&);
    virtual void withdraw(const Money&);
    virtual void updateMonth();

    virtual std::ostream& print(std::ostream&) const; 
    virtual std::istream& read(std::istream&);
};
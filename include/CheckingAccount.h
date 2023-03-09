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

class CheckingAccount : public IBankAccount 
{
  private:

    long long mMinBalance;
    long long mMinBalanceFee;
      
  public:

    CheckingAccount(int, long long, double, long long, long long);
    virtual ~CheckingAccount();

    virtual void deposit(long long);
    virtual void withdraw(long long);

    virtual void updateMonth();

    virtual std::ostream& print(std::ostream&) const; 
};
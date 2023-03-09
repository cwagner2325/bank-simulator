//********************************************************
// File name:  SavingsAccount.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the SavingsAccount 
//********************************************************

#pragma once
#include <iostream>
#include <string>

#include "IBankAccount.h"

class SavingsAccount : public IBankAccount
{
  private:
    long long mMonthlyFee;

    long long mMinMonthlyBalance;

    bool mMonthlyFeeReached;
      
  public:

    SavingsAccount(int, long long, double, long long, double);
    virtual ~SavingsAccount();

    virtual void withdraw(long long);

    virtual void updateMonth();

    virtual std::string toString() const; 
};
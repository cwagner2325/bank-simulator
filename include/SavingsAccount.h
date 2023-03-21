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

    bool mbMonthlyFeeReached;
      
  public:

    SavingsAccount();
    virtual ~SavingsAccount();

    virtual void withdraw(long long);

    virtual void updateMonth();

    virtual std::ostream& print(std::ostream&) const; 

    virtual std::istream& read(std::istream&);
};
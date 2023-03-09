//********************************************************
// File name:  IBankAccount.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the IBankAccount 
//********************************************************

#pragma once
#include <iostream>
#include <string>

class IBankAccount 
{
  private:

    int mAccountNumber;

  protected: 

    double mInterestRate;

    long long mBalance;
      
  public:

    IBankAccount(int, long long, double);
    virtual ~IBankAccount();

    virtual void deposit(long long);
    virtual void withdraw(long long);

    virtual void updateMonth() = 0;

    virtual std::string toString() const; 

    virtual bool equals(int);

    friend std::ostream& operator<<(std::ostream&, const IBankAccount&);
};
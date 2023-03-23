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
#include <memory>
#include "Money.h"
#include "IInterest.h"

class IBankAccount 
{
  private:

    int mAccountNumber;

    std::shared_ptr <IInterest> mpcInterest;

    Money mBalance;

  protected: 

    bool isBelow(const Money&);

    void addInterest();
 
  public:

    IBankAccount();
    virtual ~IBankAccount();

    virtual void deposit(const Money&);
    virtual void withdraw(const Money&);

    virtual void updateMonth() = 0;
    int getAccountNumber() {return mAccountNumber;};
    virtual bool equals(int);

    virtual std::ostream& print(std::ostream&) const; 
    friend std::ostream& operator<<(std::ostream&, const IBankAccount&);

    virtual std::istream& read(std::istream&);
    friend std::istream& operator>>(std::istream&, std::shared_ptr<IBankAccount>);
};
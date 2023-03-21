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

    bool isBelow(Money);

    void addInterest();
 
  public:

    IBankAccount();
    virtual ~IBankAccount();

    virtual void deposit(Money);
    virtual void withdraw(Money);

    virtual void updateMonth() = 0;

    virtual std::ostream& print(std::ostream&) const; 

    int getAccountNumber() {return mAccountNumber;};

    virtual bool equals(int);

    virtual std::istream& read(std::istream&);

    friend std::ostream& operator<<(std::ostream&, const IBankAccount&);
    friend std::istream& operator>>(std::istream&, std::shared_ptr<IBankAccount>);
};
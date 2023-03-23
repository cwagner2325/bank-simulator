//********************************************************
// File name:  FlatInterest.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the FlatInterest 
//********************************************************

#pragma once

#include <memory>
#include <vector>

#include "IInterest.h"
#include "Money.h"

class FlatInterest : public IInterest 
{
  public:
    FlatInterest() {};
    virtual ~FlatInterest() {};

    virtual Money calculateInterest(const Money&);
    
    virtual std::istream& read(std::istream&);
    virtual std::ostream& print(std::ostream&) const; 
  
  private:
    double mInterestRate;
};
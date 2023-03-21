//********************************************************
// File name:  TieredInterest.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the TieredInterest 
//********************************************************

#pragma once

#include <memory>
#include <vector>

#include "IInterest.h"
#include "Money.h"

class TieredInterest : public IInterest 
{
  public:
    TieredInterest() {};
    virtual ~TieredInterest() {};

    virtual Money calculateInterest(const Money&);
    virtual std::istream& read(std::istream&);

    virtual std::ostream& print(std::ostream&) const; 
  
  private:
    std::vector<std::pair<Money, double>> macTiers; 
};
//********************************************************
// File name:  Money.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file Money 
//********************************************************

#pragma once 

#include <iostream>

class Money
{
  private: 
    long long mAmount = 0;

  public:
    Money();
    Money(long long);
    Money(const Money&);

    virtual ~Money() {};

    Money operator+(const Money&);
    long long getInUSD() const;
    // Money operator-(const Money&);
    // Money operator=(const Money&);
    // Money operator>(const Money&);
    // Money operator>=(const Money&);
    friend std::ostream& operator<<(std::ostream&, const Money&);

    // Money operator+(double);

    virtual std::ostream& print(std::ostream&) const;

};
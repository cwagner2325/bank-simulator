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

#include "Currency.h"

class Money
{
  private: 
    long long mAmount = 0;
    Currency mCurrency;

  public:
    Money();
    Money(long long, const Currency&);
    Money(const Money, const Currency);
    Money(const Money&);

    virtual ~Money() {};

    Money operator+(const Money&) const;
    Money operator-(const Money&) const;
    Money operator=(const Money&);
    void operator+=(const Money&);
    void operator-=(const Money&);
    void operator*=(double);
    bool operator>(const Money&) const;
    bool operator>=(const Money&) const;

    Money operator*(double) const;

    friend std::ostream& operator<<(std::ostream&, const Money&);

    friend std::istream& operator>>(std::istream&, Money&);

    Currency getCurrency() const { return mCurrency; };
};
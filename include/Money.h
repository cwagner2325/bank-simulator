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

    Money operator+(const Money&) const;
    Money operator-(const Money&) const;
    Money operator=(const Money&);
    void operator+=(const Money&);
    void operator-=(const Money&);
    void operator*=(double);
    bool operator>(const Money&) const;
    bool operator>=(const Money&) const;

    Money operator*(double) const;

    virtual std::ostream& print(std::ostream&) const;
    friend std::ostream& operator<<(std::ostream&, const Money&);

    virtual std::istream& read(std::istream&);
    friend std::istream& operator>>(std::istream&, Money&);

    long long getInUSD() const;

    

};
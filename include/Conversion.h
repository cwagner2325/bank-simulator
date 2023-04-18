//********************************************************
// File name:  Conversion.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file Conversion 
//********************************************************

#pragma once 

#include <iostream>

#include "Currency.h"

class Conversion
{
  private:
    std::pair<Currency, Currency> mcCurrencies;
    double mConversionRate;

  public:
    Conversion();
    Conversion(Currency, Currency, double);
    ~Conversion();

    friend std::istream& operator>>(std::istream&, Conversion&);
    friend bool operator==(const Conversion&, const Conversion&);
    
    double getConversionRate() const {return mConversionRate;};
};
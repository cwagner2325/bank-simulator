//********************************************************
// File name:  Currency.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file Currency 
//********************************************************

#pragma once

#include <iostream>
#include <string>

class Currency
{
  public:
    Currency();
    Currency(std::string);
    Currency(const Currency&);

    virtual ~Currency();

    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream&, const Currency&);

    void from_str(std::string);
    friend std::istream& operator>>(std::istream&, Currency&);

    friend bool operator==(const Currency&, const Currency&);

    enum class Type 
    {
      USD,
      GBP,
      EUR,
      YEN,
    };
  
  private:
    Currency::Type meType;
};
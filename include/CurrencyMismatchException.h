//********************************************************
// File name:  CurrencyMismatchException.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file CurrencyMismatchException 
//********************************************************

#pragma once 

#include <iostream>
#include <exception>
#include <string>

class CurrencyMismatchException : public std::exception
{
  public:
    CurrencyMismatchException();
    CurrencyMismatchException(std::string);
    CurrencyMismatchException(const CurrencyMismatchException&);

    ~CurrencyMismatchException();

    CurrencyMismatchException operator=(const CurrencyMismatchException&);

    std::string what();

  private:
    std::string mcErrorMessage;
};
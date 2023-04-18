//********************************************************
// File name:  CurrencyMismatchLogger.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file CurrencyMismatchLogger 
//********************************************************

#pragma once 

#include <iostream>
#include <fstream>
#include <string>

class CurrencyMismatchLogger
{
  private: 
    std::ofstream mOutputStream;

    CurrencyMismatchLogger(const CurrencyMismatchLogger&) = delete;
    CurrencyMismatchLogger operator=(const CurrencyMismatchLogger&) = delete;

    CurrencyMismatchLogger();
    ~CurrencyMismatchLogger();

  public:
    static CurrencyMismatchLogger& getInstance();
    void writeToFile(std::string);
};
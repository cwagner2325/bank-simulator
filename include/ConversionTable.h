//********************************************************
// File name:  ConversionTable.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file ConversionTable 
//********************************************************

#pragma once 

#include <iostream>
#include <vector>
#include <string>

#include "Conversion.h"
#include "Money.h"

class ConversionTable
{
  private: 
    std::vector<Conversion> mapcConversions;

    ConversionTable(const ConversionTable&) = delete;
    ConversionTable operator=(const ConversionTable&) = delete;

    ConversionTable() {};
    ~ConversionTable() {};

    inline static ConversionTable* pInstance{nullptr};

  public:
    static ConversionTable* getInstance();
    Money convert(const Money&, const Currency&);
    void readConversionFromFile(std::string);
};
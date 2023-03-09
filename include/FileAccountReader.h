//********************************************************
// File name:  FileAccountReader.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the FileAccountReader 
//********************************************************

#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <fstream>

#include "IAccountReader.h"

class FileAccountReader : public IAccountReader 
{
  private:
    std::ifstream mcFile;

  public:
    FileAccountReader(std::string);
    virtual ~FileAccountReader();

    virtual std::shared_ptr<IBankAccount> readAccount();

};
//********************************************************
// File name:  FileCommandReader.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the FileCommandReader 
//********************************************************

#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

#include "ICommandReader.h"
#include "ICommand.h"
#include "IReceiver.h"

class FileCommandReader : public ICommandReader 
{
  public:
    FileCommandReader(std::string);
    virtual ~FileCommandReader();

    virtual std::shared_ptr<ICommand> readCommand(std::shared_ptr<IReceiver>);
    virtual void readAll(std::shared_ptr<IReceiver>, std::vector<std::shared_ptr<ICommand>>&);

  private: 
    std::ifstream mcInFile;

};
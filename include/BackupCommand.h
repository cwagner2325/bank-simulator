//********************************************************
// File name:  BackupCommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the BackupCommand 
//********************************************************

#pragma once

#include <memory>
#include <string>

#include "ICommand.h"
#include "IReceiver.h"
#include "Money.h"

class BackupCommand : public ICommand
{
  public:
    BackupCommand(std::shared_ptr<IReceiver>, std::string, std::string);
    virtual ~BackupCommand() {};

    virtual void execute();
  
  private:
    std::shared_ptr<IReceiver> mReceiver;
    std::string mCheckingFile;
    std::string mSavingFile;

};
//********************************************************
// File name:  BackupAccountsVisitor.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file BackupAccountsVisitor 
//********************************************************

#pragma once 

#include <iostream>
#include <fstream>
#include <string>

#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "IVisitor.h"

class BackupAccountsVisitor : public IVisitor
{
  public:
    BackupAccountsVisitor(std::string, std::string);
    ~BackupAccountsVisitor();

    void visit(CheckingAccount&);
    void visit(SavingsAccount&);
  
  private:
    std::ofstream mcrCheckingStream;
    std::ofstream mcrSavingStream;
};
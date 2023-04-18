//********************************************************
// File name:  PrintVisitor.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file PrintVisitor 
//********************************************************

#pragma once 

#include <iostream>

#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "IVisitor.h"

class PrintVisitor : public IVisitor
{
  public:
    PrintVisitor() {};
    ~PrintVisitor() {};

    void visit(CheckingAccount&);
    void visit(SavingsAccount&);
};
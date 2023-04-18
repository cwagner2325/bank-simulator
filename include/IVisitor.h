//********************************************************
// File name:  IVisitor.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file IVisitor 
//********************************************************

#pragma once 

#include <iostream>

class CheckingAccount;
class SavingsAccount;

class IVisitor
{
  public:
    virtual ~IVisitor() {};

    virtual void visit(CheckingAccount&) = 0;
    virtual void visit(SavingsAccount&) = 0;
};
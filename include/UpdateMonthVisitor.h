//********************************************************
// File name:  UpdateMonthVisitor.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file UpdateMonthVisitor 
//********************************************************

#pragma once 

#include <iostream>

#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "IVisitor.h"

class UpdateMonthVisitor : public IVisitor
{
  public:
    UpdateMonthVisitor() {};
    ~UpdateMonthVisitor() {};

    void visit(CheckingAccount&);
    void visit(SavingsAccount&);
};
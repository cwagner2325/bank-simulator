//********************************************************
// File name:  ICommand.h
// Author:     Cayden Wagner
// Date:       3/8/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To define the header file the ICommand 
//********************************************************

#pragma once

class ICommand
{
  public:
    virtual ~ICommand() {};

    virtual void execute() = 0;

};
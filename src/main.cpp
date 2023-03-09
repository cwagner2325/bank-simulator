//***************************************************************************
// File name:   main.cpp
// Author:      Cayden Wagner
// Date:        March 8, 2023
// Class:       AOO - CS485
// Assignment:  Bank
// Purpose:     
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include <memory>

#include "Bank.h"
#include "FileAccountReader.h"


//***************************************************************************
// Function:    main
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
int main()
{
  const std::string ACCOUNTS_FILE = "data/Accounts.txt";

  std::shared_ptr<IAccountReader> cReader(new FileAccountReader(ACCOUNTS_FILE));
  Bank* cTheBank(new Bank(cReader));

  cTheBank->printAll();

}

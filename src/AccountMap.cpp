//********************************************************
// File name:  SavingsAccount.cpp
// Author:     Cayden Wagner
// Date:       3/20/2023
// Class:      CS380
// Assignment: Bank
// Purpose:    To implement AccountMap 
//********************************************************

#include <memory>

#include "AccountMap.h"
#include "IBankAccount.h"

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
AccountMap::AccountMap()
{
  mIter = mapcTheMap.begin();
}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
AccountMap::~AccountMap() {}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
std::shared_ptr<IBankAccount> AccountMap::find(int key)
{
  if (mapcTheMap.find(key) != mapcTheMap.end())
  {
    return mapcTheMap.find(key)->second;
  }
  
  return nullptr;
}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void AccountMap::insert(std::shared_ptr<IBankAccount> pcAccount)
{
  mapcTheMap.insert(std::make_pair(pcAccount->getAccountNumber(), pcAccount));
}

//***************************************************************************
// Function:    
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
std::shared_ptr<IBankAccount> AccountMap::getNext()
{
  if (mIter == mapcTheMap.end())
  {
    mIter = mapcTheMap.begin();
    return mIter->second;
  }

  mIter++;

  if (mIter == mapcTheMap.end()) 
  {
    return nullptr;
  }

  return mIter->second;
}
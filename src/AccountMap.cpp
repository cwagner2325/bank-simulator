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
// Constructor:    AccountMap
//
// Description:    sets the iterator to the first element in the map
//
// Parameters:     none
//***************************************************************************
AccountMap::AccountMap()
{
  mIter = mapcTheMap.begin();
}

//***************************************************************************
// Destructor:    AccountMap
//
// Description:   destructor for AccountMap
//
// Parameters:    none
//***************************************************************************
AccountMap::~AccountMap() {}

//***************************************************************************
// Function:    find
//
// Description: finds the element in the map by key
//
// Parameters:  key - the key that is found
//
// Returned:    a shared pointer to the account object is found, else nullptr
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
// Function:    insert
//
// Description: inserts a new key value pair into the map
//
// Parameters:  pcAccount - a pointer to the account that is added
//
// Returned:    none
//***************************************************************************
void AccountMap::insert(std::shared_ptr<IBankAccount> pcAccount)
{
  mapcTheMap.insert(std::make_pair(pcAccount->getAccountNumber(), pcAccount));
}

//***************************************************************************
// Function:    getNext
//
// Description: gets the next element in the map
//
// Parameters:  none
//
// Returned:    a pointer to the next account if it exists, else nullptr
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
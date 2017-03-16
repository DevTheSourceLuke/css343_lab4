/*-------------------------------------------------------------------------------------------------

Authors
Bushey, Luke
King, Garret

Created:		3/13/2017
Modified:		3/13/2017

This is a factory class to create customer objects at runtime.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef customerfactory_h
#define customerfactory_h

#include <iostream>
#include "hashtable.h"
#include "customer.h"

 class CustomerFactory {

public:

	/*------------------------------------------------------------------------------------------------

	Method takes in a file stream and a customer hashtable and populates the table with
	customer objects.

	------------------------------------------------------------------------------------------------*/

	static void createCustomer(ifstream& inFile, HashTable& customers);	//creates new Transaction objects
};

#endif
/*-------------------------------------------------------------------------------------------------
	
	Authors:		Bushey, Luke
					King, Garret
					

	Created:		2/21/2017
	Modified:		3/1/2017

	This is a factory class to create transaction objects at runtime based on the type of
	transaction. Different transaction types have different responsibilities in performing
	actions between inventory and customers.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef transactionfactory_h
#define transactionfactory_h

#include <iostream>
#include <queue>
#include "hashtable.h"
#include "binarysearchtree.h"
#include "transaction.h"
#include "transactioninventory.h"
#include "transactionhistory.h"
#include "transactionborrow.h"
#include "transactionreturn.h"
#include "dvd.h"

class TransactionFactory {

	public:

		/*------------------------------------------------------------------------------------------------

			Method takes in a file stream and a Transaction queue and populates the queue with
			Transaction objects.

		------------------------------------------------------------------------------------------------*/

		static void createTransaction(ifstream& infile, queue<Transaction*>& pending);		//creates new Transaction objects
};

#endif
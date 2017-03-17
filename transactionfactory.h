/*-------------------------------------------------------------------------------------------------
	
	Authors:		
	Boyer, Destiny
	Bushey, Luke
	King, Garret
	Selin, Zach

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

#include "transaction.h"
#include "transactionInventory.h"
#include "transactionHistory.h"
#include "transactionBorrow.h"
#include "transactionReturn.h"
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
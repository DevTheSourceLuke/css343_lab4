/*-------------------------------------------------------------------------------------------------

Authors:		Bushey, Luke
King, Garret

Created:		2/21/2017
Modified:		3/1/2017

This class represents a Transaction affects the store's inventory.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transactioninventory_h
#define transactioninventory_h

#include <string>
#include "transaction.h"

class transactionInventory : public Transaction {

public:

	transactionInventory(void);								//default no-args constructor
	~transactionInventory(void);							//destructor

	bool setData(ifstream& inFile, char type);
	void displayTransaction(void) const;

private:

};


#endif // !transactioninventory_h

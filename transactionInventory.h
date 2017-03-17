/*-------------------------------------------------------------------------------------------------

Authors:		
Bushey, Luke
King, Garret

This class represents a Transaction affects the store's inventory.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef transactioninventory_h
#define transactioninventory_h

#include <string>
#include <vector>
#include "transaction.h"
#include "dvd.h"
#include "DVDClassic.h"
#include "DVDComedy.h"
#include "DVDDrama.h"

class transactionInventory : public Transaction {

public:

	transactionInventory(void);								//default no-args constructor
	~transactionInventory(void);							//destructor

	void processTransaction(HashTable& customers, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC);

	bool setData(ifstream& infile);

	void displayTransaction(void) const;

private:
	vector<BinarySearchTree<DVD>*>* inventory;

};


#endif // !transactioninventory_h

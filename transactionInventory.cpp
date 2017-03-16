#include "stdafx.h"
#include "transactionInventory.h"

transactionInventory::transactionInventory(void)
{
	inventory = NULL;
	setTransactionType('I');
}

transactionInventory::~transactionInventory(void)
{
	inventory = NULL;
}

void transactionInventory::processTransaction(HashTable& customers, vector<BinarySearchTree<DVD>*>& inventory)
{
	cout << "Printing Inventory: " << endl;
	for (int i = 0; i < inventory.size(); i++)
	{
		inventory[i]->display();
	}
}

bool transactionInventory::setData(ifstream & infile)
{
	return true;
}


void transactionInventory::displayTransaction(void) const
{
	cout << getTransactionType() << endl;
}

//#include "stdafx.h"
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

void transactionInventory::processTransaction(HashTable& customers, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC)
{
	cout << endl  << "Printing Inventory: " << endl;
	inventoryC->display();
	inventoryD->display();
	inventoryF->display();
}

bool transactionInventory::setData(ifstream & infile)
{
	return true;
}


void transactionInventory::displayTransaction(void) const
{
	cout << getTransactionType() << endl;
}

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

void transactionInventory::processTransaction()
{

}

bool transactionInventory::setData(ifstream & infile)
{
	return true;
}

void transactionInventory::passInventory(vector<BinarySearchTree<DVD>*>* i)
{
	inventory = i;
}

void transactionInventory::displayTransaction(void) const
{
	cout << getTransactionType() << endl;
}

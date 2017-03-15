#include "stdafx.h"
#include "transactionInventory.h"

transactionInventory::transactionInventory(void)
{
	setTransactionType('I');
}

transactionInventory::~transactionInventory(void)
{
}

bool transactionInventory::setData(ifstream & inFile, char type)
{
	return true;
}

void transactionInventory::displayTransaction(void) const
{
	cout << "Transaction : " << getTransactionType() << endl;
}

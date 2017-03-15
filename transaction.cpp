#include "stdafx.h"
#include "transaction.h"

Transaction::Transaction(void)
{
	setTransactionType('T');
}

Transaction::~Transaction(void)
{
}

void Transaction::processTransaction()
{
}

bool Transaction::setData(ifstream & infile)
{
	return true;
}

void Transaction::displayTransaction(void) const
{ 
	cout << transactionType << endl;
}

void Transaction::passInventory(vector<BinarySearchTree<DVD>*>* i)
{
}

void Transaction::passCustomers(HashTable * c)
{
}

char Transaction::getTransactionType(void) const
{
	return transactionType;
}

bool Transaction::setTransactionType(char input)
{
	if (input != ' ')
	{
		transactionType = input;
		return true;
	}
	else
	{
		cout << "Empty Transaction Type" << endl;
		return false;
	}
}

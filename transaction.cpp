//#include "stdafx.h"
#include "transaction.h"

Transaction::Transaction(void)
{
	setTransactionType('T');
	transactionType = ' ';
}

Transaction::~Transaction(void)
{
}

void Transaction::processTransaction(HashTable& customers, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC)
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
#include "stdafx.h"
#include "transactionHistory.h"

transactionHistory::transactionHistory(void)
{
	customers = NULL;
	setTransactionType('H');
}

transactionHistory::~transactionHistory(void)
{
	customers = NULL;
}

bool transactionHistory::setData(ifstream & infile)
{
	int id;
	infile >> id;
	return setCustomerID(id);
}

void transactionHistory::passCustomers(HashTable * c)
{
	customers = c;
}

void transactionHistory::displayTransaction(void) const
{
	cout << getTransactionType() << " " << getCustomerID() << endl;
}

void transactionHistory::processTransaction(HashTable& customers, vector<BinarySearchTree<DVD>*>& inventory)
{

	cout << "This is a transaction!!!" << endl;
}

int transactionHistory::getCustomerID(void) const
{
	return customerID;
}

bool transactionHistory::setCustomerID(int input)
{
	if (input > 999 && input < 10000)
	{
		customerID = input;
		return true;
	}
	else
	{
		cout << "Invalid ID: " << input << endl;
		return false;
	}
}

string transactionHistory::toString(void) const
{
	string transaction = "H ";
	transaction += customerID;
	return transaction;
}



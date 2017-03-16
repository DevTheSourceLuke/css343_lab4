#include "stdafx.h"
#include "transactionHistory.h"

transactionHistory::transactionHistory(void)
{
	customers = NULL;
	setTransactionType('H');
	customerID = 0;
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

void transactionHistory::displayTransaction(void) const
{
	cout << getTransactionType() << " " << getCustomerID() << endl;
}

void transactionHistory::processTransaction(HashTable& customers, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC)
{

	Customer* temp = NULL;
	temp = customers.getCustomer(getCustomerID());
	if (temp == NULL)
	{
		cout << "No Customer with this id exists: " << getCustomerID() << endl;
		delete temp;
		temp = NULL;
	}
	else
	{
		temp->displayHistory();
		temp = NULL;
	}
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



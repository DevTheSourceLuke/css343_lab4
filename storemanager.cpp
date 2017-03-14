#include "stdafx.h"
#include "storemanager.h"

bool StoreManager::setCustomers(ifstream & infile)
{
	CustomerFactory cf;
	return cf.createCustomer(infile, customers);
}

bool StoreManager::setInventory(ifstream & infile)
{
	DVDFactory df;
	return df.createTransactions(infile, inventory);
}

bool StoreManager::setTransactions(ifstream & infile)
{
	TransactionFactory tf;
	return tf.createTransaction(infile, pending);
}

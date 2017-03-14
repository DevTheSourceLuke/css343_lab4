#include "stdafx.h"
#include "storemanager.h"

StoreManager::StoreManager(void)
{

}

StoreManager::~StoreManager(void)
{

}

void StoreManager::processTransactions()
{
	while (pending.size() != 0)
	{
		pending.front().processTransaction();
		completed.push(pending.front());
		pending.pop();
	}
}

bool StoreManager::setCustomers(ifstream & infile)
{
	return CustomerFactory::createCustomer(infile, customers);
}

bool StoreManager::setInventory(ifstream & infile)
{
	return DVDFactory::createTransactions(infile, inventory);
}

bool StoreManager::setTransactions(ifstream & infile)
{
	return TransactionFactory::createTransaction(infile, pending);
}

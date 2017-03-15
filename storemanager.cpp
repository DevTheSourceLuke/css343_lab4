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
		//pending.front().processTransaction();
		cout << "Perform Transaction!!!" << endl;
		completed.push(pending.front());
		pending.pop();
	}
}

void StoreManager::setCustomers(ifstream & infile)
{
	CustomerFactory::createCustomer(infile, customers);
}

void StoreManager::setInventory(ifstream & infile)
{
	DVDFactory::createDVDs(infile, inventory);
}

void StoreManager::setTransactions(ifstream & infile)
{
	TransactionFactory::createTransaction(infile, pending, customers, inventory);
}

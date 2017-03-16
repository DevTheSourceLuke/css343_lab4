#include "stdafx.h"
#include "storemanager.h"

StoreManager::StoreManager(void)
{

}

StoreManager::~StoreManager(void)
{
	customers.~HashTable();
	while (!pending.empty())
	{
		pending.pop();
	}

	while (!completed.empty())
	{
		completed.pop();
	}

	inventoryF->clear();
	inventoryC->clear();
	inventoryD->clear();
}

void StoreManager::processTransactions()
{
	cout << endl << "Processing Transactions..." << endl;
	while (pending.size() != 0)
	{
	    pending.front()->processTransaction(customers, inventoryF, inventoryD, inventoryC);
		completed.push(pending.front());
		pending.pop();
	}
}

void StoreManager::setCustomers(ifstream & infile)
{
	cout << endl << "Creating Customers..." << endl;
	CustomerFactory::createCustomer(infile, customers);
}

void StoreManager::setInventory(ifstream & infile)
{
	cout << endl << "Creating Inventory..." << endl;
	inventoryF = new BinarySearchTree<Comedy>();
	inventoryD = new BinarySearchTree<Drama>();
	inventoryC = new BinarySearchTree<Classic>();
	DVDFactory::createDVDs(infile, inventoryF, inventoryD, inventoryC);
}

void StoreManager::setTransactions(ifstream & infile)
{
	cout << endl << "Creating Transactions..." << endl;
	TransactionFactory::createTransaction(infile, pending);
}

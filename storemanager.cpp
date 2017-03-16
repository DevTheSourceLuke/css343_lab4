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

	for (int i = 0; i < inventory.size(); i++)
	{
		inventory[i]->~BinarySearchTree();
		delete inventory[i];
		inventory[i] = NULL;
	}
	inventory.clear();
}

void StoreManager::processTransactions()
{
	cout << endl << "Processing Transactions..." << endl;
	while (pending.size() != 0)
	{
	    pending.front()->processTransaction(customers, inventory);
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
	inventory.resize(3);
	inventory[0] = new BinarySearchTree<DVD>();
	inventory[1] = new BinarySearchTree<DVD>();
	inventory[2] = new BinarySearchTree<DVD>();
	DVDFactory::createDVDs(infile, inventory);
}

void StoreManager::setTransactions(ifstream & infile)
{
	cout << endl << "Creating Transactions..." << endl;
	TransactionFactory::createTransaction(infile, pending);
}

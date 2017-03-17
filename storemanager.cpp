//#include "stdafx.h"
#include "storemanager.h"

StoreManager::StoreManager(void)
{

}

StoreManager::~StoreManager(void)
{
	customers.~HashTable();
	Transaction * temp = NULL;
	while (!pending.empty())
	{
		temp = pending.front();
		pending.pop();
		delete temp;
		temp = NULL;
	}

	while (!completed.empty())
	{
		temp = completed.front();
		completed.pop();
		delete temp;
		temp = NULL;
	}


	inventoryF->clear();
	inventoryC->clear();
	inventoryD->clear();
	delete inventoryC;
	delete inventoryD;
	delete inventoryF;
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
/*-------------------------------------------------------------------------------------------------

Authors:
			Bushey, Luke
			King, Garret

Created:		3/13/2017
Modified:		3/13/2017

-------------------------------------------------------------------------------------------------*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "storemanager.h"


using namespace std;

int main() {

	ifstream infileCust("data4customers.txt");
	if (!infileCust) {
		cout << "Customer file could not be opened." << endl;
		return 1;
	}

	ifstream infileMov("data4movies.txt");
	if (!infileMov) {
		cout << "Inventory file could not be opened." << endl;
		return 1;
	}
	
	ifstream infileCom("data4commands.txt");
	if (!infileCom) {
		cout << "Transaction file could not be opened." << endl;
		return 1;
	}

	StoreManager Store;

	Store.setCustomers(infileCust);
	Store.setInventory(infileMov);
	Store.setTransactions(infileCom);

	Store.processTransactions();
	
	return 0;
}


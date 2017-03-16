/*-------------------------------------------------------------------------------------------------

	Authors:		Bushey, Luke
					King, Garret

	Created:		2/21/2017
	Modified:		3/1/2017

	HashTable class that has the functionality to populate a HashTable, retrieve items,
	and insert items.

	NOTES:	All responsibility for handling a filestream to populate an Object's data members
			is the responsibility of the Object.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef hashtable_h
#define hashtable_h

//#include "stdafx.h"
#include <iostream>
#include "customer.h"

using namespace std;


class HashTable {
	static const int tableSize = 100;
	static const int tableHash = 101;

public:
	
	HashTable(void);					// default no-args constructor
	~HashTable(void);					// destructor

	Customer* getCustomer(int);					// method uses customer id and returns a pointer to that customer obj.
	bool insertCustomer(Customer* );		// method to populate customer into hash table.

private:
	void createTable();						    // method for constructor to create table
	void emptyTable();							// method for destructor to clear table	

	struct hashItems
	{
		Customer* custRecord;
		hashItems* next;
	};

	struct hashStore
	{
		hashItems* head;
	};

	hashStore table[tableSize];

};


#endif // !hashtable_h
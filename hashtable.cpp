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

#pragma once
#include "hashtable.h"

// Constructor and destructor for hash table
HashTable::HashTable(void)
{
	createTable();
}

HashTable::~HashTable(void)
{
	emptyTable();
}


void HashTable::createTable(void)
{
	for (int i = 0; i < tableSize; i++)
	{
		table[i].head = NULL;
	}
}

void HashTable::emptyTable(void)
{
	// loop through hashstore
	for (int i = 0; i < tableSize; i++)
	{
		if (table[i].head != NULL)
		{
			// next iterate through list deleting data and node.
			hashItems* current = table[i].head;
			while (table[i].head != NULL)
			{
				table[i].head = table[i].head->next;
				if (current->custRecord != NULL) {						// test if node's object is null
					delete current->custRecord;           				// delete the node object
					current->custRecord = NULL;
				}
				delete current;											// then delete node
				current = NULL;
				current = table[i].head;	  
			}
		
		}
	}
}

bool HashTable::insertCustomer(Customer* custToInsert)
{
	// retrieve CustID
	int custKey = custToInsert->getID;
	
	// create hashKey
	int hashKey = (custKey % tableHash);

	// create hash node to insert
	hashItems* newCust = new hashItems;
	newCust->custRecord = custToInsert;
	newCust->next = NULL;
	
	if (table[hashKey].head == NULL)
	{
		//newCust->next = 
	}


}

Customer * HashTable::getCustomer(int custID)
{

}



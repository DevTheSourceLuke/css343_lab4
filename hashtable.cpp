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
#include "stdafx.h"
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
	int custID = custToInsert->getID();
	
	// create hashKey
	int hashKey = (custID % tableHash);

	// create hash node to insert
	hashItems* newCust = new hashItems;
	newCust->custRecord = custToInsert;
	newCust->next = NULL;
	
	// test if any nodes exist at hashKey 
	if (table[hashKey].head == NULL)
	{
		// not then set start of list
		table[hashKey].head = newCust;
	}
	else {
		// list exists, traverse to end and insert customer
		hashItems* current = table[hashKey].head;

		// iterate through list
		while (current->next != NULL)
		{
			if (custID == current->custRecord->getID())
			{
				cout << "Duplicate Customer ID already exists: " << custID <<  endl;
				// if we have mem leaks then look to delete cust record here
				//delete newCust->custRecord;
				newCust->custRecord = NULL;
				delete newCust;
				newCust = NULL;
				return false;
			}
			// iterate through list
			current = current->next;
		}
		// finally set the next to point to the new node
		current->next = newCust;
	}
	return true;
}

Customer* HashTable::getCustomer(int custID)
{
	if (custID <= 999 || custID >= 10000)
	{
		return NULL;
	}

	// create hashKey
	int hashKey = (custID % tableHash);

	if (table[hashKey].head == NULL) 
	{
		return NULL;
	}
	else {
		hashItems* current = table[hashKey].head;

		while (current != NULL) 
		{
			if (custID == current->custRecord->getID()) 
			{
				return current->custRecord;
			}
			current = current->next;
		}
	}
	return NULL;
}
/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	Created:		2/21/2017
	Modified:		3/1/2017

	This class represents a Transction object. Each object stores information about the Transaction
	type and Customer ID associated with the Transaction. This class has the functionality to take
	in a data stream with the method setData() in order to populate its data members.
	The method displayTransaction() will neatly print a Transaction object's information to the
	console.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transaction_h
#define transaction_h

#include <fstream>
#include <iostream>
#include <string>
#include "hashtable.h"
#include "binarysearchtree.h"
#include "DVDClassic.h"
#include "DVDComedy.h"
#include "DVDDrama.h"

using namespace std;

class Transaction {

public:
	
	Transaction(void);							//default no-args constructor
	virtual ~Transaction(void);					//destructor
	
	/*------------------------------------------------------------------------------------------------

		Method takes in a file stream and a char indicating the type of Transaction. Method populates
		a Transaction object's data members by calling setters as helper methods for error checking.
		If any of the setters returns false then setData() will return false and the object should
		be deleted.

	------------------------------------------------------------------------------------------------*/

	virtual bool setData(ifstream& infile);

	virtual void processTransaction(HashTable& customers, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC);

	/*------------------------------------------------------------------------------------------------

		Method neatly prints all of a Transaction object's information to the console.

		NOTES:	Method cannot change any data members.

	------------------------------------------------------------------------------------------------*/

	virtual void displayTransaction(void) const;	

	//getters
	char getTransactionType(void) const;

	/*------------------------------------------------------------------------------------------------

		Setter method for transactionType. Returns a bool indicating success.

		PRECONDITIONS:
			- input cannot be a empty

		POSTCONDITIONS:
			- sets transactionType to input

	------------------------------------------------------------------------------------------------*/

	bool setTransactionType(char input);

private:
	
	char transactionType;
	
};

#endif // !transaction_h
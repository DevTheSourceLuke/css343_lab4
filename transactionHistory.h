/*-------------------------------------------------------------------------------------------------

Authors:		Bushey, Luke
King, Garret

Created:		2/21/2017
Modified:		3/1/2017

This class represents a Transaction affects the store's customer's history.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transactionhistory_h
#define transactionhistory_h

#include <string>
#include <fstream>
#include "transaction.h"
#include "hashtable.h"

class transactionHistory: public Transaction {

public:

	transactionHistory(void);							//default no-args constructor
	~transactionHistory(void);							//destructor

	bool setData(ifstream& infile);
	void passCustomers(HashTable* c);
	void displayTransaction(void) const;

	//getters
	int getCustomerID(void) const;

	/*------------------------------------------------------------------------------------------------

	Setter method for customerID. Returns a bool indicating success.

	PRECONDITIONS:
	- input must be greater than 999
	- input must be less than 10000

	POSTCONDITIONS:
	- sets customerID to input

	------------------------------------------------------------------------------------------------*/

	bool setCustomerID(int input);

private:
	int customerID = 0;
	HashTable* customers;

};


#endif // !transactionhistory_h

/*-------------------------------------------------------------------------------------------------

Authors:		
Bushey, Luke
King, Garret


This class represents a Transaction affects the store's customer's Borrow.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef transactionborrow_h
#define transactionborrow_h

#include <string>
#include <fstream>
#include <vector>
#include "dvd.h"
#include "DVDClassic.h"
#include "DVDComedy.h"
#include "DVDDrama.h"
#include "transaction.h"

class transactionBorrow : public Transaction {

public:

	transactionBorrow(void);							//default no-args constructor
	~transactionBorrow(void);							//destructor

	bool setData(ifstream& infile);
	void displayTransaction(void) const;
	void processTransaction(HashTable& customers, BinarySearchTree<Comedy>* inventoryF, BinarySearchTree<Drama>* inventoryD, BinarySearchTree<Classic>* inventoryC);

	//getters
	int getMonth(void) const;
	int getYear(void) const;
	int getCustomerID(void) const;
	char getMediaType(void) const;
	char getGenre(void) const;
	string getDirector(void) const;
	string getTitle(void) const;
	string getActor(void) const;

	/*------------------------------------------------------------------------------------------------

	Setter method for customerID. Returns a bool indicating success.

	PRECONDITIONS:
	- input must be greater than 999
	- input must be less than 10000

	POSTCONDITIONS:
	- sets customerID to input

	------------------------------------------------------------------------------------------------*/

	bool setCustomerID(int input);

	/*------------------------------------------------------------------------------------------------

	Setter method for mediaType. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be an empty character

	POSTCONDITIONS:
	- sets mediaType to input

	------------------------------------------------------------------------------------------------*/

	bool setMediaType(char input);

	/*------------------------------------------------------------------------------------------------

	Setter method for genre. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be an empty character

	POSTCONDITIONS:
	- sets genre to input

	------------------------------------------------------------------------------------------------*/

	bool setGenre(char input);

	/*------------------------------------------------------------------------------------------------

	Setter method for director. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be an empty string

	POSTCONDITIONS:
	- sets director to input

	------------------------------------------------------------------------------------------------*/

	bool setDirector(string input);

	/*------------------------------------------------------------------------------------------------

	Setter method for title. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be an empty string

	POSTCONDITIONS:
	- sets title to input

	------------------------------------------------------------------------------------------------*/

	bool setTitle(string input);

	/*------------------------------------------------------------------------------------------------

	Setter method for actor. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be an empty string

	POSTCONDITIONS:
	- sets actor to input

	------------------------------------------------------------------------------------------------*/

	bool setActor(string input);

	/*------------------------------------------------------------------------------------------------

	Setter method for year. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot greater than the current year plus one or less than 1927 (first tv made).

	POSTCONDITIONS:
	- sets year to input

	------------------------------------------------------------------------------------------------*/

	bool setYear(int input);

	/*------------------------------------------------------------------------------------------------

	Setter method for year and month. Returns a bool indicating success.

	PRECONDITIONS:
	- inputY cannot greater than the current year plus one or less than 1927( first tv made).
	- inputM cannot be greater than 12 or less than 0.

	POSTCONDITIONS:
	- sets year to input

	------------------------------------------------------------------------------------------------*/

	bool setDate(int inputY, int inputM);

	/*------------------------------------------------------------------------------------------------

	Returns the transaction values as a string.

	------------------------------------------------------------------------------------------------*/

	string toString(void) const;


private:
	int customerID;
	int year;
	int month;
	char mediaType;
	char genre ;
	string director;
	string title;
	string actor;
	vector<BinarySearchTree<DVD>*>* inventory;
	HashTable* customers;
};


#endif // !transactionborrow_h

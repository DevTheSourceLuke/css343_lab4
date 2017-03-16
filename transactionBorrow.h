/*-------------------------------------------------------------------------------------------------

Authors:		Bushey, Luke
King, Garret

Created:		2/21/2017
Modified:		3/1/2017

This class represents a Transaction affects the store's customer's Borrow.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transactionborrow_h
#define transactionborrow_h

#include <string>
#include <fstream>
#include <vector>
#include "dvd.h"
#include "transaction.h"

class transactionBorrow : public Transaction {

public:

	transactionBorrow(void);							//default no-args constructor
	~transactionBorrow(void);							//destructor

	bool setData(ifstream& infile);
	void passStructures(HashTable* c, vector<BinarySearchTree<DVD>*>* i);
	void displayTransaction(void) const;
	void processTransaction(HashTable& customers, vector<BinarySearchTree<DVD>*>& inventory);

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

	bool setYear(int input);

	bool setDate(int inputY, int inputM);


private:
	int customerID = 0;
	int year = 0;
	int month = 0;
	char mediaType = '_';
	char genre = '_';
	string director = "";
	string title = "";
	string actor = "";
	vector<BinarySearchTree<DVD>*>* inventory;
	HashTable* customers;
};


#endif // !transactionborrow_h

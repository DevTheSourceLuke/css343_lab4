/*-------------------------------------------------------------------------------------------------

Authors:		Bushey, Luke
King, Garret

Created:		2/21/2017
Modified:		3/1/2017

This class represents a Transaction affects the store's customer's Return.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef transactionreturn_h
#define transactionreturn_h

#include <string>
#include <vector>
#include "dvd.h"
#include "DVDClassic.h"
#include "DVDComedy.h"
#include "DVDDrama.h"
#include "transaction.h"


class transactionReturn : public Transaction {

public:

	transactionReturn(void);							//default no-args constructor
	~transactionReturn(void);							//destructor

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
	string toString(void) const;


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
	- input must be a D for the only available media type

	POSTCONDITIONS:
	- sets mediaType to input

	------------------------------------------------------------------------------------------------*/

	bool setMediaType(char input);

	/*------------------------------------------------------------------------------------------------

	Setter method for genre. Returns a bool indicating success.

	PRECONDITIONS:
	- input must be a F, D, or C

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
	int customerID;
	int year;
	int month;
	char mediaType;
	char genre;
	string director;
	string title;
	string actor;
	vector<BinarySearchTree<DVD>*>* inventory;
	HashTable* customers;

};


#endif // !transactionreturn_h

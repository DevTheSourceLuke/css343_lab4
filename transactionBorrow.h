/*-------------------------------------------------------------------------------------------------

Authors:		Bushey, Luke
King, Garret

Created:		2/21/2017
Modified:		3/1/2017

This class represents a Transction affects the store's customer's Borrow.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transactionborrow_h
#define transactionborrow_h

#include <string>
#include "transaction.h"

class transactionBorrow : public Transaction {

public:

	transactionBorrow(void);								//default no-args constructor
	transactionBorrow(transactionBorrow& toCopy);		//copy constructo
	~transactionBorrow(void);							//destructor

	bool setData(ifstream& inFile, char type);
	void displayTransaction(void) const;

	//getters
	char getMediaType(void) const;
	char getGenre(void) const;
	string getDirector(void) const;
	string getTitle(void) const;
	string getFirstName(void) const;
	string getLastName(void) const;

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

	Setter method for actorLastName. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be an empty string

	POSTCONDITIONS:
	- sets actorLastName to input

	------------------------------------------------------------------------------------------------*/

	bool setLastName(string input);

	/*------------------------------------------------------------------------------------------------

	Setter method for actorFirstName. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be an empty string

	POSTCONDITIONS:
	- sets actorFirstName to input

	------------------------------------------------------------------------------------------------*/

	bool setFirstName(string input);

	transactionBorrow& operator=(const transactionBorrow& toCopy);

private:


};


#endif // !transactionborrow_h

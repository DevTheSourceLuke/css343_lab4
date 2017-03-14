/*-------------------------------------------------------------------------------------------------

Authors:		Bushey, Luke
King, Garret

Created:		2/21/2017
Modified:		3/1/2017

This class represents a Transction affects the store's customer's history.

-------------------------------------------------------------------------------------------------*/

#pragma once
#ifndef transactionhistory_h
#define transactionhistory_h

#include <string>
#include "transaction.h"

class transactionHistory: public Transaction {

public:

	transactionHistory(void);								//default no-args constructor
	transactionHistory(transactionHistory& toCopy);		//copy constructo
	~transactionHistory(void);							//destructor

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

	transactionHistory& operator=(const transactionHistory& toCopy);

private:


};


#endif // !transactionhistory_h

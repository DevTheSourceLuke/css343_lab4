/*-------------------------------------------------------------------------------------------------

Authors:		
Boyer, Destiny
Bushey, Luke
King, Garret
Selin, Zach

DVD child class to represent DVD's of type Classic. Classic DVD objects are a special
case and require uniquely overloaded comparison operators for insertion into the
inventory management data structure and for populating data members.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef classic_h
#define classic_h

#include <fstream>
#include "dvd.h"

class Classic : public DVD {

public:

	Classic(void);				//default no-args constructor
	~Classic(void);				//destructor

	bool setData(ifstream& infile);
	void display(void) const;
	string getActor(void) const;
	int getMonth(void) const;
	Classic* getOtherStock(Classic* dupe);

	bool operator==(const DVD& toCompare) const;
	bool operator!=(const DVD& toCompare) const;
	bool operator<(const DVD& toCompare) const;
	bool operator>(const DVD& toCompare) const;



	/*------------------------------------------------------------------------------------------------

	Setter method for releaseYear. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be an empty string

	POSTCONDITIONS:
	- sets actor equal to input

	------------------------------------------------------------------------------------------------*/

	bool setActor(string input);

	/*------------------------------------------------------------------------------------------------

	Setter method for releaseMonth. Returns a bool indicating success.

	PRECONDITIONS:
	- input cannot be less than 0 and greater than 12

	POSTCONDITIONS:
	- sets releaseMonth equal to the input

	------------------------------------------------------------------------------------------------*/

	bool setMonth(int input);

	/*------------------------------------------------------------------------------------------------

	Setter method for otherStock. Returns a bool indicating success. otherStock holds a pointer to 
	the same movie defined by a different actor.

	PRECONDITIONS:
	- input cannot be NULL

	POSTCONDITIONS:
	- sets otherStock equal to the input

	------------------------------------------------------------------------------------------------*/

	bool setOtherStock(Classic* dupe);

	Classic* getOtherStock(void);


private:

	string majorActor;
	int releaseMonth;
	Classic* otherStock;

};

#endif // !classic_h

/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	DVD child class to represent DVD's of type Drama.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef drama_h
#define drama_h

#include "dvd.h"
#include <fstream>

class Drama : public DVD {

	public:

	Drama(void);				//default no-args constructor
	~Drama(void);				//destructor

	bool setData(ifstream& infile);
	virtual void display(void) const;


	//overloaded comparison operators
	bool operator==(const DVD& toCompare) const;
	bool operator!=(const DVD& toCompare) const;
	bool operator<(const DVD& toCompare) const;
	bool operator>(const DVD& toCompare) const;

};

#endif // !drama_h

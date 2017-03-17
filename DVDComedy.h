/*-------------------------------------------------------------------------------------------------

	Authors:		Boyer, Destiny
					Bushey, Luke
					King, Garret
					Selin, Zach

	DVD child class to represent DVD's of type Comedy.

-------------------------------------------------------------------------------------------------*/

//#pragma once
#ifndef comedy_h
#define comedy_h

#include "dvd.h"
#include <fstream>

class Comedy : public DVD {

	public:

	Comedy(void);				//default no-args constructor
	~Comedy(void);				//destructor

	bool setData(ifstream& infile);
	virtual void display(void) const;

	//overloaded comparison operators
	bool operator==(const DVD& toCompare) const;
	bool operator!=(const DVD& toCompare) const;
	bool operator<(const DVD& toCompare) const;
	bool operator>(const DVD& toCompare) const;

};

#endif // !comedy_h

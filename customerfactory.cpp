#include "stdafx.h"
#include <iostream>
#include "customerfactory.h"

bool CustomerFactory::createCustomer(ifstream & infile, HashTable& customers)
{
	Customer* temp = NULL;
	while (!infile.eof())
	{
		temp = new Customer();
		if (temp->setData(infile))
		{
			customers.insert(temp);
			temp = NULL;
		}
		else
		{
			delete temp;
			temp = NULL;
		}
	}
	return false;
}
